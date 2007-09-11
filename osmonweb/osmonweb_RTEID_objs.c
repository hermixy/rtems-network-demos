/*
 * file: osmonweb_RTEID_objs.c
 * Do not edit here!
 */
 #include "osmonweb_RTEID_objs.h"
   const char osmonweb_RTEID_objs_title[] =
      "\n"
      "<head>\n"
      "<!-- start of document title here -->\n"
      "   <title>RTEMS Classic (RTEID) API Objects on <!-"
      "-%printstr %s|4 --></title>\n"
      "<!-- end of document title -->\n"
      "</head>\n"
      "<body>\n"
   ;

   const char osmonweb_RTEID_objs_header[] =
      "\n"
      "<table border=\"0\" cellspacing=\"0\" cellpadding="
      "\"5\" width=\"100%\">\n"
      "   <tr><td><div align=\"center\">\n"
      "      <h2>RTEMS Classic (RTEID) API Objects On Tar"
      "get <b><font color=\"#4040ff\"><!--%printstr %s|4 "
      "--></font></b></h2>\n"
      "   </div></td></tr>\n"
      "   <tr><td>\n"
      "   <div align=\"center\">\n"
      "   <!-- start of API selection bar -->\n"
      "   <table border=\"0\" cellspacing=\"0\" width=\"1"
      "00%\">\n"
      "      <tr valign=\"center\">\n"
      "      <td width=\"20\">&nbsp;</td>\n"
      "      <td bgcolor=\"#4040ff\" align=\"center\" wid"
      "th=\"200\">\n"
      "         <a href=\"/goforms/osmonweb?api=RTEID\" n"
      "ame=\"RTEID objects\">\n"
      "         <font color=#ffffff size=\"+1\"><b>Classi"
      "c (RTEID) API</b></font>\n"
      "         </a>\n"
      "      </td>\n"
      "      <td width=\"20\">&nbsp;</td>\n"
      "      <td bgcolor=\"#E0E0E0\" align=\"center\" wid"
      "th=\"200\">\n"
      "         <a href=\"/goforms/osmonweb?api=POSIX\" n"
      "ame=\"POSIX objects\">\n"
      "         <font color=\"Black\" size=\"+1\">POSIX A"
      "PI</font>\n"
      "         </a>\n"
      "      </td>\n"
      "      <td width=\"20\">&nbsp;</td>\n"
      "      <td bgcolor=\"#E0E0E0\" align=\"center\" wid"
      "th=\"200\">\n"
      "         <a href=\"/goforms/osmonweb?api=ITRON\" n"
      "ame=\"ITRON objects\">\n"
      "         <font color=\"Black\" size=\"+1\">ITRON A"
      "PI</font>\n"
      "         </a>\n"
      "      </td>\n"
      "      <td width=\"20\">&nbsp;</td>\n"
      "      </tr>\n"
      "      <tr><td colspan=10 bgcolor=\"#4040ff\"><img "
      "width=1 height=1 alt=\"\"></td></tr>\n"
      "   </table>\n"
      "   <!-- end of API selection bar -->\n"
      "\n"
      "   <!-- start of Object selection bar -->\n"
      "   <table border=\"0\"  cellspacing=\"0\" width=\""
      "80%\">\n"
      "      <tr>\n"
      "         <td width=\"20\">&nbsp;</td>\n"
      "         <td bgcolor=\"#8080E0\" align=\"center\" "
      "width=\"200\">\n"
      "            <a href=\"/goforms/osmonweb?api=RTEID&"
      "obj_type=task\" name=\"RTEID tasks\">\n"
      "            <font color=Black>Tasks</font>\n"
      "            </a></td>\n"
      "         <td width=\"20\">&nbsp;</td>\n"
      "         <td bgcolor=\"#8080E0\" align=\"center\" "
      "width=\"200\">\n"
      "            <a href=\"/goforms/osmonweb?api=RTEID&"
      "obj_type=sema\" name=\"RTEID semaphores\">\n"
      "            <font color=\"Black\">Semaphores</font"
      ">\n"
      "            </a></td>\n"
      "         <td width=\"20\">&nbsp;</td>\n"
      "         <td bgcolor=\"#8080E0\" align=\"center\" "
      "width=\"200\">\n"
      "            <a href=\"/goforms/osmonweb?api=RTEID&"
      "obj_type=queue\" name=\"RTEID Message Queues\">\n"
      "            <font color=\"Black\">Message Queues</"
      "font>\n"
      "            </a></td>\n"
      "         <td width=\"20\">&nbsp;</td>\n"
      "         <td bgcolor=\"#8080E0\" align=\"center\" "
      "width=\"200\">\n"
      "            <a href=\"/goforms/osmonweb?api=RTEID&"
      "obj_type=rmon\" name=\"RTEID Rate Monotonic Timers"
      "\">\n"
      "            <font color=\"Black\">Rate Monotonic T"
      "imers</font>\n"
      "            </a></td>\n"
      "         <td width=\"20\">&nbsp;</td>\n"
      "         <td bgcolor=\"#8080E0\" align=\"center\" "
      "width=\"200\">\n"
      "            <a href=\"/goforms/osmonweb?api=RTEID&"
      "obj_type=part\" name=\"RTEID Partitions\">\n"
      "            <font color=\"Black\">Partitions</font"
      ">\n"
      "            </a></td>\n"
      "         <td width=\"20\">&nbsp;</td>\n"
      "         <td bgcolor=\"#8080E0\" align=\"center\" "
      "width=\"200\">\n"
      "            <a href=\"/goforms/osmonweb?api=RTEID&"
      "obj_type=region\" name=\"RTEID Regions\">\n"
      "            <font color=\"Black\">Regions</font>\n"
      "            </a></td>\n"
      "         <td width=\"20\">&nbsp;</td>\n"
      "      </tr>\n"
      "   </table>\n"
      "<!-- end of Object selection bar -->\n"
      "   </div>\n"
   ;

   const char osmonweb_RTEID_objs_footer[] =
      "\n"
      "    <br><br><hr><br><br>\n"
      "    <div align=\"center\"><table cellspacing=\"5\""
      " cellpadding=\"15\"><tr>\n"
      "      <td><IMG src=\"/osmonweb/EmpoweredByRTEMSEgg"
      "Logo.gif\" alt=\"Empowered by RTEMS\" width=90 hei"
      "ght=53 border=0></td>\n"
      "      <td><IMG src=\"/osmonweb/<!--%printhttpd_log"
      "o-->\" width=120 border=0></td>\n"
      "      <td><IMG src=\"/osmonweb/imdlogo.jpg\" width"
      "=123 height=61 border=0></td>\n"
      "    </tr><tr>\n"
      "      <td align=\"center\"><b>Empowered by <br>RTE"
      "MS</b></td>\n"
      "      <td align=\"center\"><b>transported by <br><"
      "!--%printhttpd_name--></b></td>\n"
      "      <td align=\"center\"><b>implemented by <br>I"
      "MD Th. D�rfler</b></td>\n"
      "    </tr></table></div>\n"
      "    </td></tr>\n"
      "</table>\n"
   ;

   const char osmonweb_RTEID_objs_trailer[] =
      "\n"
      "</body>\n"
   ;

