/*
  mkvmerge -- utility for splicing together matroska files
      from component media subtypes

  p_dts.h

  Written by Moritz Bunkus <moritz@bunkus.org>

  Distributed under the GPL
  see the file COPYING for details
  or visit http://www.gnu.org/copyleft/gpl.html
*/

/*!
    \file
    \version \$Id: p_dts.h,v 1.1 2003/05/15 08:58:52 mosu Exp $
    \brief class definition for the DTS output module
    \author Moritz Bunkus         <moritz @ bunkus.org>
*/
 
#ifndef __P_DTS_H
#define __P_DTS_H

#include "common.h"
#include "pr_generic.h"
#include "dts_common.h"

class dts_packetizer_c: public generic_packetizer_c {
private:
  int64_t bytes_output, packetno;
  unsigned long samples_per_sec;
  int buffer_size;
  unsigned char *packet_buffer;

public:
  dts_packetizer_c(generic_reader_c *nreader, unsigned long nsamples_per_sec,
                   track_info_t *nti) throw (error_c);
  virtual ~dts_packetizer_c();

  virtual int process(unsigned char *buf, int size, int64_t timecode = -1,
                      int64_t length = -1, int64_t bref = -1,
                      int64_t fref = -1);
  virtual void set_headers();
    
private:
  virtual void add_to_buffer(unsigned char *buf, int size);
  virtual unsigned char *get_dts_packet(unsigned long *header,
                                        dts_header_t *dtsheader);
  virtual int dts_packet_available();
  virtual void remove_dts_packet(int pos, int framesize);
};

#endif // __P_DTS_H
