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
        KreogCom *getCom() const;
        void ping() const;
        void locateSquad() const;

        void addCom(KreogCom *com);
    private:
        int x;
        int y;
        const int m_serial;
        KreogCom *prev = nullptr;
        KreogCom *next = nullptr;
};
