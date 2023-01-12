#ifndef _ANTS_ANT__H_
#define _ANTS_ANT__H_

#pragma once

#include <types.h>

namespace ants {

struct Ant
{
  virtual size_t crawl(size_t posx, size_t posy) = 0;
};

struct simple_ant : public Ant
{
  virtual size_t crawl(size_t posx, size_t posy) override;
};

struct recursive_ant : public Ant
{
  virtual size_t crawl(size_t posx, size_t posy) override;
};



} //namespace ants {

#endif //_ANTS_ANT__H_