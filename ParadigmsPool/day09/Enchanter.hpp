/*
** EPITECH PROJECT, 2023
** day09
** File description:
** reza
*/

#pragma once

#include "Peasant.hpp"

class Enchanter : virtual public Peasant {
    public:
        Enchanter(const std::string &name, int power);
        ~Enchanter();

        int attack() override;
        int special() override;
        void rest() override;
};