#include <iostream>
#include <ant.h>

int main(int, char**)
{
  //staring point:
#ifdef _ANT_TEST
  static const size_t x = 2;
  static const size_t y = 5;
#else
  static const size_t x = 1000;
  static const size_t y = 1000;
#endif

  std::cout << "simple_ant: I crawled " << ants::simple_ant().crawl(x, y) << " cells!" << std::endl;
  std::cout << "recursive_ant: I crawled " << ants::recursive_ant().crawl(x, y) << " cells!" << std::endl;

  return 0;
}