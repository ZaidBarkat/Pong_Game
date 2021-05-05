
#include <catch2/catch.hpp>
#include <brick.h>

using glm::vec2;

TEST_CASE("Brick Tests") {
    SECTION("test Brick Update") {

        brickbreaker::Ball ball(vec2(1000, 1000), vec2(2, 2));

        SECTION("test colliding with rectangle") {

            SECTION("test colliding with bottom line") {
                brickbreaker::Brick brick(vec2(500, 500), vec2(600, 492));

                brick.Update(ball);

                SECTION("test ishidden function") {
                    REQUIRE(brick.IsHidden());
                }

                REQUIRE(ball.GetVelocity().y == -2);
            }
            SECTION("test colliding with top line") {
                brickbreaker::Brick brick(vec2(500, 508), vec2(600, 600));

                brick.Update(ball);

                SECTION("test ishidden function") {
                    REQUIRE(brick.IsHidden());
                }

                REQUIRE(ball.GetVelocity().y == 2);
            }
            SECTION("test colliding with right line") {
                brickbreaker::Brick brick(vec2(500, 500), vec2(492, 500));

                brick.Update(ball);

                SECTION("test ishidden function") {
                    REQUIRE(brick.IsHidden());
                }

                REQUIRE(ball.GetVelocity().x == 2);
            }
            SECTION("test colliding with left line") {
                brickbreaker::Brick brick(vec2(508, 500), vec2(500, 500));

                brick.Update(ball);

                SECTION("test ishidden function") {
                    REQUIRE(brick.IsHidden());
                }

                REQUIRE(ball.GetVelocity().y == -2);
            }
        }

    }
}
