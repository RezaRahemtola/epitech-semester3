/*
** EPITECH PROJECT, 2023
** day07pm
** File description:
** $DESCRIPTION
*/

#pragma once

#include <string>

class Skat {
    public:
        Skat(const std::string &name = "bob", int stimPaks = 15);
        ~Skat();
        int &stimPaks();

        const std::string &name();
        void shareStimPaks(int number, int &stock);
        void addStimPaks(unsigned int number);
        void useStimPaks();
        void status() const;

    private:
        const std::string _name;
        int _nb_stimpaks;
};
