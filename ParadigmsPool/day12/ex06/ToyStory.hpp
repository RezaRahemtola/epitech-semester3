/*
** EPITECH PROJECT, 2023
** day12
** File description:
** ToyStory
*/

#pragma once

#include "Toy.hpp"

class ToyStory {
    public:
        static void
        tellMeAStory(
                const std::string &file,
                Toy &toy1, bool (Toy::*func1)(const std::string &),
                Toy &toy2, bool (Toy::*func2)(const std::string &));
};