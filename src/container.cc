#include "container.h"

namespace brickbreaker {

    Container::Container() {
        ci::app::setWindowSize(kWindowSize, kWindowSize);
    }

    void Container::Display() {
        ci::Color background_color("black");
        ci::gl::clear(background_color);

        //container_.Display();
    }

    void Container::Update() {
        //container_.AdvanceOneFrame();
    }

}  // namespace brickbreaker
