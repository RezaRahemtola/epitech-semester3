/*
** EPITECH PROJECT, 2023
** ex02
** File description:
** $DESCRIPTION
*/

#include <iostream>
#include "KreogCom.hpp"

KreogCom::KreogCom(int x, int y, int serial) : x(x), y(y), m_serial(serial)
{
    std::cout << "KreogCom " << serial << " initialized" << std::endl;
}

KreogCom::~KreogCom()
{
    std::cout << "KreogCom " << this->m_serial << " shutting down" << std::endl;

    if (this->prev)
        this->prev->next = this->next;
    if (this->next)
        this->next->prev = this->prev;
}

void KreogCom::addCom(int x, int y, int serial)
{
    KreogCom *newCom = new KreogCom(x, y, serial);
    KreogCom *currentNext = this->next;

    this->next = newCom;
    this->next->prev = this;
    if (currentNext != nullptr) {
        currentNext->prev = newCom;
        newCom->next = currentNext;
    }
}

void KreogCom::addCom(KreogCom *com)
{
    KreogCom *currentNext = this->next;

    this->next = com;
    com->prev = this;
    if (currentNext != nullptr) {
        currentNext->prev = com;
        com->next = currentNext;
    }
}

void KreogCom::removeCom()
{
    KreogCom *elem = this->next;

    if (elem != nullptr)
        this->next = elem->next;
    delete elem;
}

KreogCom *KreogCom::getCom() const
{
    return this->next;
}

void KreogCom::ping() const
{
    std::cout << "KreogCom " << this->m_serial << " currently at " << this->x << " " << this->y << std::endl;
}

void KreogCom::locateSquad() const
{
    KreogCom *ptr = this->next;

    while (ptr != nullptr) {
        ptr->ping();
        ptr = ptr->next;
    }
    this->ping();
}
