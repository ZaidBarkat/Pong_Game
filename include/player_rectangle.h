#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "rectangle.h"

namespace brickbreaker {

    using glm::vec2;

/**
 * An container for the Brick Breaker game.
 */
    class PlayerRectangle : public Rectangle {
    public:

        PlayerRectangle(vec2 top_left, vec2 bottom_right) : Rectangle(top_left, bottom_right) {};
        PlayerRectangle () {}

        void GoLeft();

        void GoRight();


    private:

    };

}  // namespace brickbreaker
