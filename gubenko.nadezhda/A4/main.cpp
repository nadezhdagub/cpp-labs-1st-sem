#include <iostream>
#include <stdexcept>
#include <cmath>
#include "rectangle.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"
#include "matrix-shape.hpp"

using namespace gubenko;

int main()
{
  auto r1 = std::make_shared <Rectangle> (point_t {20.0, 25.0}, 9.0, 11.0);
  std::cout << "Creating Rectangle x=20, y=25, w=9, h=11" << std::endl;
  std::cout << *r1 << std::endl;

  std::cout << "Moving Rectangle by dx=3, dy=8" << std::endl;
  r1 -> move(3, 8);
  std::cout << "coordinates (" << r1 -> getFrameRect().pos.x << ",  "<< r1 -> getFrameRect().pos.y << ") " << std::endl;

  std::cout << "Moving Rectangle to point x=33.41, y=15.41" << std::endl;
  r1 -> move({33.41, 15.41});
  std::cout << "coordinates (" << r1 -> getFrameRect().pos.x << ",  "<< r1 -> getFrameRect().pos.y << ") " << std::endl;

  std::cout << "scaled rectangle" << std::endl;
  r1 -> scale(2);
  std::cout << "scaling width and height (" << r1 -> getFrameRect().width << ",  "<< r1 -> getFrameRect().height << ") " << std::endl;

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

  auto r2 = std::make_shared <Rectangle> (point_t {19.0, 22.0}, 8.1, 13.3);
  std::cout << "Creating Rectangle x=20, y=25, w=9, h=11" << std::endl;
  std::cout << *r2 << std::endl;

  std::cout << "Moving Rectangle by dx=3, dy=8" << std::endl;
  r2 -> move(2, 3);
  std::cout << "coordinates (" << r2 -> getFrameRect().pos.x << ",  "<< r2 -> getFrameRect().pos.y << ") " << std::endl;

  std::cout << "Moving Rectangle to point x=33.41, y=15.41" << std::endl;
  r2 -> move({24.53, 12.39});
  std::cout << "coordinates (" << r2 -> getFrameRect().pos.x << ",  "<< r2 -> getFrameRect().pos.y << ") " << std::endl;

  std::cout << "scaled rectangle" << std::endl;
  r1 -> scale(1);
  std::cout << "scaling width and height (" << r2 -> getFrameRect().width << ",  "<< r2 -> getFrameRect().height << ") " << std::endl;


  MatrixShape matrix_shape(r1);
  std::cout << "matrix was created";

  matrix_shape.addShape(c);
  matrix_shape.addShape(r2);

  matrix_shape.print();
}
