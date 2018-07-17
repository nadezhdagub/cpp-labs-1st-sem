#include "rectangle.hpp"
#include <stdexcept>
#include <cassert>
#include <iostream>
#include <cmath>

using namespace gubenko;

Rectangle::Rectangle(const point_t & pos, double width, double height):
  corners_{{pos.x - width / 2, pos.y + height / 2},
           {pos.x + width / 2, pos.y + height / 2},
           {pos.x + width / 2, pos.y - height / 2},
           {pos.x - width / 2, pos.y - height / 2}},
  width_(width),
  height_(height)
{
  if (width < 0.0)
  {
    throw std::invalid_argument("invalid width");
  }

  if (height < 0.0)
  {
    throw std::invalid_argument("invalid height");
  }
}

bool gubenko::operator==(const Rectangle &rectangle_1, const Rectangle &rectangle_2)
{
  for (size_t i = 0; i < 4; i++)
  {
    if (rectangle_1.corners_[i].x != rectangle_2.corners_[i].x ||
        rectangle_1.corners_[i].y != rectangle_2.corners_[i].y)
    {
      return false;
    }
  }

  if (rectangle_1.width_ == rectangle_2.width_ &&
      rectangle_1.height_ == rectangle_2.height_)
  {
    return true;
  }
  else
  {
    return false;
  }
}

double Rectangle::getWidth() const
{
  return width_;
}

double Rectangle::getHeight() const
{
  return height_;
}

std::string Rectangle::getName() const
{
  return "rectangle";
}

double Rectangle::getArea() const
{
  return width_ * height_;
}

rectangle_t Rectangle::getFrameRect() const
{
  point_t center = {(corners_[0].x + corners_[2].x) / 2, (corners_[0].y + corners_[2].y) / 2};

  point_t top_left = center;
  point_t bottom_right = center;

  for (size_t i = 0; i < 4; i++)
  {
    if (corners_[i].x < top_left.x)
    {
      top_left.x = corners_[i].x;
    }

    if (corners_[i].y > top_left.y)
    {
      top_left.y = corners_[i].y;
    }

    if (corners_[i].x > bottom_right.x)
    {
      bottom_right.x = corners_[i].x;
    }

    if (corners_[i].y < bottom_right.y)
    {
      bottom_right.y = corners_[i].y;
    }
  }

  return {center, bottom_right.x - top_left.x, top_left.y - bottom_right.y};
}

void Rectangle::move(const point_t &pos)
{
  point_t center = getFrameRect().pos;
  move(pos.x - center.x, pos.y - center.y);
}

void Rectangle::move(double dx, double dy)
{
  for (size_t i = 0; i < 4; i++)
  {
    corners_[i].x += dx;
    corners_[i].y += dy;
  }
}

void Rectangle::scale(double k)
{
  if (k < 0)
  {
    throw std::invalid_argument("invalid scaling factor");
  }

  point_t center = getFrameRect().pos;

  for (size_t i = 0; i < 4; i++)
  {
    corners_[i] = {center.x + k * (corners_[i].x - center.x), center.y + k * (corners_[i].y - center.y)};
  }

  width_ *= k;
  height_ *= k;
}

void Rectangle::rotate(double angle)
{
  angle = angle * M_PI / 180;

  double angle_cos = cos(angle);
  double angle_sin = sin(angle);

  point_t center = getFrameRect().pos;

  for (size_t i = 0; i < 4; i++)
  {
    corners_[i] = {center.x + angle_cos * (corners_[i].x - center.x) - angle_sin * (corners_[i].y - center.y),
                   center.y + angle_cos * (corners_[i].y - center.y) + angle_sin * (corners_[i].x - center.x)};
  }
}

std::ostream & gubenko::operator <<(std::ostream & out, const Rectangle & r1)
{
  out << "Area: " << r1.getArea() << std::endl;
  out <<"pos (" << r1.getFrameRect().pos.x << ", " << r1.getFrameRect().pos.y << ")" << std::endl;
  out << "width: " << r1.getFrameRect().width << std::endl;
  out << "height: " << r1.getFrameRect().height;

  return out;
}
