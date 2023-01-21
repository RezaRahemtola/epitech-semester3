/*
** EPITECH PROJECT, 2023
** day07am
** File description:
** $DESCRIPTION
*/

#include <iostream>
#include "Exam.hpp"

bool Exam::cheat = false;

Exam::Exam(bool *ptr)
{
    this->cheat = *ptr;
}

bool Exam::isCheating()
{
    return this->cheat;
}

void Exam::start(int vessels)
{
    std::cout << "[The exam is starting]" << std::endl;
    std::cout << vessels << " Klingon vessels appeared out of nowhere." << std::endl;
    std::cout << "they are fully armed and shielded" << std::endl;

    if (this->isCheating()) {
        std::cout << "What the... someone changed the parameters of the exam !" << std::endl;
    } else {
        std::cout << "This exam is hard... you lost again." << std::endl;
    }
}
