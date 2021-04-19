#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

namespace brickbreaker {

    using glm::vec2;

/**
 * An container for the Brick Breaker game.
 */
    class Rectangle {
    public:
        Rectangle(vec2 top_left, vec2 bottom_right);

        Rectangle();

        void Draw();

        void Update();


    protected:
        vec2 rectangle_top_left_;
        vec2 rectangle_bottom_right_;
    };

}  // namespace brickbreaker
