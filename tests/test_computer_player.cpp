
#include <catch2/catch.hpp>
#include <container.h>
#include <computer_player.h>

using glm::vec2;

TEST_CASE("Computer Tests") {
    brickbreaker::Container container;
    brickbreaker::ComputerPlayer computer;

    SECTION("test computer answers") {

        SECTION("test no movement") {
            computer.ComputerMovement(container);
            REQUIRE(computer.ComputerMovement(container) == "No closest ball");
        }
        SECTION("test movement left") {
            container.SetPlayerRectangle(brickbreaker::PlayerRectangle(vec2(1000, 1000),
                                                                       vec2(1100, 1100)));
            REQUIRE(computer.ComputerMovement(container) == "left");
        }
        SECTION("test movement right") {
            container.SetPlayerRectangle(brickbreaker::PlayerRectangle(vec2(0, 1000),
                                                                       vec2(100, 1100)));
            REQUIRE(computer.ComputerMovement(container) == "right");
        }
    }
}
