/*
** EPITECH PROJECT, 2023
** Rush 3
** File description:
** Memory.hpp
*/

#include <sys/sysinfo.h>
#include <complex>
#include <sstream>
#include <iomanip>
#include "Memory.hpp"
#include "modules/ModuleError.hpp"

static const double TO_GIGABYTE = std::pow(2, 30);

Memory::Memory() : AMonitorModule<MemoryData>("RAM")
{}

void Memory::refreshData()
{
    struct sysinfo info{};

    if (sysinfo(&info) == -1)
        throw ModuleError("Cannot get memory info.");
    this->plotMemoryGraphFor(this->data.physicalMemoryUsageGraph,
                             (double(info.totalram) - double(info.freeram)) /
                             double(info.totalram));
    this->data.physicalMemoryMax = double(info.totalram) / TO_GIGABYTE;
    this->data.usedPhysicalMemory = double(info.totalram - info.freeram) / TO_GIGABYTE;
    this->plotMemoryGraphFor(this->data.swapMemoryUsageGraph,
                             (double(info.totalswap) - double(info.freeswap) * info.mem_unit) / double(info.totalswap));
    this->data.swapMemoryMax = double(info.totalswap) / TO_GIGABYTE;
    this->data.usedSwapMemory = double(info.totalswap - info.freeswap) / TO_GIGABYTE;
}

void Memory::plotMemoryGraphFor(std::vector<double> &memoryUsageGraph, double toPlot) const
{
    memoryUsageGraph.push_back(toPlot);
    if (memoryUsageGraph.size() > this->plotSize)
        memoryUsageGraph.erase(
                memoryUsageGraph.begin(),
                std::next(memoryUsageGraph.begin(), memoryUsageGraph.size() - this->plotSize)
        );
}

static std::string roundAndConvertVal(double val)
{
    std::stringstream stream;
    stream << std::setprecision(2) << std::fixed << val;
    std::string new_val = stream.str();
    stream.str(std::string());
    return new_val;
}

void Memory::drawText(ModuleBox modBox)
{
    if (this->win == nullptr || getmaxy(this->win) != modBox.endY - modBox.startY ||
        getmaxx(this->win) != modBox.endX - modBox.startX) {
        delwin(this->win);
        this->win = newwin(modBox.endY - modBox.startY, modBox.endX - modBox.startX, modBox.startY,
                           modBox.startX);
    }

    wclear(this->win);
    box(this->win, 0, 0);
    this->refreshData();

    std::string title = "RAM";
    mvwaddstr(this->win, std::max(1, 0 + getmaxy(this->win) / 10), getmaxx(this->win) / 2 - (title.length() / 2),
              title.c_str());

    std::string nbPhysical = roundAndConvertVal(this->data.usedPhysicalMemory);
    std::string nbPhysicalMax = roundAndConvertVal(this->data.physicalMemoryMax);
    std::string physical = "Physical: " + nbPhysical + " / " + nbPhysicalMax + " GB";
    mvwaddstr(this->win, getmaxy(this->win) / 2 + 1, getmaxx(this->win) / 2 - (physical.length() / 2),
              physical.c_str());

    std::string nbSwap = roundAndConvertVal(this->data.usedSwapMemory);
    std::string nbSwapMax = roundAndConvertVal(this->data.swapMemoryMax);
    std::string swap = "Swap: " + nbSwap + " / " + nbSwapMax + " GB";
    mvwaddstr(this->win, getmaxy(this->win) / 2 + 2, getmaxx(this->win) / 2 - (swap.length() / 2),
              swap.c_str());

    wrefresh(this->win);
}

void Memory::drawGraphical(sf::RenderWindow &window, const sf::Font &font, ModuleBox box)
{
    if (this->refreshCount == 0) {
        this->refreshCount = 10;
        this->refreshData();
    }
    this->refreshCount -= 1;
    if (this->rectangle == nullptr) {
        this->rectangle = new sf::RectangleShape();
        this->rectangle->setFillColor(sf::Color(255, 255, 255, 255));
    }
    if (this->text == nullptr) {
        this->text = new sf::Text();
        text->setFont(font);
        text->setCharacterSize(20);
        text->setFillColor(sf::Color(255, 255, 255, 255));
        text->setString("RAM");
    }
    if (this->memory == nullptr) {
        this->memory = new sf::Text();
        memory->setFont(font);
        memory->setCharacterSize(20);
        memory->setFillColor(sf::Color(255, 255, 255, 255));
    }

    int lenX = (box.endX - box.startX) / 2;
    int lenY = (box.endY - box.startY) / 2;
    int posX = lenX + box.startX;
    int posY = lenY * 4 / 5 + box.startY;
    int ramPosY = lenY * 1 / 4 + box.startY;
    int usedPosY = lenY * 3 / 2 + box.startY;

    this->rectangle->setSize(sf::Vector2f(lenX * 1.2, lenY * 0.8));
    std::string nbPhysical = roundAndConvertVal(this->data.usedPhysicalMemory);
    std::string nbPhysicalMax = roundAndConvertVal(this->data.physicalMemoryMax);
    std::string physical = "Physical: " + nbPhysical + " / " + nbPhysicalMax + " GB";

    std::string nbSwap = roundAndConvertVal(this->data.usedSwapMemory);
    std::string nbSwapMax = roundAndConvertVal(this->data.swapMemoryMax);
    std::string swap = "Swap: " + nbSwap + " / " + nbSwapMax + " GB";
    memory->setString(physical + "\n" + swap);

    sf::FloatRect bounds = rectangle->getLocalBounds();
    rectangle->setOrigin(bounds.left + bounds.width / 2.0f,
                         bounds.top + bounds.height / 2.0f);
    rectangle->setPosition(sf::Vector2f((float) posX, (float) posY));
    bounds = text->getLocalBounds();
    text->setOrigin(bounds.left + bounds.width / 2.0f,
                    bounds.top + bounds.height / 2.0f);
    text->setPosition(sf::Vector2f((float) posX, (float) ramPosY));
    bounds = memory->getLocalBounds();
    memory->setOrigin(bounds.left + bounds.width / 2.0f,
                      bounds.top + bounds.height / 2.0f);
    memory->setPosition(sf::Vector2f((float) posX, (float) usedPosY));
    window.draw(*rectangle);
    window.draw(*text);
    window.draw(*memory);
    this->drawGraphicLines(window, box);
}

void Memory::drawGraphicLines(sf::RenderWindow &window, ModuleBox &box)
{
    (void) box;
    if (this->line == nullptr) {
        this->line = new sf::RectangleShape();
    }
    sf::FloatRect bounds = rectangle->getLocalBounds();
    sf::FloatRect global = rectangle->getGlobalBounds();
    sf::FloatRect lineBounds;
    int i = 0;
    double lineSize = bounds.width / (this->plotSize + 1);
    for (double d: data.physicalMemoryUsageGraph) {
        this->line->setFillColor(sf::Color(255 - i, 0, 0, 255));
        this->line->setSize(sf::Vector2f(lineSize, bounds.height * d));
        lineBounds = this->line->getLocalBounds();
        line->setOrigin(lineBounds.left + lineBounds.width / 2.0f,
                        lineBounds.top + lineBounds.height);
        this->line->setPosition(sf::Vector2f(global.left + lineSize * (i + 1), global.top + bounds.height));
        window.draw(*this->line);
        i++;
    }
}
