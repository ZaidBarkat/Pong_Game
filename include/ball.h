#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

namespace brickbreaker {

    using glm::vec2;

/**
 * Ball object for the player to hit.
 */
    class Ball {
    public:
        Ball(vec2 bottom_right, vec2 initial_velocity_);

        Ball();

        /**
         * Draws the ball
         */
        void Draw();

        /**
         * checks if the ball is hitting any of the walls
         *
         * @param top_left the top left of the wall
         * @param bottom_right of the wall
         */
        void CollidesWithWall(vec2 top_left, vec2 bottom_right);

        /**
         * add velocity to the position
         */
        void UpdatePosition();

        /**
         * checks if the ball is hitting the bottom wall
         * @return
         */
        bool IsEndGame();

        const vec2 &GetVelocity() const;

        const vec2 &GetPosition() const;

        static const float GetKRadius();

        void SetPosition(const vec2 &position);

        void SetVelocity(const vec2 &velocity);

    private:
        vec2 position_;
        vec2 velocity_;

        vec2 bottom_right_container_;
        static constexpr float kRadius = 8;

    };

}  // namespace brickbreaker
