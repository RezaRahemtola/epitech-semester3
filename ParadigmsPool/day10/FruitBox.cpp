/*
** EPITECH PROJECT, 2023
** day10
** File description:
** reza
*/

#include "FruitBox.hpp"

FruitBox::FruitBox(unsigned int size) : size(size)
{
    this->fruits = new IFruit *[size];
    for (unsigned int i = 0; i < size; i++)
        this->fruits[i] = nullptr;
}

FruitBox::~FruitBox()
{
    for (unsigned int i = 0; i < size; i++)
        if (this->fruits[i])
            delete this->fruits[i];
    delete[] this->fruits;
}

unsigned int FruitBox::getSize() const
{
    return this->size;
}

unsigned int FruitBox::nbFruits() const
{
    unsigned int len = 0;
    for (unsigned int i = 0; i < this->size; i++)
        if (this->fruits[i] != nullptr)
            len++;
    return (len);
}

bool FruitBox::pushFruit(IFruit *fruit)
{
    for (unsigned int i = 0; i < this->size; i++) {
        if (this->fruits[i] == nullptr) {
            this->fruits[i] = fruit;
            return true;
        }
        if (this->fruits[i] == fruit)
            return false;
    }
    return false;
}

IFruit *FruitBox::popFruit()
{
    IFruit *fruit = nullptr;

    if (this->size == 0)
        return nullptr;
    fruit = this->fruits[0];
    for (unsigned int i = 0; i < this->size - 1; i++) {
        this->fruits[i] = this->fruits[i + 1];
    }
    this->fruits[this->size - 1] = nullptr;
    return (fruit);
}

IFruit **FruitBox::getFruits() const
{
    return this->fruits;
}

std::ostream &operator<<(std::ostream &stream, const FruitBox &box)
{
    stream << std::string("[");
    for (unsigned int i = 0; i < box.nbFruits(); i++) {
        stream << *box.getFruits()[i];
        if (i != box.nbFruits() - 1)
            stream << std::string(", ");
    }
    stream << std::string("]");
    return stream;
}