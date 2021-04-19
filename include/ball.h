#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

namespace brickbreaker {

    using glm::vec2;

/**
 * An container for the Brick Breaker game.
 */
    class Ball {
    public:
        Ball(vec2 top_left, vec2 bottom_right);

        Ball();

        void Draw();

        bool CollidesWithLine(vec2 top_left, vec2 bottom_right);
        void CollidesWithWall(vec2 top_left, vec2 bottom_right);

        void UpdatePosition();

        bool IsEndGame();

    private:
        vec2 position_;
        vec2 velocity_ = vec2(4, -2);

        vec2 top_left_container_;
        vec2 bottom_right_container_;
        static constexpr float kRadius = 10;
    };

}  // namespace brickbreaker
