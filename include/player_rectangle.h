#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "rectangle.h"

namespace brickbreaker {

    using glm::vec2;

/**
 * platform that is controlled by the player
 */
    class PlayerRectangle : public Rectangle {
    public:

        PlayerRectangle(vec2 top_left, vec2 bottom_right) : Rectangle(top_left, bottom_right) {};

        PlayerRectangle() {}

    };

}  // namespace brickbreaker
