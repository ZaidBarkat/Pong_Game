#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "ball.h"
#include "rectangle.h"
#include "player_rectangle.h"
#include "brick.h"

namespace brickbreaker {

/**
 * An container for the Brick Breaker game.
 */
    class Container {
    public:
        Container();

        /**
         * draws the bricks, player , and balls
         */
        void Display();

        /**
         * updates the ball and rectangles
         */
        void Update();

        /**
         * makes the player go right
         */
        void PlayerRight();

        /**
         * makes the player go left
         */
        void PlayerLeft();

        /**
         * resets the ball, balls hit, and resets the rectangle
         */
        void Reset();

        const std::vector<Ball> &GetBalls() const;

        const PlayerRectangle &GetPlayerRectangle() const;

        void SetBricks(const std::vector<Brick> &bricks);

        void SetPlayerRectangle(const PlayerRectangle &playerRectangle);

    private:
        static constexpr float kContainerLeftX = 0;
        static constexpr float kContainerTopY = 0;
        static constexpr float kContainerRightX = 1000;
        static constexpr float kContainerBottomY = 1000;

        std::vector<Ball> balls_;
        PlayerRectangle player_rectangle_;
        std::vector<Brick> bricks_;
        int bricks_hit_ = 0;
        int level_ = 0;
    };

}  // namespace brickbreaker
