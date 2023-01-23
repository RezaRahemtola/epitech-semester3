/*
** EPITECH PROJECT, 2023
** day09
** File description:
** reza
*/

#pragma once

#include "Enchanter.hpp"

class Priest : public Enchanter {
    public:
        Priest(const std::string &name, int power);
        ~Priest();

        void rest() override;
};