#include "rectangle.h"

namespace brickbreaker {

    using glm::vec2;

    Rectangle::Rectangle() {}

    Rectangle::Rectangle(vec2 top_left, vec2 bottom_right) {
        rectangle_top_left_ = top_left;
        rectangle_bottom_right_ = bottom_right;
    }

    void Rectangle::Draw() {
        ci::gl::color(ci::Color("Orange"));
        ci::gl::drawSolidRect(
                ci::Rectf(rectangle_top_left_,
                          rectangle_bottom_right_));
        ci::gl::color(ci::Color("black"));
        ci::gl::drawStrokedRect(ci::Rectf(rectangle_top_left_,
                                          rectangle_bottom_right_));
    }

}  // namespace brickbreaker
