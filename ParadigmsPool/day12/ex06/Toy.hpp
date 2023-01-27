/*
** EPITECH PROJECT, 2023
** day12
** File description:
** Toy
*/

#pragma once

#include "Picture.hpp"

class Toy {
    public:
        enum ToyType {
            BASIC_TOY,
            ALIEN,
            BUZZ,
            WOODY,
        };
        Toy();
        Toy(ToyType _type, std::string _name, const std::string &file);
        Toy(const Toy &_toy);
        ~Toy() = default;

        [[nodiscard]] ToyType getType() const;
        [[nodiscard]] std::string getName() const;
        void setName(std::string _name);
        bool setAscii(const std::string &file);
        [[nodiscard]] std::string getAscii() const;
        Toy &operator=(const Toy &_toy);

        virtual bool speak(const std::string &message);
        virtual bool speak_es(const std::string &message);

        Toy &operator<<(const std::string &data);

        class Error {
            public:
                enum ErrorType {
                    UNKNOWN,
                    PICTURE,
                    SPEAK
                };
                [[nodiscard]] std::string what() const noexcept;
                [[nodiscard]] std::string where() const noexcept;
                ErrorType type;
                explicit Error(ErrorType type = UNKNOWN, std::string what = "", std::string where = "");
            private:
                std::string _what;
                std::string _where;
        };

        [[nodiscard]] const Error &getLastError() const noexcept;
    protected:
        ToyType type;
        std::string name;
        Picture picture;
        Error error = Error();
};

std::ostream &operator<<(std::ostream &stream, const Toy &toy);