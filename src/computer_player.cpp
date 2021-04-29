#include <container.h>
#include "computer_player.h"

namespace brickbreaker {

    void ComputerPlayer::SetComputerMovement(Container &container) {
        std::vector<Ball> balls = container.GetBalls();
        PlayerRectangle player_rectangle = container.GetPlayerRectangle();
    }



}  // namespace brickbreaker
