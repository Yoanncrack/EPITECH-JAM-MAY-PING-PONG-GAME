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
    #include "../Utils/Utils.hpp"

namespace PONG {
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
