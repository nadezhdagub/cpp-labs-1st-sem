#include "circle.hpp"
#include <cmath>
#include <stdexcept>

using namespace gubenko;

Circle::Circle(const point_t & pos, double radius):
  pos_ (pos),
  radius_(radius)
{
  if (radius < 0.0)
  {
    throw std::invalid_argument("invalid radius");
  }
}

bool gubenko::operator==(const Circle &circle_1, const Circle &circle_2)
{
  if (circle_1.pos_.x == circle_2.pos_.x &&
      circle_1.pos_.y == circle_2.pos_.y &&
      circle_1.radius_ == circle_2.radius_)
  {
    return true;
  }
  else
  {
    return false;
  }
}

double Circle::getRadius() const
{
  return radius_;
}

std::string Circle::getName() const
{
  return "circle";
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

void Circle::scale(double n)
{
  if (n < 0.0)
  {
    throw std::invalid_argument("n must be >= 0");
  }
  radius_ *= n;
}

std::ostream & gubenko::operator <<(std::ostream & out, const Circle & c)
{
  out << "Area: " << c.getArea() << std::endl;
  out <<"pos (" << c.getFrameRect().pos.x << ", " << c.getFrameRect().pos.y << ")" << std::endl;
  out << "radius: " << c.radius_;

  return out;
}
