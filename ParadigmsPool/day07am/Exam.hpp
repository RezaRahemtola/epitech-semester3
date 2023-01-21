/*
** EPITECH PROJECT, 2023
** day07am
** File description:
** $DESCRIPTION
*/

class Exam {
    public:
        Exam(bool *ptr);
        bool isCheating();
        void start(int vessels);
        void (Exam::*kobayashiMaru)(int);

        static bool cheat;
};
