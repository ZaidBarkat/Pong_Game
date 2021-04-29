#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "rectangle.h"

namespace brickbreaker {

/**
 * A container for the Brick Breaker game.
 */
    class ComputerPlayer {
    public:


        void SetComputerMovement(Container container);

    private:
        Container container_;

    };

}  // namespace brickbreaker
