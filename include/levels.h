#pragma once

#include "brick.h"
#include "player_rectangle.h"

namespace brickbreaker {


/**
 * a class that contains all 5 levels of the brick breaker game
 */
    class Levels {

    public:
        Levels() {};

        std::vector<Brick> LevelOne();

        std::vector<Brick> LevelTwo();

        std::vector<Brick> LevelThree();

        std::vector<Brick> LevelFour();

        std::vector<Brick> LevelFive();

        /**
         * use to pick the level from the container, to change the level
         *
         * @param level that is being chosen
         * @return the bricks of the new level
         */
        std::vector<Brick> PickLevel(int level);

    };

}  // namespace brickbreaker
