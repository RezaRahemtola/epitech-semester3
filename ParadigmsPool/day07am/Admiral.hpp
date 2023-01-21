/*
** EPITECH PROJECT, 2023
** day07am
** File description:
** $DESCRIPTION
*/

#include <string>
#include "Federation.hpp"
#include "Borg.hpp"

namespace Federation
{
    namespace Starfleet
    {
        class Admiral {
            public:
                Admiral(std::string name);

                bool move(Federation::Starfleet::Ship *ship, Destination dest);
                void fire(Federation::Starfleet::Ship *ship, Borg::Ship *target);

                bool (Federation::Starfleet::Ship::*movePtr) (Destination) = &Federation::Starfleet::Ship::move;
                void (Federation::Starfleet::Ship::*firePtr) (Borg::Ship *) = &Federation::Starfleet::Ship::fire;

            private:
                std::string _name;
        };
    }
}
