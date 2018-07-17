#define BOOST_TEST_MAIN

#include <stdexcept>
#include <boost/test/included/unit_test.hpp>
#include "rectangle.hpp"
#include "circle.hpp"

const double TOLERANCE = 0.0002;

BOOST_AUTO_TEST_SUITE(CircleTest)

BOOST_AUTO_TEST_CASE(radius_move)
  {
    gubenko::Circle shape({0, 0}, 4);
  gubenko::Shape *circle = & shape;
  circle->move({30, 10});
  BOOST_CHECK_CLOSE(shape.getRadius(), 4, TOLERANCE);
  }

BOOST_AUTO_TEST_CASE(area_move)
  {
    gubenko::Circle shape({0, 0}, 4);
  gubenko::Shape *circle = & shape;
  circle->move({7, 31});
  BOOST_CHECK_CLOSE(circle->getArea(), M_PI * 16, TOLERANCE);
  }

BOOST_AUTO_TEST_CASE(area_scale)
  {
    gubenko::Circle shape({0, 0}, 4);
  gubenko::Shape *circle = & shape;
  circle->scale(3);
  BOOST_CHECK_CLOSE(circle->getArea(), M_PI * 144, TOLERANCE);
  }

BOOST_AUTO_TEST_CASE(invalid_radius)
  {
    BOOST_CHECK_THROW(gubenko::Circle ({0, 0}, -1), std::invalid_argument);
  }

BOOST_AUTO_TEST_CASE(invalid_scale)
  {
    gubenko::Circle shape({0, 0}, 1);
  gubenko::Shape *circle = & shape;
  BOOST_CHECK_THROW(circle->scale(-3), std::invalid_argument);
  }

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(RectangleTest)

BOOST_AUTO_TEST_CASE(width_move)
  {
    gubenko::Rectangle shape({0, 0}, 4, 8);
  gubenko::Shape *rectangle = & shape;
  rectangle->move({10, 20});
  BOOST_CHECK_CLOSE(shape.getWidth(), 4, TOLERANCE);
  }

BOOST_AUTO_TEST_CASE(height_move)
  {
    gubenko::Rectangle shape({0, 0}, 10, 2);
  gubenko::Shape *rectangle = &shape;
  rectangle->move({0, 0});
  BOOST_CHECK_CLOSE(shape.getHeight(), 2, TOLERANCE);
  }

BOOST_AUTO_TEST_CASE(area_move)
  {
    gubenko::Rectangle shape({10, 10}, 5, 3);
  gubenko::Shape *rectangle = &shape;
  rectangle->move({0, 0});
  BOOST_CHECK_CLOSE(rectangle->getArea(), 15, TOLERANCE);
  }

BOOST_AUTO_TEST_CASE(area_scale)
  {
    gubenko::Rectangle shape({0, 0}, 2, 3);
  gubenko::Shape *rectangle = &shape;
  rectangle->scale(2);
  BOOST_CHECK_CLOSE(rectangle->getArea(), 24, TOLERANCE);
  }

BOOST_AUTO_TEST_CASE(invalid_width)
  {
    BOOST_CHECK_THROW(gubenko::Rectangle shape({0, 0}, -10, 3), std::invalid_argument);
  }

BOOST_AUTO_TEST_CASE(invalid_height)
  {
    BOOST_CHECK_THROW(gubenko::Rectangle shape({0, 0}, 5, -1), std::invalid_argument);
  }

BOOST_AUTO_TEST_CASE(invalid_scale)
  {
    gubenko::Rectangle shape({0, 0}, 10, 10);
  gubenko::Shape *rectangle = &shape;
  BOOST_CHECK_THROW(rectangle->scale(-1), std::invalid_argument);
  }

BOOST_AUTO_TEST_SUITE_END()
