/*
** EPITECH PROJECT, 2023
** day12
** File description:
** Woody
*/

#pragma once

#include "Toy.hpp"

class Woody : public Toy {
    public:
        Woody() = delete;
        explicit Woody(const std::string &name, const std::string &ascii = "woody.txt");
        void speak(const std::string &message) override;
};