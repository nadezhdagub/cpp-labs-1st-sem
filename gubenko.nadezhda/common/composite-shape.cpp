#include "composite-shape.hpp"
#include <iostream>
#include <stdexcept>
#include <cmath>

using namespace gubenko;

CompositeShape::CompositeShape(const std::shared_ptr<Shape> &newShape):
  shapes_(new std::shared_ptr <Shape> [1]),
  size_(1)
{
  if (newShape == nullptr)
  {
    throw std::invalid_argument("invalid shape");
  }
  shapes_[0] = newShape;
}

CompositeShape::CompositeShape(const CompositeShape &composite_shape)
{
  std::unique_ptr <std::shared_ptr<Shape>[]> shapes_copy(new std::shared_ptr<Shape>[size_]);
  size_= composite_shape.size_;

  for (size_t i = 0; i < size_; i++)
  {
    shapes_copy[i] = composite_shape.shapes_[i];
  }

  shapes_.swap(shapes_copy);
}

CompositeShape & CompositeShape::operator=(const CompositeShape &composite_shape)
{
  if (this != &composite_shape)
  {
    std::unique_ptr <std::shared_ptr<Shape>[]> shapes_copy(new std::shared_ptr<Shape>[size_]);
    size_ = composite_shape.size_;

    for (size_t i = 0; i < size_; i++)
    {
      shapes_copy[i] = composite_shape.shapes_[i];
    }

    shapes_.swap(shapes_copy);
  }

  return *this;
}

bool gubenko::operator==(const CompositeShape &composite_shape_1, const CompositeShape &composite_shape_2)
{
  if (composite_shape_1.size_ != composite_shape_2.size_)
  {
    return false;
  }

  size_t i = 0;

  while (i < composite_shape_1.size_)
  {
    if (composite_shape_1.shapes_[i] == composite_shape_2.shapes_[i])
    {
      i++;
    }
    else
    {
      return false;
    }
  }

  return true;
}

void CompositeShape::addShape(const std::shared_ptr<gubenko::Shape> &newShape)
{
  if (newShape == nullptr)
  {
    throw std::invalid_argument("invalid shape");
  }

  std::unique_ptr <std::shared_ptr <Shape>[]> shapes_temp(new std::shared_ptr <Shape>[size_+1]);

  for (size_t i = 0; i < size_; i++)
  {
    shapes_temp[i] = shapes_[i];
  }

  shapes_temp[size_] = newShape;
  size_++;
  shapes_.swap(shapes_temp);
}

std::string CompositeShape::getName() const
{
  return "composite shape";
}

double CompositeShape::getArea() const
{
  double area = 0;

  for (size_t i = 0; i < size_; i++)
  {
    area += shapes_[i]->getArea();
  }
  return area;
}

rectangle_t CompositeShape::getFrameRect() const
{
  rectangle_t shapeFrameRect = shapes_[0]->getFrameRect();

  double shapeFrameRectUpperLeft_x = shapeFrameRect.pos.x - shapeFrameRect.width / 2;
  double shapeFrameRectUpperLeft_y = shapeFrameRect.pos.y + shapeFrameRect.height / 2;

  double shapeFrameRectLowerRight_x = shapeFrameRect.pos.x + shapeFrameRect.width / 2;
  double shapeFrameRectLowerRight_y = shapeFrameRect.pos.y - shapeFrameRect.height / 2;

  point_t upper_left = {shapeFrameRectUpperLeft_x, shapeFrameRectUpperLeft_y};
  point_t lower_right = {shapeFrameRectLowerRight_x, shapeFrameRectLowerRight_y};

  for (size_t i = 1; i < size_; i++)
  {
    shapeFrameRect = shapes_[i]->getFrameRect();

    shapeFrameRectUpperLeft_x = shapeFrameRect.pos.x - shapeFrameRect.width / 2;
    shapeFrameRectUpperLeft_y = shapeFrameRect.pos.y + shapeFrameRect.height / 2;

    shapeFrameRectLowerRight_x = shapeFrameRect.pos.x + shapeFrameRect.width / 2;
    shapeFrameRectLowerRight_y = shapeFrameRect.pos.y - shapeFrameRect.height / 2;

    if (shapeFrameRectUpperLeft_x < upper_left.x)
    {
      upper_left.x = shapeFrameRectUpperLeft_x;
    }

    if (shapeFrameRectUpperLeft_y > upper_left.y)
    {
      upper_left.y = shapeFrameRectUpperLeft_y;
    }

    if (shapeFrameRectLowerRight_x > lower_right.x)
    {
      lower_right.x = shapeFrameRectLowerRight_x;
    }

    if (shapeFrameRectLowerRight_y < lower_right.y)
    {
      lower_right.y = shapeFrameRectLowerRight_y;
    }
  }

  point_t center = {(upper_left.x + lower_right.x) / 2, (upper_left.y + lower_right.y) / 2};

  return {center, lower_right.x - upper_left.x, upper_left.y - lower_right.y};
}

void CompositeShape::move(double dx, double dy)
{
  for (size_t i = 0; i < size_; i++)
  {
    shapes_[i]->move(dx, dy);
  }
}

void CompositeShape::move(const point_t & pos)
{
  point_t center = getFrameRect().pos;
  move(pos.x-center.x, pos.y-center.y);
}

void CompositeShape::scale(double n)
{
  if (n < 0.0)
  {
    throw std::invalid_argument("n must be >= 0");
  }

  point_t center = getFrameRect().pos;

  for (size_t i = 0; i < size_; i++)
  {
    point_t shape_center = shapes_[i]->getFrameRect().pos;
    shapes_[i]->move({center.x + n*(shape_center.x-center.x),
                      center.y + n*(shape_center.y-center.y)});
    shapes_[i]->scale(n);
  }
}

void CompositeShape::rotate(double angle)
{
  double angle_cos = cos(angle * M_PI / 180);
  double angle_sin = sin(angle * M_PI / 180);

  point_t center = getFrameRect().pos;

  for (size_t i = 0; i < size_; i++)
  {
    point_t shape_center = shapes_[i]->getFrameRect().pos;

    shapes_[i]->move({center.x + angle_cos * (shape_center.x - center.x) - angle_sin * (shape_center.y - center.y),
                      center.y + angle_cos * (shape_center.y - center.y) + angle_sin * (shape_center.x - center.x)});

    shapes_[i]->rotate(angle);
  }
}

std::ostream & gubenko::operator <<(std::ostream & out, const CompositeShape & s)
{
  out << "Area: " << s.getArea() << std::endl;
  out << "pos (" << s.getFrameRect().pos.x << ", " << s.getFrameRect().pos.y << ")" << std::endl;
  out << "size: " << s.size_ ;

  return out;
