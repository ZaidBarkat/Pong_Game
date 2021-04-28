#include "container.h"

namespace brickbreaker {

    using glm::vec2;

    Container::Container() {
        ball_ = Ball(vec2(kContainerLeftX, kContainerTopY),
                     vec2(kContainerRightX, kContainerBottomY));

        player_rectangle_ = PlayerRectangle(vec2(500, 800), vec2(700, 850));

        int increment_column = 0;
        while (bricks_.size() != kNumberOfRows * kNumberOfColumns) {
            float row_size = kContainerBottomY / kNumberOfRows - kSizeOfRectangle;
            for (int increment_row = (int) kContainerLeftX;
                 increment_row < (int) row_size; increment_row += kSizeOfRectangle) {
                Brick brick(vec2(increment_column, increment_row),
                                    vec2(increment_column + kSizeOfRectangle,
                                         increment_row + kSizeOfRectangle));
                bricks_.push_back(brick);
            }
            increment_column += (int) kSizeOfRectangle;
        }

    }

    void Container::Display() {
        ci::gl::color(ci::Color("white"));
        ci::gl::drawStrokedRect(ci::Rectf(vec2(kContainerLeftX, kContainerTopY),
                                          vec2(kContainerRightX, kContainerBottomY)));
        player_rectangle_.Draw();
        ball_.Draw();
        for (Brick &brick: bricks_) {
            brick.Draw();
        }

    }

    void Container::Update() {
        int bricks_hit = 0;

        for (size_t i = 0; i < bricks_.size(); i++) {
            bricks_[i].Update(ball_);

            if (bricks_[i].IsHidden()) {
                ++bricks_hit;
            }
        }

        if (ball_.IsEndGame() || bricks_hit == bricks_.size()) {
            exit(0);
        }

        player_rectangle_.Update(ball_);

        ball_.CollidesWithWall(vec2(kContainerLeftX, kContainerTopY), vec2(kContainerRightX, kContainerBottomY));

        ball_.UpdatePosition();
    }

    void Container::PlayerRight() {
        player_rectangle_.GoRight();
    }

    void Container::PlayerLeft() {
        player_rectangle_.GoLeft();
    }

}  // namespace brickbreaker
