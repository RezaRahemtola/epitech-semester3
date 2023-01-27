/*
** EPITECH PROJECT, 2023
** day13
** File description:
** Command
*/

#pragma once

#include <exception>
#include <functional>
#include <string>
#include <unordered_map>
#include <utility>

class Command {
    public:
        class Error : public std::exception {
            public:
                explicit Error(std::string text) : text(std::move(text))
                {};

                [[nodiscard]] const char *what() const noexcept override
                {
                    return this->text.c_str();
                };

            private:
                std::string text;
        };

        void registerCommand(const std::string &name, const std::function<void()> &function);
        void executeCommand(const std::string &name);
    private:
        std::unordered_map<std::string, std::function<void()>> map;
};