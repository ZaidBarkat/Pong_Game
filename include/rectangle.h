#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "ball.h"

namespace brickbreaker {

    using glm::vec2;

/**
 * Creation of bricks and platform
 */
    class Rectangle {
    public:
        Rectangle(vec2 top_left, vec2 bottom_right);

        Rectangle();

        virtual void Draw();

        virtual void Update(Ball &ball);

        const vec2 &GetRectangleTopLeft() const;

        const vec2 &GetRectangleBottomRight() const;

        void SetRectangleTopLeftX(const float &rectangleTopLeftX);

        void SetRectangleBottomRightX(const float &rectangleBottomRightX);


    protected:
        vec2 rectangle_top_left_;
        vec2 rectangle_bottom_right_;
    };

}  // namespace brickbreaker
