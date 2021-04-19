#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

namespace brickbreaker {

/**
 * An container for the Brick Breaker game.
 */
    class Container {
    public:
        Container();

        void display() override;
        void update() override;

    };

}  // namespace idealgas
