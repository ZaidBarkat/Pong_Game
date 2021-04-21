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

    bool Ball::CollidesWithLine(vec2 top_left, vec2 bottom_right) {
        // if the position in the x direction is either hitting the left or right wall

        if ((position_.x + kRadius == top_left.x || position_.x - kRadius == bottom_right.x) &&
        position_.y + kRadius >= top_left.y && position_.y - kRadius <= bottom_right.y) {
            velocity_ = vec2(-velocity_.x, velocity_.y);
            return true;
        }
            // if the position in the y direction is hitting the top or bottom wall
        else if ((position_.y + kRadius == top_left.y || position_.y - kRadius == bottom_right.y) &&
        position_.x + kRadius >= top_left.x && position_.x - kRadius <= bottom_right.x) {
            velocity_ = vec2(velocity_.x, -velocity_.y);
            return true;
        }

        return false;
    }

    void Ball::CollidesWithWall(vec2 top_left, vec2 bottom_right) {
        // if the position in the x direction is either hitting the left or right wall

        if (position_.x - kRadius <= top_left.x || position_.x + kRadius >= bottom_right.x) {
            velocity_ = vec2(-velocity_.x, velocity_.y);
        }
            // if the position in the y direction is hitting the top or bottom wall
        else if (position_.y - kRadius <= top_left.y || position_.y + kRadius >= bottom_right.y) {
            velocity_ = vec2(velocity_.x, -velocity_.y);
        }
    }


    bool Ball::IsEndGame() {
        return position_.y + kRadius >= bottom_right_container_.y;
    }

}  // namespace brickbreaker
