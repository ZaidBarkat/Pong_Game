#include "ball.h"

namespace brickbreaker {

    using glm::vec2;

    Ball::Ball() {}

    Ball::Ball(vec2 top_left, vec2 bottom_right) {
        position_ = vec2(bottom_right.x / 2, bottom_right.y / 2);
        top_left_container_ = top_left;
        bottom_right_container_ = bottom_right;

    }

    void Ball::Draw() {
        ci::gl::color(ci::Color("Orange"));
        ci::gl::drawSolidCircle(vec2(position_.x, position_.y), kRadius);

    }

    void Ball::UpdatePosition() {
        position_ += velocity_;
    }

    bool Ball::IsEndGame() {
        return position_.y + kRadius >= bottom_right_container_.y;
    }

}  // namespace brickbreaker
