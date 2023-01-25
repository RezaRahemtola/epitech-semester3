/*
** EPITECH PROJECT, 2023
** day10
** File description:
** reza
*/

#include "ABerry.hpp"
#include "Lemon.hpp"
#include "FruitUtils.hpp"

void FruitUtils::sort(FruitBox &unsorted, FruitBox &lemon, FruitBox &citrus, FruitBox &berry)
{
    unsigned int ops = unsorted.nbFruits();
    IFruit *fruit = nullptr;
    bool inserted = false;

    for (unsigned int i = 0; i < ops; i++) {
        inserted = false;
        fruit = unsorted.popFruit();

        if (dynamic_cast<ACitrus *>(fruit) != nullptr) {
            if (dynamic_cast<Lemon *>(fruit) != nullptr) {
                inserted = lemon.pushFruit(fruit);
            } else {
                inserted = citrus.pushFruit(fruit);
            }
        }
        if (!inserted && dynamic_cast<ABerry *>(fruit) != nullptr)
            inserted = berry.pushFruit(fruit);
        if (!inserted)
            unsorted.pushFruit(fruit);
    }
}

FruitBox **FruitUtils::pack(IFruit **fruits, unsigned int boxSize)
{
    unsigned int len = 0;
    FruitBox **boxes = nullptr;

    if (boxSize == 0)
        return nullptr;

    for (unsigned int i = 0; fruits[i] != nullptr; i++)
        len++;
    boxes = new FruitBox *[len / boxSize + 2];
    for (unsigned int i = 0; i < len / boxSize + 2; i++)
        boxes[i] = nullptr;

    for (unsigned int i = 0; fruits[i] != nullptr; i++) {
        if (i % boxSize == 0)
            boxes[i / boxSize] = new FruitBox(boxSize);
        boxes[i / boxSize]->pushFruit(fruits[i]);
    }
    return boxes;
}

IFruit **FruitUtils::unpack(FruitBox **fruitBoxes)
{
    IFruit **fruits = nullptr;
    unsigned int len = 0;
    unsigned int index = 0;
    unsigned int boxSize = 0;

    if (fruitBoxes == nullptr)
        return nullptr;
    for (unsigned int i = 0; fruitBoxes[i] != nullptr; i++)
        len += fruitBoxes[i]->nbFruits();

    fruits = new IFruit *[len + 2];
    for (unsigned int i = 0; i < len + 2; i++)
        fruits[i] = nullptr;
    for (unsigned int i = 0; fruitBoxes[i] != nullptr; i++) {
        boxSize = fruitBoxes[i]->nbFruits();
        for (unsigned int j = 0; j < boxSize; j++) {
            fruits[index] = fruitBoxes[i]->popFruit();
            index++;
        }
    }
    return fruits;
}