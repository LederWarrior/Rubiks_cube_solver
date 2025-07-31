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
        Display(Pattern::FaceColor cube[6][3][3], Pattern::Pattern pattern);

        void run();  // Lance la boucle d'affichage
        void update(); // Met à jour l'affichage du cube
        void setCube(Pattern::Pattern pattern);
        void handleKeys(sf::Event event);

    private:
        sf::RenderWindow _window;
        Pattern::FaceColor _logicalCube[6][3][3];

        sf::Color getSfColor(Pattern::FaceColor color);
        void drawFace(Pattern::FaceName face, int offsetX, int offsetY);
        const int squareSize = 40;
        const int padding = 5;
        Pattern::Pattern _pattern;
};