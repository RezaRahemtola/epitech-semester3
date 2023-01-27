/*
** EPITECH PROJECT, 2023
** day12
** File description:
** Toy
*/

#include <iostream>
#include <utility>
#include "Toy.hpp"

Toy::Toy() : type(BASIC_TOY), name("toy"), picture(Picture())
{}

Toy::Toy(ToyType _type, std::string _name, const std::string &file) : type(_type), name(std::move(_name)),
                                                                      picture(Picture(file))
{}

Toy::ToyType Toy::getType() const
{
    return this->type;
}

std::string Toy::getName() const
{
    return this->name;
}

void Toy::setName(std::string _name)
{
    this->name = _name;
}

bool Toy::setAscii(const std::string &file)
{
    return this->picture.getPictureFromFile(file);
}

std::string Toy::getAscii() const
{
    return this->picture.data;
}

Toy::Toy(const Toy &_toy) : type(_toy.type), name(_toy.name), picture(Picture(_toy.picture))
{}

Toy &Toy::operator=(const Toy &_toy)
{
    this->type = _toy.type;
    this->name = _toy.name;
    this->picture = Picture(_toy.picture);
    return *this;
}

void Toy::speak(const std::string &message)
{
    std::cout << this->name << " \"" << message << "\"" << std::endl;
}

Toy &Toy::operator<<(const std::string &data)
{
    this->picture.data = data;
    return *this;
}

std::ostream &operator<<(std::ostream &stream, const Toy &toy)
{
    stream << toy.getName() << std::endl << toy.getAscii() << std::endl;
    return stream;
}
