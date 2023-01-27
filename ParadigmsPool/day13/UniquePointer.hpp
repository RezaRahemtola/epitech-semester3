/*
** EPITECH PROJECT, 2023
** day13
** File description:
** UniquePointer
*/

#pragma once

template<typename T>
class UniquePointer {
    public:
        explicit UniquePointer(T *ptr = nullptr) : ptr(ptr)
        {};

        ~UniquePointer()
        {
            delete this->ptr;
        };

        UniquePointer(const UniquePointer<T> &) = delete;
        UniquePointer<T> &operator=(const UniquePointer<T> &) = delete;

        UniquePointer<T> &operator=(T *newPtr)
        {
            delete this->ptr;
            this->ptr = newPtr;
            return *this;
        };

        T *operator->() const
        {
            return this->ptr;
        }

        void reset(T *newPtr = nullptr)
        {
            delete this->ptr;
            this->ptr = newPtr;
        };

        T *get()
        {
            return this->ptr;
        }

    private:
        T *ptr;
};
