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

        void Display();
        void Update();
        void PlayerRight();
        void PlayerLeft() ;

    private:
        static constexpr float kContainerLeftX = 0;
        static constexpr float kContainerTopY = 0;
        static constexpr float kContainerRightX = 1000;
        static constexpr float kContainerBottomY = 1000;
        static constexpr int kSizeOfRectangle = 100;
        static constexpr int kNumberOfRows = 3;
        static constexpr int kNumberOfColumns = 10;

        Ball ball_;
        PlayerRectangle player_rectangle_;
        std::vector<Brick> bricks_;
    };

}  // namespace brickbreaker
