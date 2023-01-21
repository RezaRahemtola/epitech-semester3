/*
** EPITECH PROJECT, 2023
** day07am
** File description:
** $DESCRIPTION
*/

#pragma once

#include <string>
#include "Destination.hpp"
#include "WarpSystem.hpp"

class BaseShip {
    public:
        // BaseShip(); // Starfleet default
        BaseShip(short maxWarp, Destination home); // Borgs

        virtual void setupCore(WarpSystem::Core *core) = 0;
        virtual void checkCore(void) = 0;

        bool move(int warp, Destination d);
        bool move(int warp);
        bool move(Destination d);
        bool move();

    protected:
        short _maxWarp;
        Destination _home;
        Destination _location;
        WarpSystem::Core *_core = nullptr;
};

class BaseFederationShip : public BaseShip {
    public:
        BaseFederationShip(int length, int width, std::string name, int maxWarp, Destination home);

    protected:
        int _length;
        int _width;
        std::string _name;
};
