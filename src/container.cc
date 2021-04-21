#include "container.h"

namespace brickbreaker {

    using glm::vec2;

    Container::Container() {
        ball_ = Ball(vec2(kContainerLeftX, kContainerTopY),
                     vec2(kContainerRightX, kContainerBottomY));

        player_rectangle_ = PlayerRectangle(vec2(500, 800), vec2(700, 850));

        int increment_column = 0;
        while (rectangles_.size() != kNumberOfRows * kNumberOfColumns) {
            float row_size = kContainerBottomY / kNumberOfRows - kSizeOfRectangle;
            for (int increment_row = (int) kContainerLeftX;
                 increment_row < (int) row_size; increment_row += kSizeOfRectangle) {
                Rectangle rectangle(vec2(increment_column, increment_row),
                                    vec2(increment_column + kSizeOfRectangle,
                                         increment_row + kSizeOfRectangle));
                rectangles_.push_back(rectangle);
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
        for (Rectangle &rectangle: rectangles_) {
            rectangle.Draw();
        }

    }

    void Container::Update() {
        for (size_t i = 0; i < rectangles_.size(); i++) {
            if (ball_.CollidesWithLine(rectangles_[i].GetRectangleTopLeft(), rectangles_[i].GetRectangleBottomRight())) {
                rectangles_.erase(rectangles_.begin() + i);
            }
        }

        ball_.CollidesWithLine(player_rectangle_.GetRectangleTopLeft(), player_rectangle_.GetRectangleBottomRight());

        ball_.CollidesWithWall(vec2(kContainerLeftX, kContainerTopY), vec2(kContainerRightX, kContainerBottomY));

        ball_.UpdatePosition();

        if (ball_.IsEndGame() || rectangles_.empty()) {
            exit(0);
        }
    }

    void Container::PlayerRight() {
        player_rectangle_.GoRight();
    }

    void Container::PlayerLeft() {
        player_rectangle_.GoLeft();
    }

}  // namespace brickbreaker
