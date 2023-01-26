/*
** EPITECH PROJECT, 2023
** day11
** File description:
** reza
*/

#pragma once

#include <exception>
#include <string>

class IDirectoryLister {
    public:
        virtual bool open(const std::string &path, bool hidden) = 0;
        virtual std::string get() = 0;
        virtual ~IDirectoryLister() = default;

        class OpenFailureException : public std::exception {
            public:
                [[nodiscard]] const char *what() const noexcept override;
        };

        class NoMoreFileException : public std::exception {
            public:
                [[nodiscard]] const char *what() const noexcept override;
        };
};