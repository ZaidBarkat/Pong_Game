#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "rectangle.h"

namespace brickbreaker {

    using glm::vec2;

/**
 * A container for the Brick Breaker game.
 */
    class Brick : public Rectangle {
    public:

        Brick(vec2 top_left, vec2 bottom_right) : Rectangle(top_left, bottom_right) {};

        Brick() {}

        void Draw() override;

        void Update(Ball &ball) override;

        bool IsHidden() const;

    private:
        bool is_hidden = false;

    };

}  // namespace brickbreaker
