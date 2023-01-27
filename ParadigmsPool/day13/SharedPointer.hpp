/*
** EPITECH PROJECT, 2023
** day13
** File description:
** SharedPointer
*/

#pragma once

#include <unordered_map>

template<typename T>
static std::unordered_map<T *, std::size_t> map;

template<typename T>
class SharedPointer {
    public:
        explicit SharedPointer(T *newPtr = nullptr) : ptr(newPtr)
        {
            if (newPtr != nullptr) {
                if (map<T>.count(newPtr) == 0) {
                    map<T>[newPtr] = 1;
                } else {
                    map<T>[ptr]++;
                }
            }
        };

        SharedPointer(const SharedPointer<T> &newPtr)
        {
            if (this->ptr != nullptr) {
                if (map<T>[this->ptr] > 1) {
                    map<T>[this->ptr]--;
                    this->ptr = nullptr;
                } else {
                    map<T>.erase(this->ptr);
                    delete this->ptr;
                }
            }
            this->ptr = newPtr.get();
            if (this->ptr != nullptr)
                map<T>[this->ptr]++;
        };

        ~SharedPointer()
        {
            if (this->ptr != nullptr) {
                if (map<T>[this->ptr] > 1) {
                    map<T>[this->ptr]--;
                    return;
                } else {
                    map<T>.erase(this->ptr);
                }
            }
            delete this->ptr;
        };


        SharedPointer<T> &operator=(const SharedPointer<T> &newPtr)
        {
            if (this->ptr != nullptr) {
                if (map<T>[this->ptr] > 1) {
                    map<T>[this->ptr]--;
                    this->ptr = nullptr;
                } else {
                    map<T>.erase(this->ptr);
                    delete this->ptr;
                }
            }
            this->ptr = newPtr.get();
            if (this->ptr != nullptr)
                map<T>[this->ptr]++;
            return *this;
        }

        SharedPointer<T> &operator=(T *newPtr)
        {
            if (this->ptr != nullptr) {
                if (map<T>[this->ptr] > 1) {
                    map<T>[this->ptr] -= 1;
                    this->ptr = nullptr;
                } else {
                    map<T>.erase(newPtr);
                    delete this->ptr;
                }
            }
            this->ptr = newPtr;
            if (this->ptr != nullptr)
                map<T>[this->ptr]++;
            return *this;
        };

        T *operator->() const
        {
            return this->ptr;
        }

        void reset()
        {
            if (this->ptr != nullptr) {
                if (map<T>[this->ptr] > 1) {
                    map<T>[this->ptr]--;
                    this->ptr = nullptr;
                } else {
                    map<T>.erase(this->ptr);
                    delete this->ptr;
                }
                this->ptr = nullptr;
            }
        };

        T *get() const
        {
            return this->ptr;
        }

    private:
        T *ptr = nullptr;
};
