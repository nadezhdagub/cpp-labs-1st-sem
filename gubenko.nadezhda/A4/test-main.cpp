#define BOOST_TEST_MAIN

#include <boost/test/included/unit_test.hpp>
#include "circle.hpp"
#include "rectangle.hpp"
#include "composite-shape.hpp"
#include "matrix-shape.hpp"
#include <stdexcept>

const double TOLERANCE = 0.001;

BOOST_AUTO_TEST_SUITE(testCircle)

BOOST_AUTO_TEST_CASE(invariability_of_radius_when_move_into)
  {
    gubenko::Circle circle({0,0},6);
  double rad = circle.getRadius();
  circle.move({15,15});
  BOOST_CHECK_CLOSE(circle.getRadius(),rad,TOLERANCE);
  }

BOOST_AUTO_TEST_CASE(invariability_of_radius_when_move_on)
  {
    gubenko::Circle circle({0,0},5);
  double rad = circle.getRadius();
  circle.move(-20,25);
  BOOST_CHECK_CLOSE(circle.getRadius(),rad,TOLERANCE);
  }

BOOST_AUTO_TEST_CASE(invariability_of_area_when_move_into)
  {
    gubenko::Circle circle({4,-2},10);
  double area = circle.getArea();
  circle.move({-4,-6});
  BOOST_CHECK_CLOSE(circle.getArea(),area,TOLERANCE);
  }

BOOST_AUTO_TEST_CASE(invariability_of_area_when_move_on)
  {
    gubenko::Circle circle({4,-7},10);
  double area = circle.getArea();
  circle.move(3,-2);
  BOOST_CHECK_CLOSE(circle.getArea(),area,TOLERANCE);
  }


BOOST_AUTO_TEST_CASE(Check_scale)
  {
    gubenko::Circle circle({12,-9},3);
  BOOST_CHECK_THROW(circle.scale(-5), std::invalid_argument);
  }
BOOST_AUTO_TEST_CASE(rotate_size)
  {
    gubenko::Rectangle rectangle({0, 10}, 5, 8);
  rectangle.rotate(90);

  BOOST_CHECK_CLOSE(rectangle.getWidth(), 5, TOLERANCE);
  BOOST_CHECK_CLOSE(rectangle.getHeight(), 8, TOLERANCE);
  }

BOOST_AUTO_TEST_CASE(rotate_area)
  {
    gubenko::Rectangle rectangle({0, 0}, 2, 3);
  rectangle.rotate(120);

  BOOST_CHECK_CLOSE(rectangle.getArea(), 6, TOLERANCE);
  }
BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(testRectangle)

BOOST_AUTO_TEST_CASE(invariability_of_width_when_move_into)
  {
    gubenko::Rectangle rectangle({0,0},7,3);
  double wid = rectangle.getWidth();
  rectangle.move({6,56});
  BOOST_CHECK_CLOSE(rectangle.getWidth(),wid,TOLERANCE);
  }

BOOST_AUTO_TEST_CASE(invariability_of_width_when_move_on)
  {
    gubenko::Rectangle rectangle({0,0},7,3);
  double wid = rectangle.getWidth();
  rectangle.move(3,-9);
  BOOST_CHECK_CLOSE(rectangle.getWidth(),wid,TOLERANCE);
  }

BOOST_AUTO_TEST_CASE(invariability_of_height_when_move_into)
  {
    gubenko::Rectangle rectangle({0,0},7,3);
  double hei = rectangle.getHeight();
  rectangle.move({-5,45});
  BOOST_CHECK_CLOSE(rectangle.getHeight(),hei,TOLERANCE);
  }

BOOST_AUTO_TEST_CASE(invariability_of_height_when_move_on)
  {
    gubenko::Rectangle rectangle({0,0},7,3);
  double hei = rectangle.getHeight();
  rectangle.move(-5,5);
  BOOST_CHECK_CLOSE(rectangle.getHeight(),hei,TOLERANCE);
  }

