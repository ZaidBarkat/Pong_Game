#include <computer_player.h>
#include <levels.h>
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

            case ci::app::KeyEvent::KEY_q:
                level_.SetLevel(--level_number_);
                container_.SetBricks(level_.PickLevel());
                container_.Reset();
                break;

            case ci::app::KeyEvent::KEY_e:
                level_.SetLevel(++level_number_);
                container_.SetBricks(level_.PickLevel());
                container_.Reset();
                break;

            case ci::app::KeyEvent::KEY_a:
                ComputerPlayer player;
                std::string direction = player.ComputerMovement(container_);

                if (direction == "left") {
                    container_.PlayerLeft();
                } else if (direction == "right") {
                    container_.PlayerRight();
                }

                break;
        }
    }
}  // namespace brickbreaker
