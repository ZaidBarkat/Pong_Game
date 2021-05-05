
#include <catch2/catch.hpp>
#include <ball.h>

using glm::vec2;

TEST_CASE("Ball Tests") {
    brickbreaker::Ball ball(vec2(0, 0), vec2(1000, 1000));

    SECTION("test colliding with wall") {

        SECTION("test colliding with bottom wall") {
            ball.CollidesWithWall(vec2(400, 500), vec2(510, 500));
            REQUIRE(ball.GetVelocity() == vec2(2, 2));
        }
        SECTION("test colliding with top wall") {
            ball.CollidesWithWall(vec2(400, 490), vec2(510, 600));
            REQUIRE(ball.GetVelocity() == vec2(2, -2));
        }
        SECTION("test colliding with right wall") {
            ball.CollidesWithWall(vec2(500, 400), vec2(600, 500));
            REQUIRE(ball.GetVelocity() == vec2(-2, -2));
        }
        SECTION("test colliding with left wall") {
            ball.CollidesWithWall(vec2(300, 200), vec2(500, 300));
            REQUIRE(ball.GetVelocity() == vec2(-2, -2));
        }
    }

    SECTION("test updating position") {
        ball.UpdatePosition();
        REQUIRE(ball.GetPosition() == vec2(502, 498));
    }

    SECTION("test end game condition") {
        ball.SetPosition(vec2(500, 1000));
        REQUIRE(ball.IsEndGame());
    }
}
