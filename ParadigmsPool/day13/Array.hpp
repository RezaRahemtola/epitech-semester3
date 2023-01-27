/*
** EPITECH PROJECT, 2023
** day13
** File description:
** Array
*/

#pragma once

#include <exception>
#include <vector>
#include <functional>
#include <iostream>
#include <ostream>

template<typename T, size_t Size>
class Array {
    public:
        std::vector<T> array = std::vector<T>(Size);

        class AccessException : public std::exception {
            public:
                [[nodiscard]] const char *what() const noexcept override
                {
                    return "Out of range";
                };
        };

        T &operator[](size_t position)
        {
            if (position >= Size)
                throw AccessException();
            return this->array[position];
        };

        T operator[](size_t position) const
        {
            if (position >= Size)
                throw AccessException();
            return this->array[position];
        };

        [[nodiscard]] std::size_t size() const
        {
            return Size;
        };

        void forEach(const std::function<void(const T &)> &task) const
        {
            for (T elem: this->array)
                task(elem);
        };

        template<typename U>
        Array<U, Size> convert(const std::function<U(const T &)> &converter) const
        {
            Array<U, Size> newArray;

            for (size_t i = 0; i < Size; i++) {
                newArray[i] = converter(this->array[i]);
            }
            return newArray;
        };
};

template<typename T, size_t Size>
std::ostream &operator<<(std::ostream &stream, const Array<T, Size> &array)
{
    stream << std::string("[");
    for (size_t i = 0; i < Size; i++) {
        stream << array[i];
        if (i != Size - 1)
            stream << std::string(", ");
    }
    stream << std::string("]");
    return stream;
};
