/*  Init
 *
 *  This routine is the initialization task for this test program.
 *
 *  Don't forget to change the IP addresses
 */

#define CONFIGURE_APPLICATION_NEEDS_CONSOLE_DRIVER
#define CONFIGURE_APPLICATION_NEEDS_CLOCK_DRIVER
#define CONFIGURE_RTEMS_INIT_TASKS_TABLE
#define CONFIGURE_LIBIO_MAXIMUM_FILE_DESCRIPTORS	20
#define CONFIGURE_USE_IMFS_AS_BASE_FILESYSTEM

#define CONFIGURE_EXECUTIVE_RAM_SIZE	(512*1024)
#define CONFIGURE_MAXIMUM_SEMAPHORES	20
#define CONFIGURE_MAXIMUM_TASKS		20

#define CONFIGURE_MICROSECONDS_PER_TICK	10000

#define CONFIGURE_INIT_TASK_STACK_SIZE	(10*1024)
#define CONFIGURE_INIT_TASK_PRIORITY	120
#define CONFIGURE_INIT_TASK_INITIAL_MODES (RTEMS_PREEMPT | \
                                           RTEMS_NO_TIMESLICE | \
                                           RTEMS_NO_ASR | \
                                           RTEMS_INTERRUPT_LEVEL(0))

#define STACK_CHECKER_ON
#define CONFIGURE_INIT

#include "system.h"
#include <bsp.h>

#include <errno.h>
#include <time.h>

#include <rtems/confdefs.h>
#include <stdio.h>
#include <rtems/rtems_bsdnet.h>
#include <rtems/ftpd.h>
#include <rtems/untar.h>

     
#include <rtems/error.h>
#include <rpc/rpc.h>
#include <netinet/in.h>
#include <time.h>

#include <arpa/inet.h>
#include <sys/socket.h>
#include "../networkconfig.h"

#include <rtems_webserver.h>

#define ARGUMENT 0

/*
 *  The tarfile image is built automatically externally.
 */
#include "FilesystemImage.h"

#if defined(USE_FTPD)
  boolean FTPD_enabled = TRUE;
  struct rtems_ftpd_configuration rtems_ftpd_configuration = {
    10,                     /* FTPD task priority            */
    1024,                   /* Maximum buffersize for hooks  */
    21,                     /* Well-known port     */
    NULL                    /* List of hooks       */
 };
#else
 boolean FTPD_enabled = FALSE;
#endif

#if defined(USE_GOAHEAD_HTTPD)
  boolean GoAhead_HTTPD_enabled = TRUE;

  /* GoAhead Trace Handler */
  #include <goahead/uemf.h>
  void quietTraceHandler(int level, char *buf)
  {
    /* do nothing */
  }
#else
  boolean GoAhead_HTTPD_enabled = FALSE;
#endif

#if defined(USE_SIMPLE_HTTPD)
  boolean Simple_HTTPD_enabled = TRUE;

  #include <shttpd/shttpd.h>
#else
  boolean Simple_HTTPD_enabled = FALSE;
#endif

#define bool2string(_b) ((_b) ? "true" : "false")

#if defined(USE_SIMPLE_HTTPD)
extern void example_shttpd_addpages(struct shttpd_ctx *ctx);
#endif

rtems_task Init(
  rtems_task_argument argument
)
{
  rtems_status_code status;

  printf("\n\n*** HTTP TEST ***\n\r" );
  printf("GoAhead HTTPD Enabled: %s\n", bool2string(GoAhead_HTTPD_enabled) );
  printf("Simple HTTPD Enabled: %s\n", bool2string(Simple_HTTPD_enabled) );
  printf("FTPD Enabled: %s\n", bool2string(FTPD_enabled) );
  printf("\n");

  /*
   * Load filesystem image
   */
  printf("Loading filesystem image\n");
  status = Untar_FromMemory( (char *)FilesystemImage, FilesystemImage_size );
   
  printf("Initializing Network\n");
  rtems_bsdnet_initialize_network ();

  #if defined(USE_FTPD)
    printf( "Initializing FTPD\n" );
    rtems_initialize_ftpd();
  #endif

  #if defined(USE_GOAHEAD_HTTPD)
    printf( "Initializing GoAhead HTTPD\n" );
    status = rtems_initialize_webserver();
    if ( status )
      printf( "ERROR -- failed to initialize webserver\n" );

    traceSetHandler( quietTraceHandler );
  #endif

  #if defined(USE_SIMPLE_HTTPD)
    /*
     *  SHTTPD uses about 37K of stack even in this test on a PowerPC.
     *  There is no point in doing math for the stack size.  Bump it
     *  until there isn't a problem.
     */
    printf( "Initializing Simple HTTPD\n" );
    status = rtems_initialize_webserver(
      100,                             /* initial priority */
      (48 * 1024),                     /* stack size */
      RTEMS_DEFAULT_MODES,             /* initial modes */
      RTEMS_DEFAULT_ATTRIBUTES,        /* attributes */
      NULL,                            /* init_callback */
      example_shttpd_addpages,         /* addpages_callback */
      "/",                             /* initial priority */
      80                               /* port to listen on */
    );
    if ( status )
      printf( "ERROR -- failed to initialize webserver\n" );

  #endif

  status = rtems_task_delete( RTEMS_SELF );
}




