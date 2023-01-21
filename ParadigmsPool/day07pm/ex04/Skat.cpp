/*
** EPITECH PROJECT, 2023
** day07pm
** File description:
** $DESCRIPTION
*/

#include <iostream>
#include "KreogCom.hpp"
#include "Skat.hpp"

Skat::Skat(const std::string &name, int stimPaks, int serial, int x, int y, Phaser::AmmoType type) : _name(name), _nb_stimpaks(stimPaks), kreog(new KreogCom(x, y, serial)), phaser(new Phaser(20, type))
{
}

Skat::~Skat()
{
    delete this->kreog;
    delete this->phaser;
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

void Skat::fire() const
{
    this->phaser->fire();
}

void Skat::locate() const
{
    this->kreog->ping();
}

void Skat::reload() const
{
    this->phaser->reload();
}

KreogCom &Skat::com() const
{
    return *this->kreog;
}
