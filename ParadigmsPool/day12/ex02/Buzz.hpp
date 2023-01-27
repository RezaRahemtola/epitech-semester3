/*
** EPITECH PROJECT, 2023
** day12
** File description:
** Buzz
*/

#pragma once

#include "Toy.hpp"

class Buzz : public Toy {
    public:
        Buzz() = delete;
        explicit Buzz(const std::string &name, const std::string &ascii = "buzz.txt");
};