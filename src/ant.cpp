#include <ant.h>
#include <cell.h>
#include <vector>
#include <map>
#include <set>

namespace ants {

struct pos_t
{
  pos_t(size_t _x=0, size_t _y=0) : x(_x), y(_y) {}
  size_t x;
  size_t y;

  pos_t left() const { return pos_t(x-1, y); }
  pos_t top() const { return pos_t(x, y+1); }
  pos_t right() const { return pos_t(x+1, y); }
  pos_t bottom() const { return pos_t(x, y-1); }
};

using pos_array_t = std::vector<pos_t>;
using pos_set_t = std::set<size_t>;
using trampled_map_t = std::map<size_t, pos_set_t>;

static bool trampled(const pos_t& p, const trampled_map_t& trm)
{
  auto x = trm.find(p.x);
  if (x!=trm.end())
    return x->second.count(p.y)>0;

  return false;
}

static bool check(const pos_t& p, const trampled_map_t& trm)
{
  if (trampled(p, trm))
    return false;

  return cell<>(p.x, p.y);
}

static void step(const pos_t& p,
                 pos_array_t& cells,
                 trampled_map_t& trm)
{
  cells.push_back(p);
  trm[p.x].insert(p.y);
}

size_t simple_ant::crawl(size_t posx, size_t posy)
{
  pos_array_t cells;
  trampled_map_t trm;

  step({posx, posy}, cells, trm);

  size_t s = 0;
  while(s < cells.size())
  {
    auto p = cells[s];

    pos_t p1 = p.top();
    if (check(p1, trm))
      step(p1, cells, trm);

    pos_t p2 = p.right();
    if (check(p2, trm))
      step(p2, cells, trm);

    pos_t p3 = p.bottom();
    if (check(p3, trm))
      step(p3, cells, trm);

    pos_t p4 = p.left();
    if (check(p4, trm))
      step(p4, cells, trm);

    ++s;
  }

  return cells.size();
}

static void step(const pos_t& p,
                 size_t& cells,
                 trampled_map_t& trm)
{
  ++cells;
  trm[p.x].insert(p.y);

  pos_t p1 = p.left();
  if (check(p1, trm))
    step(p1, cells, trm);

  pos_t p2 = p.right();
  if (check(p2, trm))
    step(p2, cells, trm);

  pos_t p3 = p.top();
  if (check(p3, trm))
    step(p3, cells, trm);

  pos_t p4 = p.bottom();
  if (check(p4, trm))
    step(p4, cells, trm);
}

size_t recursive_ant::crawl(size_t posx, size_t posy)
{
  size_t cells = 0;
  trampled_map_t trm;

  step({posx, posy}, cells, trm);

  return cells;
}

} //namespace ants {