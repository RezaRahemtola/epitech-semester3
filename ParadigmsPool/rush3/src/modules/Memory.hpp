/*
** EPITECH PROJECT, 2023
** Rush 3
** File description:
** Memory.hpp
*/

#pragma once

#include "AMonitorModule.hpp"

typedef struct {
    std::vector<double> physicalMemoryUsageGraph;
    std::vector<double> swapMemoryUsageGraph;
    double physicalMemoryMax;
    double usedPhysicalMemory;
    double swapMemoryMax;
    double usedSwapMemory;
} MemoryData;

class Memory : public AMonitorModule<MemoryData> {
        std::size_t plotSize = 100;
        int refreshCount = 0;
        sf::Text *text = nullptr;
        sf::Text *memory = nullptr;
        sf::RectangleShape *rectangle = nullptr;
        sf::RectangleShape *line = nullptr;

        void plotMemoryGraphFor(std::vector<double> &memoryUsageGraph, double toPlot) const;
        WINDOW *win = nullptr;
    public:
        Memory();
        ~Memory() override = default;

        void refreshData() final;

        void drawText(ModuleBox modBox) final;
        void drawGraphical(sf::RenderWindow &window, const sf::Font &font, ModuleBox box) final;

    private:
        void drawGraphicLines(sf::RenderWindow &window, ModuleBox &box);
};
