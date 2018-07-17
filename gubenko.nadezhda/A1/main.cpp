#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"

void print(Shape & figure)
{
  std::cout << "Area: " << figure.getArea() << std::endl;
  std::cout << "Frame X: " << figure.getFrameRect().pos.x << " " << "Frame Y: " << figure.getFrameRect().pos.y << std::endl;
  std::cout << "Frame width " << figure.getFrameRect().width << " " << "Frame height " << figure.getFrameRect().height << std::endl;
}

int main()
{
  std::cout << "Creating Rectangle x=20, y=25, w=9, h=11" << std::endl;
  Rectangle r({20, 25}, 9, 11);
  print(r);

  std::cout << "Moving Rectangle by dx=3, dy=8" << std::endl;
  r.move(3, 8);
  print(r);

  std::cout << "Moving Rectangle to point x=33.41, y=15.41" << std::endl;
  r.move({33.41, 15.41});
  print(r);

  std::cout << "Creating Circle x=10.0, y=14.0, r=2" << std::endl;
  Circle c({10.0, 14.0}, 2.0);
  print(c);

  std::cout << "Moving Circle by dx=4, dy=7" << std::endl;
  c.move(4, 7);
  print(c);

  std::cout << "Moving Circle to point x=10.21, y=8.51" << std::endl;
  c.move({10.21, 8.51});
  print(c);

  return 0;
}
