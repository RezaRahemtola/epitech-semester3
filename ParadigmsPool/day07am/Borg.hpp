/*
** EPITECH PROJECT, 2023
** day07am
** File description:
** $DESCRIPTION
*/

#pragma once

#include "BaseShip.hpp"

namespace Federation
{
    namespace Starfleet
    {
        class Ship;
    }
    class Ship;
}

namespace Borg
{
    class Ship : public BaseShip {
        public:
            Ship(int weaponFrequency = 20, short repair = 3);

            void setupCore(WarpSystem::Core *core) override;
            void checkCore(void) override;

            int getShield();
            void setShield(int shield);
            int getWeaponFrequency();
            void setWeaponFrequency(int frequency);
            short getRepair();
            void setRepair(short repair);

            void fire(Federation::Starfleet::Ship *target);
            void fire (Federation::Ship *target);
            void repair();

        private:
            int _side;
            int _weaponFrequency;
            short _repair;
            int _shield;
    };
}
