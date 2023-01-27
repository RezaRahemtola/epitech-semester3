/*
** EPITECH PROJECT, 2023
** day12
** File description:
** Picture
*/

#include <fstream>
#include <iostream>
#include "Picture.hpp"

Picture::Picture(const std::string &file)
{
    this->getPictureFromFile(file);
}

bool Picture::getPictureFromFile(const std::string &file)
{
    std::string line;
    std::ifstream infile;

    infile.open(file);
    if (!infile.good()) {
        this->data = "ERROR";
        return false;
    }
    this->data = "";
    while (std::getline(infile, line)) {
        this->data += line;
        if (!infile.eof())
            this->data += "\n";
    }
    return true;
}