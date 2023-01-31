/*
** EPITECH PROJECT, 2023
** Rush3
** File description:
** Utils.cpp
*/

#include <cmath>
#include "Utils.hpp"

#include <iostream>

std::vector<DisplayItem> Utils::placeModules(std::vector<IMonitorModule *> &modules, int sizeX, int sizeY, int page)
{
    std::vector<DisplayItem> list;
    int size = (int) modules.size();
    int grid = std::min(3, (int) std::ceil(std::sqrt(size)));
    int defX = 0;
    int defY = 0;

    if (modules.empty())
        return list;
    defX = sizeX / grid;
    defY = sizeY / grid;

    for (int i = 0; i + (page - 1) * 3 < size; i++) {
        auto *box = new ModuleBox();
        box->startX = defX * (i % grid);
        box->startY = defY * (i / grid);
        box->endX = defX * (i % grid + 1);
        box->endY = defY * (i / grid + 1);
        DisplayItem item = {*modules[i + (page - 1) * 3], box};
        list.push_back(item);
    }
    if (size == 2) {
        list[0].box->endX = sizeX;
        list[0].box->endY = sizeY / 2;
        list[1].box->startX = 0;
        list[1].box->startY = sizeY / 2;
        list[1].box->endX = sizeX;
        list[1].box->endY = sizeY;
    }
    if (size == 3) {
        list[size - 1].box->endX = sizeX;
    }
    return list;
}
