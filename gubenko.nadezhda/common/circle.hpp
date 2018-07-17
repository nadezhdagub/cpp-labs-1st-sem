#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"
#include <iostream>

namespace gubenko
{
  class Circle: public Shape
  {
  public:
    Circle(const point_t & pos, double radius);
    friend std::ostream & gubenko::operator <<(std::ostream & out, const Circle & c);
    friend bool gubenko::operator==(const Circle &, const Circle &);
    double getRadius() const;
    std::string getName() const override;
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(double dx, double dy) override;
    void move(const point_t & pos) override;
    void scale(double n) override;
    void rotate (double /*angle*/) override {};

  private:
    point_t pos_;
    double radius_;
  };

  bool operator==(const Circle &, const Circle &);

  std::ostream & operator << (std::ostream & out, const Circle & c);
}

#endif //CIRCLE_HPP
