#include "levels.h"

namespace brickbreaker {

    std::vector<Brick> Levels::LevelOne() {
        std::vector<Brick> bricks;
        float left_container_x = 0;
        float bottom_container_y = 1000;
        int size_of_rectangle = 100;
        int number_of_rows = 3;
        int number_of_columns = 10;


        int increment_column = 0;
        while (bricks.size() != number_of_rows * number_of_columns) {
            float row_size = bottom_container_y / number_of_rows - size_of_rectangle;
            for (int increment_row = (int) left_container_x;
                 increment_row < (int) row_size; increment_row += size_of_rectangle) {
                Brick brick(vec2(increment_column, increment_row),
                            vec2(increment_column + size_of_rectangle,
                                 increment_row + size_of_rectangle));
                bricks.push_back(brick);
            }
            increment_column += (int) size_of_rectangle;
        }
        return bricks;
    }

    std::vector<Brick> Levels::LevelTwo() {
        std::vector<Brick> bricks;

        float left_container_x = 0;
        float bottom_container_y = 1000;
        int size_of_rectangle = 100;
        int number_of_rows = 3;
        int number_of_columns = 5;


        int increment_column = 0;
        while (bricks.size() != number_of_rows * number_of_columns) {
            float row_size = bottom_container_y / number_of_rows - size_of_rectangle;
            for (int increment_row = (int) left_container_x;
                 increment_row < (int) row_size; increment_row += size_of_rectangle) {
                Brick brick(vec2(increment_column, increment_row),
                            vec2(increment_column + size_of_rectangle,
                                 increment_row + size_of_rectangle));
                bricks.push_back(brick);
            }
            increment_column += (int) size_of_rectangle;
        }
        return bricks;
    }

    std::vector<Brick> Levels::LevelThree() {
        std::vector<Brick> bricks;

        float left_container_x = 0;
        float bottom_container_y = 1000;
        int size_of_rectangle = 100;
        int number_of_rows = 4;
        int number_of_columns = 10;


        int increment_column = 0;
        while (bricks.size() != number_of_rows * number_of_columns) {
            float row_size = bottom_container_y / number_of_rows - size_of_rectangle;
            for (int increment_row = (int) left_container_x;
                 increment_row < (int) row_size; increment_row += size_of_rectangle) {
                Brick brick(vec2(increment_column, increment_row),
                            vec2(increment_column + size_of_rectangle,
                                 increment_row + size_of_rectangle));
                bricks.push_back(brick);
            }
            increment_column += (int) size_of_rectangle;
        }
        return bricks;
    }

    std::vector<Brick> Levels::LevelFour() {
        std::vector<Brick> bricks;

        float left_container_x = 0;
        float bottom_container_y = 1000;
        int size_of_rectangle = 100;
        int number_of_rows = 4;
        int number_of_columns = 5;


        int increment_column = 0;
        while (bricks.size() != number_of_rows * number_of_columns) {
            float row_size = bottom_container_y / number_of_rows - size_of_rectangle;
            for (int increment_row = (int) left_container_x;
                 increment_row < (int) row_size; increment_row += size_of_rectangle) {
                Brick brick(vec2(increment_column, increment_row),
                            vec2(increment_column + size_of_rectangle,
                                 increment_row + size_of_rectangle));
                bricks.push_back(brick);
            }
            increment_column += (int) size_of_rectangle;
        }
        return bricks;
    }

    std::vector<Brick> Levels::LevelFive() {
        std::vector<Brick> bricks;

        float left_container_x = 0;
        float bottom_container_y = 1000;
        int size_of_rectangle = 100;
        int number_of_rows = 4;
        int number_of_columns = 3;


        int increment_column = 0;
        while (bricks.size() != number_of_rows * number_of_columns) {
            float row_size = bottom_container_y / number_of_rows - size_of_rectangle;
            for (int increment_row = (int) left_container_x;
                 increment_row < (int) row_size; increment_row += size_of_rectangle) {
                Brick brick(vec2(increment_column, increment_row),
                            vec2(increment_column + size_of_rectangle,
                                 increment_row + size_of_rectangle));
                bricks.push_back(brick);
            }
            increment_column += (int) size_of_rectangle;
        }
        return bricks;
    }

    std::vector<Brick> Levels::PickLevel(int level) {
        if (level == 1) {
            return LevelOne();
        } else if (level == 2) {
            return LevelTwo();
        } else if (level == 3) {
            return LevelThree();
        } else if (level == 4) {
            return LevelFour();
        } else if (level == 5) {
            return LevelFive();
        } else {
            throw std::invalid_argument("no level has been created");
        }
    }

}  // namespace brickbreaker