BOOST_AUTO_TEST_CASE(invariability_of_area_when_move_into)
  {
    gubenko::Rectangle rectangle({0,0},5,4);
  double area = rectangle.getArea();
  rectangle.move({-4,-6});
  BOOST_CHECK_CLOSE(rectangle.getArea(),area,TOLERANCE);
  }

BOOST_AUTO_TEST_CASE(invariability_of_area_when_move_on)
  {
    gubenko::Rectangle rectangle({0,0},7,3);
  double area = rectangle.getArea();
  rectangle.move(3,-2);
  BOOST_CHECK_CLOSE(rectangle.getArea(),area,TOLERANCE);
  }


BOOST_AUTO_TEST_CASE(Check_scale)
  {
    gubenko::Rectangle rectangle({3,6},3,2);
  BOOST_CHECK_THROW(rectangle.scale(-1), std::invalid_argument);
  }
BOOST_AUTO_TEST_CASE(rotate_size)
  {
    gubenko::Rectangle rectangle({0, 10}, 5, 8);
  rectangle.rotate(90);

  BOOST_CHECK_CLOSE(rectangle.getWidth(), 5, TOLERANCE);
  BOOST_CHECK_CLOSE(rectangle.getHeight(), 8, TOLERANCE);
  }

BOOST_AUTO_TEST_CASE(rotate_area)
  {
    gubenko::Rectangle rectangle({0, 0}, 2, 3);
  rectangle.rotate(120);

  BOOST_CHECK_CLOSE(rectangle.getArea(), 6, TOLERANCE);
  }
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(testCompositeShape)

BOOST_AUTO_TEST_CASE(invariability_of_width_when_move_into)
  {
    std::shared_ptr<gubenko::Shape> shape1 = std::make_shared<gubenko::Rectangle>(gubenko::Rectangle({0,0},5,2));
  std::shared_ptr<gubenko::Shape> shape2 = std::make_shared<gubenko::Circle>(gubenko::Circle({5,2},1));
  gubenko::CompositeShape compositeShape(shape1);
  compositeShape.addShape(shape2);
  double width = compositeShape.getFrameRect().width;
  compositeShape.move({3,-2});
  BOOST_CHECK_CLOSE(compositeShape.getFrameRect().width,width,TOLERANCE);
  }

BOOST_AUTO_TEST_CASE(invariability_of_width_when_move_on)
  {
    std::shared_ptr<gubenko::Shape> shape1 = std::make_shared<gubenko::Rectangle>(gubenko::Rectangle({0,0},5,2));
  std::shared_ptr<gubenko::Shape> shape2 = std::make_shared<gubenko::Circle>(gubenko::Circle({5,2},1));
  gubenko::CompositeShape compositeShape(shape1);
  compositeShape.addShape(shape2);
  double width = compositeShape.getFrameRect().width;
  compositeShape.move(3,-2);
  BOOST_CHECK_CLOSE(compositeShape.getFrameRect().width,width,TOLERANCE);
  }

BOOST_AUTO_TEST_CASE(invariability_of_height_when_move_into)
  {
    std::shared_ptr<gubenko::Shape> shape1 = std::make_shared<gubenko::Rectangle>(gubenko::Rectangle({0,0},5,2));
  std::shared_ptr<gubenko::Shape> shape2 = std::make_shared<gubenko::Circle>(gubenko::Circle({5,2},1));
  gubenko::CompositeShape compositeShape(shape1);
  compositeShape.addShape(shape2);
  double height = compositeShape.getFrameRect().height;
  compositeShape.move({3,-2});
  BOOST_CHECK_CLOSE(compositeShape.getFrameRect().height,height,TOLERANCE);
  }

BOOST_AUTO_TEST_CASE(invariability_of_height_when_move_on)
  {
    std::shared_ptr<gubenko::Shape> shape1 = std::make_shared<gubenko::Rectangle>(gubenko::Rectangle({0,0},5,2));
  std::shared_ptr<gubenko::Shape> shape2 = std::make_shared<gubenko::Circle>(gubenko::Circle({5,2},1));
  gubenko::CompositeShape compositeShape(shape1);
  compositeShape.addShape(shape2);
  double height = compositeShape.getFrameRect().height;
  compositeShape.move(3,-2);
  BOOST_CHECK_CLOSE(compositeShape.getFrameRect().height,height,TOLERANCE);
  }

