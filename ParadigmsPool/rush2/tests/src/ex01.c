/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 01
*/

#include "new.h"
#include "player.h"

int main(void)
{
    Object *player = new(Player);

    delete(player);
    return (0);
}
