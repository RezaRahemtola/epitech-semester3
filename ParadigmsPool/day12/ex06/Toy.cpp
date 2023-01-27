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
    bool result = this->picture.getPictureFromFile(file);
    if (!result)
        this->error = Toy::Error(Error::PICTURE, "bad new illustration", "setAscii");
    return result;
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

bool Toy::speak(const std::string &message)
{
    std::cout << this->name << " \"" << message << "\"" << std::endl;
    return true;
}

Toy &Toy::operator<<(const std::string &data)
{
    this->picture.data = data;
    return *this;
}

bool Toy::speak_es(const std::string &)
{
    this->error = Toy::Error(Error::SPEAK, "wrong mode", "speak_es");
    return false;
}

const Toy::Error &Toy::getLastError() const noexcept
{
    return this->error;
}

std::ostream &operator<<(std::ostream &stream, const Toy &toy)
{
    stream << toy.getName() << std::endl << toy.getAscii() << std::endl;
    return stream;
}

Toy::Error::Error(Toy::Error::ErrorType type, std::string what, std::string where) : type(type),
                                                                                     _what(std::move(what)),
                                                                                     _where(std::move(where))
{
}

std::string Toy::Error::where() const noexcept
{
    return this->_where;
}

std::string Toy::Error::what() const noexcept
{
    return this->_what;
}
