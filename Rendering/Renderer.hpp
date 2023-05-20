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
        UNKNOWN
    };
    
    enum EventType {
        KEY_PRESSED,
        MOUSE_CLICK,
        UNKNOWN
    };
    
    typedef struct Event {
        EventType m_EvtType;
        KEY m_KeyCode;
        Event(EventType evt, KEY key) : m_EvtType(evt), m_KeyCode(key) {}
    }Event;
    
    typedef struct Pos {
        Pos(double x, double y) : m_x(x), m_y(y){}
        double m_x, m_y;
    }Pos;
    
    typedef struct Color {
        Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) : m_r(r), m_g(g), m_b(b), m_a(a) {}
        uint8_t m_r, m_g, m_b, m_a;
    }Color;

    const Color &BLACK = Color(0, 0, 0, 255);
    const Color &WHITE = Color(255, 255, 255, 255);
    class Renderer {
        public:
            virtual bool windowOpened() = 0;
            virtual void SetPixels(std::unordered_map<Color, Pos>) = 0;
            virtual void Render();
            virtual bool pollEvent() = 0;
            virtual Event getEvent() = 0;
            virtual void closeWindow() = 0;
            virtual ~Renderer() = 0;
    };
}
#endif /* !RENDERER_HPP_ */