BOOST_AUTO_TEST_CASE(invariability_of_area_when_move_into)
  {
    std::shared_ptr<gubenko::Shape> shape1 = std::make_shared<gubenko::Rectangle>(gubenko::Rectangle({0,0},5,2));
  std::shared_ptr<gubenko::Shape> shape2 = std::make_shared<gubenko::Circle>(gubenko::Circle({5,2},1));
  gubenko::CompositeShape compositeShape(shape1);
  compositeShape.addShape(shape2);
  double area = shape1->getArea()+shape2->getArea();
  compositeShape.move({3,-2});
  BOOST_CHECK_CLOSE(compositeShape.getArea(),area,TOLERANCE);
  }

BOOST_AUTO_TEST_CASE(invariability_of_area_when_move_on)
  {
    std::shared_ptr<gubenko::Shape> shape1 = std::make_shared<gubenko::Rectangle>(gubenko::Rectangle({0,0},5,2));
  std::shared_ptr<gubenko::Shape> shape2 = std::make_shared<gubenko::Circle>(gubenko::Circle({5,2},1));
  gubenko::CompositeShape compositeShape(shape1);
  compositeShape.addShape(shape2);
  double area = shape1->getArea()+shape2->getArea();
  compositeShape.move(3,-2);
  BOOST_CHECK_CLOSE(compositeShape.getArea(),area,TOLERANCE);
  }

BOOST_AUTO_TEST_CASE(Check_scale)
  {
    std::shared_ptr<gubenko::Shape> shape1 = std::make_shared<gubenko::Rectangle>(gubenko::Rectangle({0,0},5,2));
  gubenko::CompositeShape compositeShape(shape1);
  BOOST_CHECK_THROW(compositeShape.scale(-1), std::invalid_argument);
  }

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(testRotation)

BOOST_AUTO_TEST_CASE(rectangle)
  {
    gubenko::Rectangle rectangle({10, 0}, 3, 3);
  rectangle.rotate(-45);

  gubenko::rectangle_t frame_rect = rectangle.getFrameRect();

  BOOST_CHECK_CLOSE(frame_rect.pos.x, 10, TOLERANCE);
  BOOST_CHECK_CLOSE(frame_rect.pos.y, 0, TOLERANCE);
  BOOST_CHECK_CLOSE(frame_rect.width, 3 * sqrt(2), TOLERANCE);
  BOOST_CHECK_CLOSE(frame_rect.height, 3 * sqrt(2), TOLERANCE);
  }
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(testMatrixShape)

BOOST_AUTO_TEST_CASE(new_rows)
  {
    auto rectangle = std::make_shared<gubenko::Rectangle>(gubenko::point_t{-3, -1}, 4, 4);
  auto circle = std::make_shared<gubenko::Circle>(gubenko::point_t{-1, 0}, 2);

  gubenko::MatrixShape matrix_shape(rectangle);
  matrix_shape.addShape(circle);

  BOOST_CHECK(matrix_shape[1][0] == circle);
  }

BOOST_AUTO_TEST_CASE(new_columns)
  {
    auto rect1 = std::make_shared<gubenko::Rectangle>(gubenko::point_t{1, -1}, 2, 2);
  auto rect2 = std::make_shared<gubenko::Rectangle>(gubenko::point_t{0, 0}, 2, 2);
  auto rect3 = std::make_shared<gubenko::Rectangle>(gubenko::point_t{2, -2}, 2, 2);

  gubenko::MatrixShape matrix_shape(rect1);
  matrix_shape.addShape(rect2);
  matrix_shape.addShape(rect3);

  BOOST_CHECK(matrix_shape[1][1] == rect3);
  }

BOOST_AUTO_TEST_SUITE_END()
