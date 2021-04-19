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

}  // namespace brickbreaker
