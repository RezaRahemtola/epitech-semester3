/*
** EPITECH PROJECT, 2023
** ex01
** File description:
** $DESCRIPTION
*/

#pragma once

#include <string>

class DroidMemory {
    public:
        DroidMemory();
        DroidMemory(const DroidMemory &mem);

        size_t getFingerprint() const;
        size_t getExp() const;
        void setFingerprint(size_t fingerprint);
        void setExp(size_t exp);

        void operator<<(DroidMemory &droid);
        void operator>>(DroidMemory &droid);
        void operator+=(DroidMemory &droid);
        void operator+=(size_t exp);
        DroidMemory operator+(DroidMemory &droid) const;
        DroidMemory operator+(size_t exp) const;

        DroidMemory &operator=(const DroidMemory &source);
        bool operator==(const DroidMemory &droid) const;
        bool operator!=(const DroidMemory &droid) const;

        bool operator<(const DroidMemory &droid) const;
        bool operator<(size_t exp) const;
        bool operator>(const DroidMemory &droid) const;
        bool operator>(size_t exp) const;
        bool operator<=(const DroidMemory &droid) const;
        bool operator<=(size_t exp) const;
        bool operator>=(const DroidMemory &droid) const;
        bool operator>=(size_t exp) const;
    private:
        size_t Exp;
        size_t Fingerprint;
};

std::ostream &operator<<(std::ostream&stream, const DroidMemory &mem);
