/*
** EPITECH PROJECT, 2023
** day09
** File description:
** reza
*/

#pragma once

#include <iostream>

class IPotion {
    public:
        virtual int getHp() const = 0;
        virtual int getPower() const = 0;
};