/*
** EPITECH PROJECT, 2023
** EPITECH-JAM-MAY-PING-PONG-GAME [WSL: Ubuntu]
** File description:
** Utils
*/

#ifndef UTILS_HPP_
    #define UTILS_HPP_
    #include <string>
    #include <vector>
namespace PONG {
    enum KEY {
        Up,
        Down,
        A,
        Q,
        ESC,
        UNKNOWN_KEY
    };
    enum DIRECTION {
            UP,
            DOWN,
            UNKNOWN
        };
    
    enum EventType {
        KEY_PRESSED,
        MOUSE_CLICK,
        QUIT,
        UNKNOWN_EVENT
    };
    enum PLAYER{
        P1,
        P2,
        UNKNOWN_PLAYER
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
    enum MODE {
        COMPUTER,
        VERSUS
    };
    static const std::vector<std::string> basicMap = {
            "1111111111111111111111111111111111111111",
            "0000000000000000000000000000000000000000",
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
}

#endif /* !UTILS_HPP_ */
