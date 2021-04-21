
#include <catch2/catch.hpp>
#include <player_rectangle.h>

using glm::vec2;

TEST_CASE("Player Tests") {
    brickbreaker::PlayerRectangle player(vec2(500, 500), vec2(600, 600));

    SECTION("test Rectangle movement") {

        SECTION("test Rectangle moves left") {
            player.GoLeft();

            SECTION("top left x coordinate") {
                REQUIRE(player.GetRectangleTopLeft().x == Approx(490));
            }
            SECTION("bottom right x coordinate") {
                REQUIRE(player.GetRectangleBottomRight().x == Approx(590));
            }
        }
        SECTION("test Rectangle moves right") {
            player.GoRight();

            SECTION("top left x coordinate") {
                REQUIRE(player.GetRectangleTopLeft().x == Approx(510));
            }
            SECTION("bottom right x coordinate") {
                REQUIRE(player.GetRectangleBottomRight().x == Approx(610));
            }
        }
    }
}
