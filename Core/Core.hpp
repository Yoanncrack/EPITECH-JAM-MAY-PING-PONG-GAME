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

namespace PONG {
    enum MODE {
        COMPUTER,
        VERSUS
    };
    static const std::vector<std::string> basicMap = {
            "1111111111111111111111111111111111111111",
            "00000000000000000000000000000000000000000",
            "1010000000000000000000000000000000000001",
            "1000000000000000000000000000000000000001",
            "1000000000000000000000000000000000000001",
            "1000000000000000000000000000000000000001",
            "0000000000000000000000000000000000000000",
            "0000000000000000000000000000000000000000",
            "0000000000000000000000000000000000000000",
            "0000000000000000000000000000000000000000",
            "0000000000000000000000000000000000000000",
            "0000000000000000000000000000000000000000",
            "0000000000000000000000000000000000000000",
            "0000000000000000000000000000000000000000",
            "0000000000000000000000000000000000000000",
            "0000000000000000000000000000000000000000",
            "0000000000000000000000000000000000000000",
            "0000000000000000000000000000000000000000",
            "0000000000000000000000000000000000000000",
            "0000000000000000000000000000000000000000",
            "0000000000000000000000000000000000000000",
            "0000000000000000000000000000000000000000",
            "0000000000000000000000000000000000000000",
            "0000000000000000000000000000000000000000",
            "0000000000000000000000000000000000000000",
            "0000000000000000000000000000000000000000",
            "0000000000000000000000000000000000000000",
            "0000000000000000000000000000000000000000",
            "0000000000000000000000000000000000000000",
            "1111111111111111111111111111111111111111"
        };
    class Core {
        public:
            explicit Core(std::string arg) {
                gameMode = (arg == "AI") ? COMPUTER : VERSUS;
                m_renderer = std::make_shared<Sfml>();
             //   m_game = std::make_shared<Game>(MODE);
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
                            if (m_renderer->getEvent().m_EvtType == PONG::EventType::QUIT) {
                                m_renderer->closeWindow();
                                break;
                            }
                        }
                        m_renderer->Render();
                    }

            }
            ~Core() = default;
        protected:
        private:
        MODE gameMode;
        std::shared_ptr<Renderer> m_renderer;
        std::shared_ptr<Game> m_pong;
    };
}

#endif /* !CORE_HPP_ */
