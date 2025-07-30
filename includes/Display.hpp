/*
** EPITECH PROJECT, 2025
** Rubiks_cube_solver
** File description:
** Display
*/

#pragma once

#include "libs.hpp"
#include "Pattern.hpp"

class Display {
    public:
        Display();
        ~Display();
        void show(Pattern::FaceColor base_cube[6][3][3]);

    protected:
    private:
        std::shared_ptr<Pattern::Pattern> _cube_pattern;
};
