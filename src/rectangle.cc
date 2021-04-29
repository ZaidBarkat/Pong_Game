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

    void Rectangle::Update(Ball &ball) {
        if ((ball.GetPosition().x + ball.GetKRadius() == rectangle_top_left_.x ||
             ball.GetPosition().x - ball.GetKRadius() == rectangle_bottom_right_.x) &&
            ball.GetPosition().y + ball.GetKRadius() >= rectangle_top_left_.y &&
            ball.GetPosition().y - ball.GetKRadius() <= rectangle_bottom_right_.y) {
            ball.SetVelocity(vec2(-ball.GetVelocity().x, ball.GetVelocity().y));
        }
            // if the position in the y direction is hitting the top or bottom wall
        else if ((ball.GetPosition().y + ball.GetKRadius() == rectangle_top_left_.y ||
                  ball.GetPosition().y - ball.GetKRadius() == rectangle_bottom_right_.y) &&
                 ball.GetPosition().x + ball.GetKRadius() >= rectangle_top_left_.x &&
                 ball.GetPosition().x - ball.GetKRadius() <= rectangle_bottom_right_.x) {
            ball.SetVelocity(vec2(ball.GetVelocity().x, -ball.GetVelocity().y));
        }
    }

    const vec2 &Rectangle::GetRectangleTopLeft() const {
        return rectangle_top_left_;
    }

    const vec2 &Rectangle::GetRectangleBottomRight() const {
        return rectangle_bottom_right_;
    }

    void Rectangle::SetRectangleTopLeftX(const float &rectangleTopLeftX) {
        rectangle_top_left_.x = rectangleTopLeftX;
    }

    void Rectangle::SetRectangleBottomRightX(const float &rectangleBottomRightX) {
        rectangle_bottom_right_.x = rectangleBottomRightX;
    }

}  // namespace brickbreaker
