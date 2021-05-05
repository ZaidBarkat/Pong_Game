#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "container.h"

namespace brickbreaker {

/**
 * computer player to figure out how to hit the balls effectively
 */
    class ComputerPlayer {
    public:

        std::string ComputerMovement(Container &container);

    };

}  // namespace brickbreaker
