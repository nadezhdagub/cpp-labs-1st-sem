#include <cmath>
#include <cassert>
#include <iostream>
#include "circle.hpp"

Circle::Circle(const point_t & pos, double radius):
pos_ (pos),
radius_(radius)
{
  assert(radius > 0);
}

double Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

rectangle_t Circle::getFrameRect() const
{
  return {pos_, radius_ * 2 , radius_ * 2};
} 

void Circle::move(const point_t & pos) 
{
  pos_ = pos;
}

void Circle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

