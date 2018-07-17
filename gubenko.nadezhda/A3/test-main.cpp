#define BOOST_TEST_MAIN

#include <boost/test/included/unit_test.hpp>
#include <stdexcept>
#include "rectangle.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"

const double TOLERANCE = 0.0002;

BOOST_AUTO_TEST_SUITE(CompositeShapeTest)

BOOST_AUTO_TEST_CASE(AreaMove)
  {
    auto rect1 = std::make_shared <gubenko::Rectangle> (gubenko::point_t {1.5, 3}, 3, 1);
  auto rect2 = std::make_shared <gubenko::Rectangle> (gubenko::point_t {2.5, 3}, 3, 2);

  gubenko::CompositeShape composite_shape(rect1);

  composite_shape.addShape(rect2);

  double area = composite_shape.getArea();

  composite_shape.move({3, 6});

  BOOST_CHECK_CLOSE(composite_shape.getArea(), area, TOLERANCE);
  }

BOOST_AUTO_TEST_CASE(FrameRect_size_move)
  {
    auto rectangle = std::make_shared <gubenko::Rectangle> (gubenko::point_t {2.5, 2}, 3, 2);
  auto circle = std::make_shared <gubenko::Circle> (gubenko::point_t {6, 4}, 1);

  gubenko::CompositeShape composite_shape(rectangle);

  composite_shape.addShape(circle);

  double widthBefore = composite_shape.getFrameRect().width;
  double heightBefore = composite_shape.getFrameRect().height;

  composite_shape.move({10, 20});

  BOOST_CHECK_CLOSE(composite_shape.getFrameRect().width, widthBefore, TOLERANCE);
  BOOST_CHECK_CLOSE(composite_shape.getFrameRect().height, heightBefore, TOLERANCE);
  }

BOOST_AUTO_TEST_CASE(FrameRect_pos_move)
  {
    auto rectangle = std::make_shared <gubenko::Rectangle>(gubenko::point_t {0, 0}, 2, 4);
  auto circle = std::make_shared <gubenko::Circle> (gubenko::point_t {2, -2}, 2);

  gubenko::CompositeShape composite_shape(rectangle);

  composite_shape.addShape(circle);

  double xBefore = composite_shape.getFrameRect().pos.x;
  double yBefore = composite_shape.getFrameRect().pos.y;

  composite_shape.move(0, 0);

  BOOST_CHECK_CLOSE(composite_shape.getFrameRect().pos.x, xBefore, TOLERANCE);
  BOOST_CHECK_CLOSE(composite_shape.getFrameRect().pos.y, yBefore, TOLERANCE);
  }

BOOST_AUTO_TEST_CASE(Relative_move)
  {
    auto rectangle = std::make_shared <gubenko::Rectangle>(gubenko::point_t {0, 0}, 2, 4);
  auto circle = std::make_shared <gubenko::Circle> (gubenko::point_t {2, -2}, 2);

  gubenko::CompositeShape composite_shape(rectangle);

  composite_shape.addShape(circle);

  double area = composite_shape.getArea();

  composite_shape.move(2, 2);

  BOOST_CHECK_CLOSE(composite_shape.getArea(), area, TOLERANCE );
  }

BOOST_AUTO_TEST_CASE(FrameRect_pos_scale)
  {
    auto rectangle = std::make_shared <gubenko::Rectangle> (gubenko::point_t {3, -2}, 2, 2);
  auto circle = std::make_shared <gubenko::Circle> (gubenko::point_t {0, 2}, 1);

  gubenko::CompositeShape composite_shape(rectangle);

  composite_shape.addShape(circle);

  double xBefore = composite_shape.getFrameRect().pos.x;
  double yBefore = composite_shape.getFrameRect().pos.y;

  composite_shape.scale(2);

  BOOST_CHECK_CLOSE(composite_shape.getFrameRect().pos.x, xBefore, TOLERANCE);
  BOOST_CHECK_CLOSE(composite_shape.getFrameRect().pos.y, yBefore, TOLERANCE);
  }

BOOST_AUTO_TEST_CASE(FrameRect_size_scale)
  {
    auto rectangle = std::make_shared <gubenko::Rectangle> (gubenko::point_t{2, -2}, 2, 2);
  auto circle = std::make_shared <gubenko::Circle> (gubenko::point_t {-2, 2}, 1);

  gubenko::CompositeShape composite_shape(rectangle);

  composite_shape.addShape(circle);

  double widthBefore = composite_shape.getFrameRect().width;
  double heightBefore = composite_shape.getFrameRect().height;

  composite_shape.scale(1);

  BOOST_CHECK_CLOSE(composite_shape.getFrameRect().width, widthBefore, TOLERANCE);
  BOOST_CHECK_CLOSE(composite_shape.getFrameRect().height, heightBefore, TOLERANCE);
  }

BOOST_AUTO_TEST_CASE(AreaScale)
  {
    auto rectangle = std::make_shared <gubenko::Rectangle> (gubenko::point_t {-1, 0.5}, 4, 1);
  auto circle = std::make_shared <gubenko::Circle> (gubenko::point_t {-2, 3}, 1);

  gubenko::CompositeShape composite_shape(rectangle);

  composite_shape.addShape(circle);

  double area = composite_shape.getArea();
  double k = 2;

  composite_shape.scale(k);

  BOOST_CHECK_CLOSE(composite_shape.getArea(), area * k * k, TOLERANCE);
  }

BOOST_AUTO_TEST_CASE(InvalidDetection)
  {
    BOOST_CHECK_THROW(gubenko::CompositeShape composite_shape(nullptr), std::invalid_argument);
  }

BOOST_AUTO_TEST_CASE(invalid_scale)
  {
    auto rectangle = std::make_shared <gubenko::Rectangle>(gubenko::point_t{0, 0}, 5, 5);
  gubenko::CompositeShape composite_shape(rectangle);

  BOOST_CHECK_THROW(composite_shape.scale(-1), std::invalid_argument);
  }
BOOST_AUTO_TEST_CASE(invalid_addShape)
  {
    auto circle = std::make_shared <gubenko::Circle> (gubenko::point_t {0, 0}, 3);
  gubenko::CompositeShape composite_shape(circle);

  BOOST_CHECK_THROW(composite_shape.addShape(nullptr), std::invalid_argument);
  }

BOOST_AUTO_TEST_SUITE_END()
