#include <iostream>
#include <cassert>
#include "rectangle.hpp"

Rectangle::Rectangle(const point_t & pos, double width, double height):
  pos_(pos),
  width_(width),
  height_(height)
{
  assert(width > 0 && height > 0);
}

double Rectangle::getArea() const
{
  return width_ * height_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return{pos_, width_, height_};
}

void Rectangle::move(const point_t & pos)
{
  pos_ = pos;
}

void Rectangle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}
