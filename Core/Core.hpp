/*
** EPITECH PROJECT, 2023
** EPITECH-JAM-MAY-PING-PONG-GAME [WSL: Ubuntu]
** File description:
** Core
*/

#ifndef CORE_HPP_
    #define CORE_HPP_
    #include "../Rendering/Sfml.hpp"
    #include "../GameLogic/PingPong.hpp"
    #include <string>
    #include <memory>
    #include <vector>
    #include <unordered_map>
    #include "../Utils/Utils.hpp"
namespace PONG {
    class Core {
        public:
            Core() {
                m_renderer = std::make_shared<Sfml>();
                Pos p1Head(0, 40);
                Pos p1Tail(0, 100);

                Pos p2Head(780, 40);
                Pos p2Tail(780, 100);

                m_game = std::make_shared<Pong>(20, p1Head, p1Tail, p2Head, p2Tail, 580);
            }
            void run() {
                std::unordered_map<Pos, Color, PosHash> pixels;
                Pos pos(0, 0);
                PONG::Color color(0, 0, 0, 255);
                for (const auto &row : basicMap) {
                    for (const auto &col : row) {
                        color = (col == '0') ? PONG::BLACK : PONG::WHITE;
                        pixels[pos] = color;
                        pos.m_x += 20;
                    }
                    pos.m_x = 0;
                    pos.m_y += 20;
                }
                    m_renderer->SetPixels(pixels);
                    while (m_renderer->windowOpened()) {
                        while (m_renderer->pollEvent()) {
                            PONG::Event evt = m_renderer->getEvent();
                            if (evt.m_EvtType == PONG::EventType::QUIT) {
                                m_renderer->closeWindow();
                                break;
                            }
                            if (evt.m_EvtType == PONG::EventType::KEY_PRESSED) {
                                KEY key = evt.m_KeyCode;
                                if (key == Up) {
                                    Pos toPop(0, 0);
                                    Pos toPush(0, 0);
                                    bool move = false;
                                    m_game->movePlayer(PLAYER::P1, DIRECTION::UP, toPop, toPush, move);
                                    if (move) {
                                        pixels[toPop] = BLACK;
                                        pixels[toPush] = WHITE;
                                        m_renderer->SetPixels(pixels);
                                    }
                                }
                                if (key == Down) {
                                    Pos toPop(0, 0);
                                    Pos toPush(0, 0);
                                    bool move = false;
                                    m_game->movePlayer(PLAYER::P1, DIRECTION::DOWN, toPop, toPush, move);
                                    if (move) {
                                        pixels[toPop] = BLACK;
                                        pixels[toPush] = WHITE;
                                        m_renderer->SetPixels(pixels);
                                    }
                                }
                                if (key == A) {
                                    Pos toPop(0, 0);
                                    Pos toPush(0, 0);
                                    bool move = false;
                                    m_game->movePlayer(PLAYER::P2, DIRECTION::UP, toPop, toPush, move);
                                    if (move) {
                                        pixels[toPop] = BLACK;
                                        pixels[toPush] = WHITE;
                                        m_renderer->SetPixels(pixels);
                                    }
                                }
                                if (key == Q) {
                                    Pos toPop(0, 0);
                                    Pos toPush(0, 0);
                                    bool move = false;
                                    m_game->movePlayer(PLAYER::P2, DIRECTION::DOWN, toPop, toPush, move);
                                    if (move) {
                                        pixels[toPop] = BLACK;
                                        pixels[toPush] = WHITE;
                                        m_renderer->SetPixels(pixels);
                                    }
                                }
                            }
                        }
                        m_renderer->Render();
                    }

            }
            ~Core() = default;
        protected:
        private:
        std::shared_ptr<Renderer> m_renderer;
        std::shared_ptr<Pong> m_game;
    };
}

#endif /* !CORE_HPP_ */
