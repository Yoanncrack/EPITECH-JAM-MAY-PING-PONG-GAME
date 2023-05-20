/*
** EPITECH PROJECT, 2023
** EPITECH-JAM-MAY-PING-PONG-GAME [WSL: Ubuntu]
** File description:
** Game
*/

#ifndef GAME_HPP_
#define GAME_HPP_

namespace PONG {
    class Game {
        enum DIRECTION {
            UP,
            DOWN
        };
        enum PLAYER {
            P1,
            P2
        };
        public:
            virtual void movePlayer(PLAYER, DIRECTION) = 0;
            virtual void updateBallPos();
            virtual bool isGameOver();
            virtual ~Game() = 0;
    };
}
#endif /* !GAME_HPP_ */
