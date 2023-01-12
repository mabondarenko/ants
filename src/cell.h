#ifndef _ANTS_CELL__H_
#define _ANTS_CELL__H_

#pragma once

#include <types.h>

namespace ants {

#ifdef _ANT_TEST
static const char matrix[9][11] =
{
 // 0  1  2  3  4  5  6  7  8  9  10
  { 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0 }, // 0
  { 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0 }, // 1
  { 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0 }, // 2
  { 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0 }, // 3
  { 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0 }, // 4
  { 1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0 }, // 5
  { 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0 }, // 6
  { 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0 }, // 7
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }  // 8
};
#endif

template <typename _Type=size_t, _Type _Value=25>
class cell
{
public:
  cell(_Type x, _Type y)
    : valid_(check(x, y))
  {
  }

  operator bool() const { return valid_; }

private:
  size_t value(_Type n)
  {
    _Type sum = 0;
    while(n)
    {
      sum += n%10;
      n /= 10;
    }
    return sum;
  }

  bool check(_Type x, _Type y)
  {
#ifdef _ANT_TEST
    return matrix[y][x]==0;
#else
    return value(x) + value(y) <= _Value;
#endif
  }

private:
  bool valid_;
};

} //namespace ants {

#endif //_ANTS_CELL__H_