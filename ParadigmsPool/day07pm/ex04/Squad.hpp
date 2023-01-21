/*
** EPITECH PROJECT, 2023
** ex04
** File description:
** $DESCRIPTION
*/

#pragma once

#include <vector>
#include "Phaser.hpp"
#include "Skat.hpp"

class Squad {
    public:
        Squad(int posXBegin, int posYBegin, Phaser::AmmoType ammoType, int size = 5);
        ~Squad();
        void fire() const;
        void localisation() const;
        Skat **skats() const;
        Skat *at(int idx) const;
        int size() const;
    private:
        Skat **_skats;
};

void foreach(Skat **beginIdx, void (Skat::*actionPtr)() const);
