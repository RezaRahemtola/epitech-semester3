/*
** EPITECH PROJECT, 2023
** rush3
** File description:
** Display.hpp
*/

#pragma once

#include "AMonitorDisplay.hpp"

namespace Text {
    class Display : public AMonitorDisplay {
        public:
            explicit Display(std::vector<IMonitorModule *> &modules);
            ~Display() override;

            void drawModules() override;
            void displayLoop() override;

            bool needToDraw();
        private:
            int seconds = 0;
    };
}
