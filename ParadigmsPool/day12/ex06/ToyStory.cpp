/*
** EPITECH PROJECT, 2023
** day12
** File description:
** ToyStory
*/

#include <fstream>
#include <iostream>
#include "ToyStory.hpp"

void ToyStory::tellMeAStory(const std::string &file,
                            Toy &toy1, bool (Toy::*func1)(const std::string &),
                            Toy &toy2, bool (Toy::*func2)(const std::string &))
{
    std::ifstream infile(file);
    std::string line;
    if (!infile.good()) {
        std::cout << "Bad Story" << std::endl;
        return;
    }

    std::cout << toy1.getAscii() << std::endl;
    std::cout << toy2.getAscii() << std::endl;

    bool isFirst = true;
    while (std::getline(infile, line)) {
        if (line.rfind("picture:", 0) == 0) {
            if (isFirst) {
                if (!toy1.setAscii(line.substr(8))) {
                    const Toy::Error &e = toy1.getLastError();
                    std::cout << e.where() << ": " << e.what() << std::endl;
                    return;
                }
                std::cout << toy1.getAscii();
            } else {
                if (!toy2.setAscii(line.substr(8))) {
                    const Toy::Error &e = toy2.getLastError();
                    std::cout << e.where() << ": " << e.what() << std::endl;
                    return;
                }
                std::cout << toy2.getAscii();
            }
            continue;
        }
        if (isFirst) {
            if (!(toy1.*func1)(line)) {
                const Toy::Error &e = toy1.getLastError();
                std::cout << e.where() << ": " << e.what() << std::endl;
                return;
            }
        } else if (!(toy2.*func2)(line)) {
            const Toy::Error &e = toy2.getLastError();
            std::cout << e.where() << ": " << e.what() << std::endl;
            return;
        }
        isFirst = !isFirst;
    }
}

