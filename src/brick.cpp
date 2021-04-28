#include <ball.h>
#include "brick.h"

namespace brickbreaker {

    using glm::vec2;

    void Brick::Draw() {
        if (!is_hidden) {
            ci::gl::color(ci::Color("Orange"));
            ci::gl::drawSolidRect(
                    ci::Rectf(rectangle_top_left_,
                              rectangle_bottom_right_));
            ci::gl::color(ci::Color("black"));
            ci::gl::drawStrokedRect(ci::Rectf(rectangle_top_left_,
                                              rectangle_bottom_right_));
        }
    }

    void Brick::Update(Ball &ball) {
        if (!is_hidden) {
            if ((ball.GetPosition().x + ball.GetKRadius() == rectangle_top_left_.x ||
                 ball.GetPosition().x - ball.GetKRadius() == rectangle_bottom_right_.x) &&
                ball.GetPosition().y + ball.GetKRadius() >= rectangle_top_left_.y &&
                ball.GetPosition().y - ball.GetKRadius() <= rectangle_bottom_right_.y) {
                ball.SetVelocity(vec2(-ball.GetVelocity().x, ball.GetVelocity().y));
                is_hidden = true;
            }
                // if the position in the y direction is hitting the top or bottom wall
            else if ((ball.GetPosition().y + ball.GetKRadius() == rectangle_top_left_.y ||
                      ball.GetPosition().y - ball.GetKRadius() == rectangle_bottom_right_.y) &&
                     ball.GetPosition().x + ball.GetKRadius() >= rectangle_top_left_.x &&
                     ball.GetPosition().x - ball.GetKRadius() <= rectangle_bottom_right_.x) {
                ball.SetVelocity(vec2(ball.GetVelocity().x, -ball.GetVelocity().y));
                is_hidden = true;
            }
        }
    }

    bool Brick::IsHidden() const {
        return is_hidden;
    }

}  // namespace brickbreaker
