#include <iostream>
#include <stdexcept>
#include "rectangle.hpp"
#include "circle.hpp"

using namespace gubenko;

int main()
{
  try
  {
    Rectangle r({20, 25}, 9, 11);
    std::cout << "Creating Rectangle x=20, y=25, w=9, h=11" << std::endl;
    std::cout << r << std::endl;

    r.move(3, 8);
    std::cout << "Moving Rectangle by dx=3, dy=8" << std::endl;
    std::cout << r << std::endl;

    r.move({33.41, 15.41});
    std::cout << "Moving Rectangle to point x=33.41, y=15.41" << std::endl;
    std::cout << r << std::endl;

    r.scale(2);
    std::cout << "scaled rectangle" << std::endl;
    std::cout << r << std::endl;
  }
  catch (const std::invalid_argument &e)
  {
    std::cerr << e.what() << std::endl;
    return 1;
  }

  try
  {
    Circle c({10.0, 14.0}, 2.0);
    std::cout << "Creating Circle x=10.0, y=14.0, r=2" << std::endl;
    std::cout << c << std::endl;

    c.move(4, 7);
    std::cout << "Moving Circle by dx=4, dy=7" << std::endl;
    std::cout << c << std::endl;

    c.move({10.21, 8.51});
    std::cout << "Moving Circle to point x=10.21, y=8.51" << std::endl;
    std::cout << c << std::endl;

    c.scale(3);
    std::cout << "scaled circle" << std::endl;
    std::cout << c << std::endl;
  }
  catch (const std::invalid_argument & e)
  {
    std::cerr << e.what() << std::endl;
    return 1;
  }

  return 0;
}
