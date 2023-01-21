/*
** EPITECH PROJECT, 2023
** ex03
** File description:
** $DESCRIPTION
*/

#pragma once

#include <vector>

class Phaser {
    public:
        enum AmmoType {
            REGULAR,
            PLASMA,
            ROCKET
        };
        Phaser(int maxAmmo = 20, AmmoType type = REGULAR);
        ~Phaser();

        void fire();
        void ejectClip();
        void changeType(AmmoType newType);
        void reload();
        void addAmmo(AmmoType type);
        int getCurrentAmmos() const;

    private:
        static const int Empty;
        int maxAmmo;
        AmmoType defaultType;
        std::vector <AmmoType> ammo;
};
