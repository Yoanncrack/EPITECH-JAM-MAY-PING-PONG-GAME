/*
** EPITECH PROJECT, 2023
** EPITECH-JAM-MAY-PING-PONG-GAME [WSL: Ubuntu]
** File description:
** Sfml
*/

#ifndef SFML_HPP_
    #define SFML_HPP_
    #include "Renderer.hpp"
    #include <SFML/Graphics.hpp>
    #include <memory>
namespace PONG {
    class Sfml : public Renderer {
        public:
            Sfml() {
                m_window = std::make_shared<sf::RenderWindow>(sf::VideoMode(800, 600), "2D PING PONG");
                m_windowOpened = true;
            }
            bool windowOpened()  {
                return m_windowOpened;
            }
            //Bah vu que la librairie sfml est une lib multimédia, \
            on va afficher des carrés de taille 20*20 pour imiter des pixels 
            void SetPixels(const std::unordered_map<Pos, Color, PosHash> &image) {
                m_pixels.clear();
                for (const auto &s_pixel : image) {
                    sf::RectangleShape pixel;
                    pixel.setSize({20.0f, 20.0f});
                    sf::Color converted = sf::Color(s_pixel.second.m_r, s_pixel.second.m_g, s_pixel.second.m_b, s_pixel.second.m_a);
                    pixel.setFillColor(converted);
                    pixel.setOutlineColor(converted);
                    pixel.setPosition({s_pixel.first.m_x, s_pixel.first.m_y});
                    m_pixels.push_back(pixel);
                }
            }
            void Render() {
                m_window->clear();
                for (const auto &pixel : m_pixels) {
                    m_window->draw(pixel);
                }
                m_window->display();
            }
            bool pollEvent() {
                return m_window->pollEvent(m_event);
            }
            Event getEvent() {
                if (m_event.type == sf::Event::KeyPressed) {
                    if (m_event.key.code == sf::Keyboard::Up) return Event(EventType::KEY_PRESSED, KEY::UP);
                    if (m_event.key.code == sf::Keyboard::Down) return Event(EventType::KEY_PRESSED, KEY::UP);
                    if (m_event.key.code == sf::Keyboard::A) return Event(EventType::KEY_PRESSED, KEY::A);
                    if (m_event.key.code == sf::Keyboard::Q) return Event(EventType::KEY_PRESSED, KEY::Q);
                    if (m_event.key.code == sf::Keyboard::Escape) return Event(EventType::KEY_PRESSED, KEY::ESC);
                    return Event(EventType::KEY_PRESSED, KEY::UNKNOWN_KEY);
                }
                if (m_event.type == sf::Event::Closed) return Event(EventType::QUIT, KEY::UNKNOWN_KEY);
                return Event(EventType::UNKNOWN_EVENT, KEY::UNKNOWN_KEY);
            }
            void closeWindow() {
                m_window->close();
                m_windowOpened = false;
            }
            ~Sfml() = default;
        private:
            std::shared_ptr<sf::RenderWindow> m_window;
            bool m_windowOpened;
            sf::Event m_event;
            std::vector<sf::RectangleShape> m_pixels;
    };
}

#endif /* !SFML_HPP_ */
