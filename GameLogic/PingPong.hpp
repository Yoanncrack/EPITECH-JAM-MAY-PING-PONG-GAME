/*
** EPITECH PROJECT, 2023
** EPITECH-JAM-MAY-PING-PONG-Pong [WSL: Ubuntu]
** File description:
** Pong
*/

#ifndef Pong_HPP_
    #define Pong_HPP_
    #include <vector>
    #include <iostream>
    #include "../Utils/Utils.hpp"

namespace PONG {
    class Player {
        public:
        Player(int gameSpeed, const Pos &head, const Pos &tail) : m_gameSpeed(gameSpeed),
        m_head(head), m_tail(tail) {
        }
            void movePlayer(DIRECTION dir, int limitDown, Pos &toPop, Pos &toPush, bool &move)
            {
                if (dir == UNKNOWN) {
                    move = false;
                    return;
                }
                toPop = (dir == UP) ? (Pos){m_tail.m_x, m_tail.m_y} : (Pos){m_head.m_x, m_head.m_y};
                toPush = (dir == UP) ? (Pos){m_head.m_x, m_head.m_y - m_gameSpeed} : (Pos){m_tail.m_x, m_tail.m_y + m_gameSpeed};
                if ((toPop.m_y < 20 || toPop.m_y >= limitDown)|| (toPush.m_y < 20 || toPush.m_y >= limitDown)) {
                    move = false;
                    return;
                }
                m_head = (dir == UP) ? (Pos){m_head.m_x, m_head.m_y-m_gameSpeed} : (Pos){m_head.m_x, m_head.m_y+m_gameSpeed};
                m_tail = (dir == UP) ? (Pos){m_tail.m_x, m_tail.m_y-m_gameSpeed} : (Pos){m_tail.m_x, m_tail.m_y+m_gameSpeed} ;
                move = true;
            }
        private:
            int m_gameSpeed;
            Pos m_head;
            Pos m_tail;
    };
    class Pong {
        public:
        Pong(int gameSpeed, const Pos &headOne, const Pos &tailOne, const Pos &headTwo, const Pos &tailTwo, int limitDown) {
            m_gameSpeed = gameSpeed;
            m_p1 = std::make_shared<Player>(gameSpeed, headOne, tailOne);
            m_p2 = std::make_shared<Player>(gameSpeed, headTwo, tailTwo);
            m_limitDown = limitDown;
        }
            void movePlayer(PLAYER player, DIRECTION dir, Pos &toPop, Pos &toPush, bool &move)
            {
                if (player == UNKNOWN_PLAYER || dir == UNKNOWN) {
                    move = false;
                    return;
                }
                if (player == P1) {
                    m_p1->movePlayer(dir, m_limitDown, toPop, toPush, move);
                    return;
                }
                m_p2->movePlayer(dir, m_limitDown, toPop, toPush, move);
            }
            void updateBallPos()
            {

            }
            bool isPongOver()
            {

            }
        private:
            int m_gameSpeed;
            std::shared_ptr<Player> m_p1;
            std::shared_ptr<Player> m_p2;
            int m_limitDown;
    };
}
#endif /* !Pong_HPP_ */
