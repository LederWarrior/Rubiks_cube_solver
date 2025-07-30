/*
** EPITECH PROJECT, 2025
** rubiks_cube_solver
** File description:
** main
*/

#include "../includes/Display.hpp"

int main()
{
    Pattern::Pattern pattern;

    pattern.rotateFace(Pattern::STANDING);
    pattern.rotateFace(Pattern::BACK);
    pattern.rotateFace(Pattern::RIGHT);
    pattern.rotateFace(Pattern::RIGHT);
    pattern.rotatez();
    pattern.printLogicalCube();
    // static sf::VideoMode mode = sf::VideoMode::getDesktopMode();
    // sf::RenderWindow window(mode, "Rubik's Cube solver");

    // Load a sprite to display
    // sf::Texture texture;
    // if (!texture.loadFromFile("cute_image.jpg"))
    //     return -1;
    // sf::Sprite sprite(texture);

    // Create a graphical text to display
    // sf::Font font;
    // if (!font.loadFromFile("arial.ttf"))
    //     return -1;

    // sf::Text text;
    // text.setFont(font);
    // text.setString("Hello SFML");
    // text.setCharacterSize(50);
    // text.setFillColor(sf::Color::White); // Optionnel

    // Load and play music
    // sf::Music music;
    // if (!music.openFromFile("nice_music.ogg"))
    //     return -1;
    // music.play();

    // Start the game loop
    // while (window.isOpen())
    // {
        // Process events
        // sf::Event event;
        // while (window.pollEvent(event))
        // {
            // Close window: exit
            // if (event.type == sf::Event::Closed)
                // window.close();
        // }

        // Clear screen
        // window.clear(sf::Color::White);

        // Draw the sprite and text
        // window.draw(sprite);
        // window.draw(text);

        // Update the window
        // window.display();
    // }

    return 0;
}
