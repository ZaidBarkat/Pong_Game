#include <container.h>
#include "computer_player.h"

namespace brickbreaker {

    std::string ComputerPlayer::ComputerMovement(Container &container) {
        std::vector<Ball> balls = container.GetBalls();
        PlayerRectangle player_rectangle = container.GetPlayerRectangle();

        float min_y = balls[0].GetPosition().y;
        float min_x = 0;
        for (const Ball &ball : balls) {
            if (min_y <= ball.GetPosition().y && ball.GetVelocity().y > 0) {
                min_y = ball.GetPosition().y;
                min_x = ball.GetPosition().x;
            }
        }

        if (min_x <= player_rectangle.GetRectangleTopLeft().x) {
            return "left";
        } else if (min_x > player_rectangle.GetRectangleBottomRight().x) {
            return "right";
        }

        return "No closest ball";
    }


}  // namespace brickbreaker
