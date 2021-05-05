#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "container.h"
#include "levels.h"

namespace brickbreaker {

/**
 * An app for visualizing the behavior of an brick breaker game.
 */
    class BrickBreakerApp : public ci::app::App {
    public:
        BrickBreakerApp();

        void draw() override;

        void update() override;

        /**
         * checking if the key is being pressed down, moves the player
         *
         * @param event
         */
        void keyDown(ci::app::KeyEvent event) override;

        // provided that you can see the entire UI on your screen.
        const int kWindowSize = 1000;
        const int kMargin = 100;

    private:
        Container container_;

        int level_number_ = 1;
        Levels level_;

    };

}  // namespace brickbreaker
