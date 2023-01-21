/*
** EPITECH PROJECT, 2023
** day07am
** File description:
** $DESCRIPTION
*/

#include "Borg.hpp"

namespace Borg
{
    class BorgQueen {
        public:
            bool (Borg::Ship::*movePtr) (Destination) = &Borg::Ship::move;
            void (Borg::Ship::*firePtr) (Federation::Starfleet::Ship *) = &Borg::Ship::fire;
            void (Borg::Ship::*destroyPtr) (Federation::Ship *) = &Borg::Ship::fire;

            bool move(Borg::Ship *ship, Destination dest);
            void fire(Borg::Ship *ship, Federation::Starfleet::Ship *target);
            void destroy(Borg::Ship *ship, Federation::Ship *target);
    };
}
