/*
** EPITECH PROJECT, 2023
** rush3
** File description:
** Main.cpp
*/

#include "graphical/Display.hpp"
#include "text/Display.hpp"
#include "Option.hpp"

int main(int argc, char **argv)
{
    std::vector<IMonitorModule *> modules = std::vector<IMonitorModule *>();
    Option::DisplayMode mode = Option::check_options(argc, argv, modules);

    if (mode == Option::TERMINAL) {
        Text::Display t(modules);
        t.displayLoop();
    } else if (mode == Option::GRAPHICAL) {
        Graphical::Display g(modules);
        g.displayLoop();
    }
    return 0;
}
