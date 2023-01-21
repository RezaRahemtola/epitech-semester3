/*
** EPITECH PROJECT, 2023
** day07am
** File description:
** $DESCRIPTION
*/

#pragma once

namespace WarpSystem
{
    class QuantumReactor {
        public:
            QuantumReactor();
            bool isStable();
            void setStability(bool stability);

        private:
            bool _stability;
    };

    class Core {
        public:
            Core(QuantumReactor *reactor);
            QuantumReactor *checkReactor();

        private:
            QuantumReactor *_coreReactor;
    };
}
