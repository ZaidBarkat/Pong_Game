#include "container.h"

namespace brickbreaker {

    using glm::vec2;

    Container::Container() {

    }

    void Container::Display() {
        ci::gl::color(ci::Color("white"));
        ci::gl::drawStrokedRect(ci::Rectf(vec2(kContainerLeftX, kContainerTopY),
                                          vec2(kContainerRightX, kContainerBottomY)));

    }

    void Container::Update() {

    }

}  // namespace brickbreaker
