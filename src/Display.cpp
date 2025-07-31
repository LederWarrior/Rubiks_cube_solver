/*
** EPITECH PROJECT, 2025
** Rubiks_cube_solver
** File description:
** Display
*/

#include "../includes/Display.hpp"

Display::Display(Pattern::FaceColor cube[6][3][3], Pattern::Pattern pattern)
    : _window(sf::VideoMode(1920, 1080), "Rubik's Cube Viewer"), _pattern(pattern)
{
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 3; k++) {
                _logicalCube[i][j][k] = cube[i][j][k];
            }
        }
    }
    _window.setFramerateLimit(30);
}

void Display::setCube(Pattern::Pattern pattern)
{
    const auto& sourceCube = pattern.getLogicalCube();

    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 3; k++) {
                _logicalCube[i][j][k] = sourceCube[i][j][k];
            }
        }
    }
}

sf::Color Display::getSfColor(Pattern::FaceColor color) {
    switch (color) {
        case Pattern::WHITE: return sf::Color::White;
        case Pattern::RED: return sf::Color::Red;
        case Pattern::GREEN: return sf::Color::Green;
        case Pattern::BLUE: return sf::Color::Blue;
        case Pattern::ORANGE: return sf::Color(255, 165, 0); // orange
        case Pattern::YELLOW: return sf::Color::Yellow;
        default: return sf::Color::Black;
    }
}

void Display::drawFace(Pattern::FaceName face, int offsetX, int offsetY) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            sf::RectangleShape square(sf::Vector2f(squareSize, squareSize));
            square.setFillColor(getSfColor(_logicalCube[face][i][j]));
            square.setOutlineColor(sf::Color::Black);
            square.setOutlineThickness(1);
            square.setPosition(offsetX + j * (squareSize + padding), offsetY + i * (squareSize + padding));
            _window.draw(square);
        }
    }
}

void Display::handleKeys(sf::Event event)
{
    event = event;
    if (event.key.code == sf::Keyboard::F)
        _pattern.rotateFace(Pattern::FRONT);
    if (event.key.code == sf::Keyboard::B)
        _pattern.rotateFace(Pattern::BACK);
    if (event.key.code == sf::Keyboard::U)
        _pattern.rotateFace(Pattern::UP);
    if (event.key.code == sf::Keyboard::D)
        _pattern.rotateFace(Pattern::DOWN);
    if (event.key.code == sf::Keyboard::L)
        _pattern.rotateFace(Pattern::LEFT);
    if (event.key.code == sf::Keyboard::R)
        _pattern.rotateFace(Pattern::RIGHT);
    
    setCube(_pattern);
}

void Display::update() {
    _window.clear(sf::Color(50, 50, 50));

    int cx = 1920 / 3;
    int cy = 1080 / 3;

    // Disposition du patron
    drawFace(Pattern::UP, cx + squareSize * 3 + padding * 3, cy - squareSize * 4);
    drawFace(Pattern::LEFT, cx, cy);
    drawFace(Pattern::FRONT, cx + squareSize * 3 + padding * 3, cy);
    drawFace(Pattern::RIGHT, cx + (squareSize + padding) * 6, cy);
    drawFace(Pattern::BACK, cx + (squareSize + padding) * 9, cy);
    drawFace(Pattern::DOWN, cx + squareSize * 3 + padding * 3, cy + squareSize * 4);

    _window.display();
}

void Display::run() {
    while (_window.isOpen()) {
        sf::Event event;
        while (_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                _window.close();
            if (event.type == sf::Event::KeyPressed) {
                handleKeys(event);
            }
        }
        update();
    }
}
