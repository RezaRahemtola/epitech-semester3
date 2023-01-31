/*
** EPITECH PROJECT, 2023
** Rush 3
** File description:
** AKeyValueDisplayedMonitorModule.hpp
*/

#pragma once

#include <iostream>
#include "AMonitorModule.hpp"

class AKeyValueDisplayedMonitorModule : public AMonitorModule<std::map<std::string, std::string>> {
    public:
        explicit AKeyValueDisplayedMonitorModule(const std::string &name) : AMonitorModule(name)
        {}

        ~AKeyValueDisplayedMonitorModule() override
        {
            delete this->text;
            delwin(this->win);
        }

        void drawText(ModuleBox modBox) final
        {
            std::size_t idx = 0;
            if (this->win == nullptr || getmaxy(this->win) != modBox.endY - modBox.startY ||
                getmaxx(this->win) != modBox.endX - modBox.startX) {
                delwin(this->win);
                this->win = newwin(modBox.endY - modBox.startY, modBox.endX - modBox.startX, modBox.startY,
                                   modBox.startX);
            }

            wclear(this->win);
            box(this->win, 0, 0);
            this->refreshData();
            for (auto const &[key, val]: this->data) {
                std::string content = key + ": " + val;

                mvwaddstr(this->win, getmaxy(this->win) / 2 + idx, getmaxx(this->win) / 2 - (content.length() / 2),
                          content.c_str());
                idx++;
            }
            wrefresh(this->win);
        }

        void drawGraphical(sf::RenderWindow &window, const sf::Font &font, ModuleBox box) final
        {
            this->refreshData();
            if (this->text == nullptr) {
                this->text = new sf::Text();
                text->setFont(font);
                text->setCharacterSize(20);
                text->setFillColor(sf::Color(255, 255, 255, 255));
            }
            std::string str;
            for (auto const &[key, value]: this->data) {
                str += key + ": " + value + "\n";
            }
            text->setString(str);

            int posX = (box.endX - box.startX) / 2 + box.startX;
            int posY = (box.endY - box.startY) / 2 + box.startY;
            sf::FloatRect bounds = text->getLocalBounds();
            text->setOrigin(bounds.left + bounds.width / 2.0f,
                            bounds.top + bounds.height / 2.0f);
            text->setPosition(sf::Vector2f((float) posX, (float) posY));

            window.draw(*this->text);
        }

    private:
        sf::Text *text = nullptr;
        WINDOW *win = nullptr;
};
