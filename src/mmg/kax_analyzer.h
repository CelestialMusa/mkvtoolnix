/*
  mkvmerge GUI -- utility for splicing together matroska files
      from component media subtypes

  kax_analyzer.h

  Written by Moritz Bunkus <moritz@bunkus.org>
  Parts of this code were written by Florian Wager <root@sirelvis.de>

  Distributed under the GPL
  see the file COPYING for details
  or visit http://www.gnu.org/copyleft/gpl.html
*/

/*!
    \file
    \version $Id$
    \brief Matroska file analyzer
    \author Moritz Bunkus <moritz@bunkus.org>
*/

#ifndef __KAX_ANALYZER_H
#define __KAX_ANALYZER_H

#include <string>
#include <vector>

#include <ebml/EbmlElement.h>
#include <matroska/KaxSegment.h>

#include "wx/wx.h"

#include "common.h"
#include "error.h"
#include "mm_io.h"

using namespace std;
using namespace libmatroska;

class analyzer_data_c {
public:
  EbmlId id;
  int64_t pos, size;

public:
  analyzer_data_c(const EbmlId nid, int64_t npos, int64_t nsize):
  id(nid), pos(npos), size(nsize) {
  };
};

class kax_analyzer_c {
public:
  vector<analyzer_data_c *> data;
  string file_name;
  mm_io_c *file;
  KaxSegment *segment;
  wxWindow *parent;

public:
  kax_analyzer_c(wxWindow *nparent, string nname);
  virtual ~kax_analyzer_c();

  virtual void process();
  virtual bool update_element(EbmlElement *e);
  virtual EbmlElement *read_element(uint32_t pos,
                                    const EbmlCallbacks &callbacks);
  virtual int find(const EbmlId &id) {
    uint32_t i;

    for (i = 0; i < data.size(); i++)
      if (id == data[i]->id)
        return i;

    return -1;
  };

  static bool probe(string file_name);
};


#endif // __KAX_ANALYZER_H
