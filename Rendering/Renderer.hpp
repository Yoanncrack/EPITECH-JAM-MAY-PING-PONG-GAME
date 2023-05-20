/*
** EPITECH PROJECT, 2023
** EPITECH-JAM-MAY-PING-PONG-GAME [WSL: Ubuntu]
** File description:
** Renderer
*/

#ifndef RENDERER_HPP_
    #define RENDERER_HPP_
    #include <string>
    #include <unordered_map>

namespace PONG {
    enum KEY {
        UP,
        DOWN,
        A,
        Q,
        ESC,
        UNKNOWN_KEY
    };
    
    enum EventType {
        KEY_PRESSED,
        MOUSE_CLICK,
        QUIT,
        UNKNOWN_EVENT
    };
    
    struct Event {
        EventType m_EvtType;
        KEY m_KeyCode;
        Event(EventType evt, KEY key) : m_EvtType(evt), m_KeyCode(key) {}
    };
    
        struct Pos {
        Pos(float x, float y) : m_x(x), m_y(y){}
        bool operator ==(const Pos &other) const {
            return (m_x==other.m_x) && (m_y==other.m_y);
        }
        float m_x, m_y;
    };

    struct PosHash {
        std::size_t operator()(const Pos &other) const {
            std::size_t h1 = std::hash<float>()(other.m_x);
            std::size_t h2 = std::hash<float>()(other.m_y);
            return h1 ^ h2;
        }
    };
    
    struct Color {
        Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) : m_r(r), m_g(g), m_b(b), m_a(a) {}
        uint8_t m_r, m_g, m_b, m_a;
        Color() = default;
    };

    const Color &BLACK = Color(0, 0, 0, 255);
    const Color &WHITE = Color(255, 255, 255, 255);
    class Renderer {
        public:
            virtual bool windowOpened() = 0;
            virtual void SetPixels(const std::unordered_map<Pos, Color, PosHash>&) = 0;
            virtual void Render() = 0;
            virtual bool pollEvent() = 0;
            virtual Event getEvent() = 0;
            virtual void closeWindow() = 0;
        };
}
#endif /* !RENDERER_HPP_ */
