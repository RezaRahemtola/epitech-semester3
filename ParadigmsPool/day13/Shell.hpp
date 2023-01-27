/*
** EPITECH PROJECT, 2023
** day13
** File description:
** Shell
*/

#pragma once

#include <exception>
#include <string>
#include <iostream>
#include <istream>
#include <sstream>

class Shell {
    public:
        class Warning : public std::exception {
            public:
                explicit Warning(std::string text) : text(std::move(text))
                {
                };

                [[nodiscard]] const char *what() const noexcept override
                {
                    return this->text.c_str();
                }

            private:
                std::string text;
        };

        class Error : public std::exception {
            public:
                explicit Error(std::string text) : text(std::move(text))
                {}

                [[nodiscard]] const char *what() const noexcept override
                {
                    return this->text.c_str();
                }

            private:
                std::string text;
        };

        explicit Shell(std::istream &istream);
        ~Shell() = default;

        void next();

        template<typename T>
        T extract()
        {
            T result;
            std::string data;

            if (!(this->line >> result))
                throw Warning("Invalid conversion");
            return result;
        }

    private:
        std::istream &stream;
        std::stringstream line;
};
