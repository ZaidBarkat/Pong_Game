#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "container.h"

namespace brickbreaker {

/**
 * An app for visualizing the behavior of an ideal gas.
 */
    class BrickBreakerApp : public ci::app::App {
    public:
        BrickBreakerApp();

        void draw() override;
        void update() override;

        // provided that you can see the entire UI on your screen.
        const int kWindowSize = 1000;
        const int kMargin = 100;

    private:
        Container container_;

    };

}  // namespace brickbreaker
