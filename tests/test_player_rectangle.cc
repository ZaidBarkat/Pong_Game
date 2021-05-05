
#include <catch2/catch.hpp>
#include <player_rectangle.h>

using glm::vec2;

TEST_CASE("Player Tests") {
    SECTION("test Rectangle Update") {

        brickbreaker::Ball ball(vec2(1000, 1000), vec2(2, 2));

        SECTION("test colliding with rectangle") {

            SECTION("test colliding with bottom line") {
                brickbreaker::PlayerRectangle player(vec2(500, 500), vec2(600, 492));

                player.Update(ball);
                REQUIRE(ball.GetVelocity().y == -2);
            }
            SECTION("test colliding with top line") {
                brickbreaker::PlayerRectangle player(vec2(500, 508), vec2(600, 600));

                player.Update(ball);
                REQUIRE(ball.GetVelocity().y == 2);
            }
            SECTION("test colliding with right line") {
                brickbreaker::PlayerRectangle player(vec2(500, 500), vec2(492, 500));

                player.Update(ball);
                REQUIRE(ball.GetVelocity().x == 2);
            }
            SECTION("test colliding with left line") {
                brickbreaker::PlayerRectangle player(vec2(508, 500), vec2(500, 500));

                player.Update(ball);
                REQUIRE(ball.GetVelocity().y == -2);
            }
        }

        }
    }
