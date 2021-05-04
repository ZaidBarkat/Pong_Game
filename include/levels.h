#pragma once

#include "brick.h"
#include "player_rectangle.h"

namespace brickbreaker {


/**
 * An container for the Brick Breaker game.
 */
    class Levels {

    public:
        Levels() {};

        std::vector<Brick> LevelOne();

        std::vector<Brick> LevelTwo();

        std::vector<Brick> LevelThree();

        std::vector<Brick> LevelFour();

        std::vector<Brick> LevelFive();

        std::vector<Brick> PickLevel();

        void SetLevel(int level);

    private:
        int level_;

        std::vector<Ball> balls_;
    };

}  // namespace brickbreaker
