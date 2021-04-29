#include "container.h"

namespace brickbreaker {

    using glm::vec2;

    Container::Container() {
        balls_.push_back(Ball(vec2(kContainerRightX, kContainerBottomY),
                              vec2(2, -2)));

        player_rectangle_ = PlayerRectangle(vec2(500, 750), vec2(700, 770));

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
        for (Ball &ball: balls_) {
            ball.Draw();
        }
        for (Brick &brick: bricks_) {
            brick.Draw();
        }

    }

    void Container::Update() {
        for (size_t j = 0; j < balls_.size(); j++) {
            int bricks_hit = 0;
            for (size_t i = 0; i < bricks_.size(); i++) {
                bricks_[i].Update(balls_[j]);

                if (bricks_[i].IsHidden()) {
                    ++bricks_hit;
                }
            }

            if (bricks_hit >= 3 && new_balls_ != 4) {
                balls_.push_back(Ball(vec2(kContainerRightX, kContainerBottomY),
                                      vec2(2, 2)));
                new_balls_++;
            }

            if (balls_[j].IsEndGame() || bricks_hit == bricks_.size()) {
                exit(0);
            }

            player_rectangle_.Update(balls_[j]);

            balls_[j].CollidesWithWall(vec2(kContainerLeftX, kContainerTopY),
                                       vec2(kContainerRightX, kContainerBottomY));

            balls_[j].UpdatePosition();
        }
    }

    void Container::PlayerRight() {
        player_rectangle_.SetRectangleBottomRightX(player_rectangle_.GetRectangleBottomRight().x + 20);
        player_rectangle_.SetRectangleTopLeftX(player_rectangle_.GetRectangleTopLeft().x + 20);

    }

    void Container::PlayerLeft() {
        player_rectangle_.SetRectangleBottomRightX(player_rectangle_.GetRectangleBottomRight().x - 20);
        player_rectangle_.SetRectangleTopLeftX(player_rectangle_.GetRectangleTopLeft().x - 20);

    }

    void Container::ComputerPlayer() {
        float min_y = balls_[0].GetPosition().y;
        float min_x = 0;
        for (const Ball &ball : balls_) {
            if (min_y <= ball.GetPosition().y) {
                min_y = ball.GetPosition().y;
                min_x = ball.GetPosition().x;
            }
        }

        if (min_x < player_rectangle_.GetRectangleTopLeft().x) {
            player_rectangle_.SetRectangleBottomRightX(player_rectangle_.GetRectangleBottomRight().x - 30);
            player_rectangle_.SetRectangleTopLeftX(player_rectangle_.GetRectangleTopLeft().x - 30);
        } else if (min_x > player_rectangle_.GetRectangleBottomRight().x) {
            player_rectangle_.SetRectangleBottomRightX(player_rectangle_.GetRectangleBottomRight().x + 30);
            player_rectangle_.SetRectangleTopLeftX(player_rectangle_.GetRectangleTopLeft().x + 30);
        }
    }

    const std::vector<Ball> &Container::GetBalls() const {
        return balls_;
    }

    const PlayerRectangle &Container::GetPlayerRectangle() const {
        return player_rectangle_;
    }

}  // namespace brickbreaker
