#include "player_rectangle.h"

namespace brickbreaker {

    using glm::vec2;

    void PlayerRectangle::GoLeft() {
        rectangle_bottom_right_.x -= 20;
        rectangle_top_left_.x -= 20;
    }

    void PlayerRectangle::GoRight() {
        rectangle_bottom_right_.x += 20;
        rectangle_top_left_.x += 20;
    }
}  // namespace brickbreaker
