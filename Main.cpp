/*
** EPITECH PROJECT, 2023
** EPITECH-JAM-MAY-PING-PONG-GAME [WSL: Ubuntu]
** File description:
** Main
*/

#include "Core/Core.hpp"
#include <string>

int main(int argc, const char **argv)
{
    if (argc != 2)
        return 84;
    PONG::Core game((std::string)argv[1]);
    game.run();
    return 0;
}
