#include <iostream>
#include <stdexcept>
#include "rectangle.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"

using namespace gubenko;

int main()
{
  try
  {
    auto r = std::make_shared <Rectangle> (point_t {20.0, 25.0}, 9.0, 11.0);
    std::cout << "Creating Rectangle x=20, y=25, w=9, h=11" << std::endl;
    std::cout << *r << std::endl;

    std::cout << "Moving Rectangle by dx=3, dy=8" << std::endl;
    r -> move(3, 8);
    std::cout << "coordinates (" << r -> getFrameRect().pos.x << ",  "<< r -> getFrameRect().pos.y << ") " << std::endl;

    std::cout << "Moving Rectangle to point x=33.41, y=15.41" << std::endl;
    r -> move({33.41, 15.41});
    std::cout << "coordinates (" << r -> getFrameRect().pos.x << ",  "<< r -> getFrameRect().pos.y << ") " << std::endl;

    std::cout << "scaled rectangle" << std::endl;
    r -> scale(2);
    std::cout << "scaling width and height (" << r -> getFrameRect().width << ",  "<< r -> getFrameRect().height << ") " << std::endl;


    auto c = std::make_shared <Circle> (point_t {10.0, 14.0}, 2.0);
    std::cout << "Creating Circle x=10.0, y=14.0, r=2" << std::endl;
    std::cout << *c << std::endl;

    std::cout << "Moving Circle by dx=4, dy=7" << std::endl;
    c -> move(4, 7);
    std::cout << "coordinates (" << c -> getFrameRect().pos.x << ",  "<< c -> getFrameRect().pos.y << ") " << std::endl;

    std::cout << "Moving Circle to point x=10.21, y=8.51" << std::endl;
    c -> move({10.21, 8.51});
    std::cout << " coordinates (" << c -> getFrameRect().pos.x << ",  "<< c -> getFrameRect().pos.y << ") " << std::endl;

    std::cout << "scaled circle" << std::endl;
    c -> scale(3);
    std::cout << "scaling width and height (" << c -> getFrameRect().width << ",  "<< c -> getFrameRect().height << ") " << std::endl;


    CompositeShape s(r);
    std::cout << "Composite Shape created" << std::endl;
    s.addShape(c);
    std::cout << s << std::endl;

  }
  catch (const std::invalid_argument &e)
  {
    std::cerr << e.what() << std::endl;
    return 1;
  }

  return 0;
}
