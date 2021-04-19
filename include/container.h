#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "ball.h"

namespace brickbreaker {

/**
 * An container for the Brick Breaker game.
 */
    class Container {
    public:
        Container();

        void Display();
        void Update();

    private:
        static constexpr float kContainerLeftX = 5;
        static constexpr float kContainerTopY = 5;
        static constexpr float kContainerRightX = 1000;
        static constexpr float kContainerBottomY = 1000;

        Ball ball_;
    };

}  // namespace brickbreaker
