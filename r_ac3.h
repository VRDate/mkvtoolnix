/*
  mkvmerge -- utility for splicing together matroska files
      from component media subtypes

  r_avi.h

  Written by Moritz Bunkus <moritz@bunkus.org>

  Distributed under the GPL
  see the file COPYING for details
  or visit http://www.gnu.org/copyleft/gpl.html
*/

/*!
    \file r_avi.h
    \version \$Id: r_ac3.h,v 1.7 2003/04/13 15:23:03 mosu Exp $
    \brief class definitions for the AVI demultiplexer module
    \author Moritz Bunkus         <moritz @ bunkus.org>
*/

#ifndef __R_AC3_H
#define __R_AC3_H

#include <stdio.h>

#include "pr_generic.h"
#include "common.h"
#include "error.h"
#include "p_ac3.h"
#include "ac3_common.h"

class ac3_reader_c: public generic_reader_c {
private:
  unsigned char          *chunk;
  FILE                   *file;
  class ac3_packetizer_c *ac3packetizer;
  int64_t                 bytes_processed, size;
     
public:
  ac3_reader_c(track_info_t *nti) throw (error_c);
  virtual ~ac3_reader_c();

  virtual int       read();
  virtual packet_t *get_packet();
  virtual int       display_priority();
  virtual void      display_progress();

  static int        probe_file(FILE *file, int64_t size);
};

#endif // __R_AC3_H
