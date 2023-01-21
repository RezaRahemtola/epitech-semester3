/*
** EPITECH PROJECT, 2023
** day07pm
** File description:
** $DESCRIPTION
*/

#pragma once

#include <string>
#include "KreogCom.hpp"
#include "Phaser.hpp"

class Skat {
    public:
        Skat(const std::string &name, int stimPaks, int serial, int x, int y, Phaser::AmmoType type);
        ~Skat();
        int &stimPaks();

        const std::string &name();
        void shareStimPaks(int number, int &stock);
        void addStimPaks(unsigned int number);
        void useStimPaks();
        void status() const;

        void fire() const;
        void locate() const;
        void reload() const;
        KreogCom &com() const;
    private:
        const std::string _name;
        int _nb_stimpaks;
        KreogCom *kreog;
        Phaser *phaser;
};
