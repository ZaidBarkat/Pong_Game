#include <computer_player.h>
#include "brick_breaker_app.h"

namespace brickbreaker {

    BrickBreakerApp::BrickBreakerApp() {
        ci::app::setWindowSize(kWindowSize, kWindowSize);
    }

    void BrickBreakerApp::draw() {
        ci::Color background_color("black");
        ci::gl::clear(background_color);

        container_.Display();
    }

    void BrickBreakerApp::update() {
        container_.Update();
    }

    void BrickBreakerApp::keyDown(ci::app::KeyEvent event) {
        switch (event.getCode()) {
            case ci::app::KeyEvent::KEY_RIGHT:
                container_.PlayerRight();
                break;

            case ci::app::KeyEvent::KEY_LEFT:
                container_.PlayerLeft();
                break;

            case ci::app::KeyEvent::KEY_a:
                container_.ComputerPlayer();
                break;
        }
    }
}  // namespace brickbreaker
