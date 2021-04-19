#include "player_rectangle.h"

namespace brickbreaker {

    using glm::vec2;

    void PlayerRectangle::GoLeft() {
        rectangle_bottom_right_.x -= 10;
        rectangle_top_left_.x -= 10;
    }

    void PlayerRectangle::GoRight() {
        rectangle_bottom_right_.x += 10;
        rectangle_top_left_.x += 10;
    }
}  // namespace brickbreaker
