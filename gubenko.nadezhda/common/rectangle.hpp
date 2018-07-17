#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"
#include <iostream>

namespace gubenko
{
  class Rectangle: public Shape
  {
  public:
    Rectangle(const point_t & pos, double width, double height);
    friend std::ostream & gubenko::operator <<(std::ostream & out, const Rectangle & r);
    friend bool gubenko::operator==(const Rectangle &, const Rectangle &);
    double getWidth() const;
    double getHeight() const;
    std::string getName() const override;
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(double dx, double dy) override;
    void move (const point_t & pos) override;
    void scale(double n) override;
    void rotate(double angle) override;

  private:
    point_t corners_[4];
    double width_, height_;
  };

  bool operator==(const Rectangle &, const Rectangle &);

  std::ostream & operator <<(std::ostream & out, const Rectangle & r);
}

#endif // RECTANGLE_HPP
