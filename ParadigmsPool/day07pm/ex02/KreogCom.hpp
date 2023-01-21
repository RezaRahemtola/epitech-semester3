/*
** EPITECH PROJECT, 2023
** ex02
** File description:
** $DESCRIPTION
*/

#pragma once

class KreogCom {
    public:
        KreogCom(int x, int y, int serial);
        ~KreogCom();
        void addCom(int x, int y, int serial);
        void removeCom();
        KreogCom *getCom();
        void ping() const;
        void locateSquad() const;

    private:
        int x;
        int y;
        const int m_serial;
        KreogCom *prev = nullptr;
        KreogCom *next = nullptr;
};
