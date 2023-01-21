/*
** EPITECH PROJECT, 2023
** day07am
** File description:
** $DESCRIPTION
*/

#pragma once

#include <string>
#include "BaseShip.hpp"

namespace Borg
{
    class Ship;
}

namespace Federation
{
    namespace Starfleet
    {
        class Captain {
            public:
                Captain(std::string name);
                std::string getName();
                int getAge();
                void setAge(int age);

            private:
                std::string _name;
                int _age;
        };

        class Ship : public BaseFederationShip {
            public:
                Ship();
                Ship(int length, int width, std::string name, short maxWarp, int torpedo = 0);
                void promote(Captain *captain);
                void setupCore(WarpSystem::Core *core) override;
                void checkCore(void) override;

                int getShield();
                void setShield(int shield);
                int getTorpedo();
                void setTorpedo(int torpedo);
                void fire(Borg::Ship *target);
                void fire(int torpedoes, Borg::Ship *target);
            private:
                Captain *_captain;
                int _photonTorpedo;
                int _shield;
        };

        class Ensign {
            public:
                Ensign(std::string name);

            private:
                std::string _name;
        };
    }
    class Ship : public BaseFederationShip {
        public:
            Ship(int length, int width, std::string name);
            void setupCore(WarpSystem::Core *core) override;
            void checkCore(void) override;
            WarpSystem::Core *getCore();
    };
}
