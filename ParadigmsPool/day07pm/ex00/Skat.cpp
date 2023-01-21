/*
** EPITECH PROJECT, 2023
** day07pm
** File description:
** $DESCRIPTION
*/

#include <iostream>
#include "Skat.hpp"

Skat::Skat(const std::string &name, int stimPaks) : _name(name), _nb_stimpaks(stimPaks)
{
}

Skat::~Skat()
{
}

int &Skat::stimPaks()
{
    return _nb_stimpaks;
}

const std::string &Skat::name()
{
    return _name;
}

void Skat::shareStimPaks(int number, int &stock)
{
    if (number > this->_nb_stimpaks) {
        std::cout << "Don't be greedy" << std::endl;
        return;
    }
    std::cout << "Keep the change." << std::endl;
    stock += number;
    this->_nb_stimpaks -= number;
}

void Skat::addStimPaks(unsigned int number)
{
    if (number == 0)
        std::cout << "Hey boya, did you forget something?" << std::endl;
    _nb_stimpaks += number;
}

void Skat::useStimPaks()
{
    if (_nb_stimpaks == 0) {
        std::cout << "Mediiiiiic" << std::endl;
    } else {
        _nb_stimpaks -= 1;
        std::cout << "Time to kick some ass and chew bubble gum." << std::endl;
    }
}

void Skat::status() const
{
    std::cout << "Soldier " << _name
              << " reporting " << _nb_stimpaks << " stimpaks remaining sir!"
              << std::endl;
}
