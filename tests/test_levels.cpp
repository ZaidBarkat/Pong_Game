
#include <catch2/catch.hpp>
#include <levels.h>

using glm::vec2;

TEST_CASE("Level Tests") {
    brickbreaker::Levels level;

    SECTION("test all levels") {

        SECTION("level 1") {
            std::vector<brickbreaker::Brick> bricks = level.LevelOne();
            REQUIRE(bricks.size() == 30);
        }
        SECTION("level 2") {
            std::vector<brickbreaker::Brick> bricks = level.LevelTwo();
            REQUIRE(bricks.size() == 15);
        }
        SECTION("level 3") {
            std::vector<brickbreaker::Brick> bricks = level.LevelThree();
            REQUIRE(bricks.size() == 40);
        }
        SECTION("level 4") {
            std::vector<brickbreaker::Brick> bricks = level.LevelFour();
            REQUIRE(bricks.size() == 20);
        }
        SECTION("level 5") {
            std::vector<brickbreaker::Brick> bricks = level.LevelFive();
            REQUIRE(bricks.size() == 12);
        }
    }
}
