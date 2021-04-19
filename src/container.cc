#include "container.h"

namespace brickbreaker {

    using glm::vec2;

    Container::Container() {
        ball_ = Ball(vec2(kContainerLeftX, kContainerTopY), vec2(kContainerRightX, kContainerBottomY));
    }

    void Container::Display() {
        ci::gl::color(ci::Color("white"));
        ci::gl::drawStrokedRect(ci::Rectf(vec2(kContainerLeftX, kContainerTopY),
                                          vec2(kContainerRightX, kContainerBottomY)));
        ball_.Draw();

    }

    void Container::Update() {
        ball_.UpdatePosition();

        if (ball_.IsEndGame()) {
            exit(0);
        }
    }

}  // namespace brickbreaker
