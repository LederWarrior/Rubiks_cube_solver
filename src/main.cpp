/*
** EPITECH PROJECT, 2025
** rubiks_cube_solver
** File description:
** main
*/

#include "../includes/Display.hpp"

int main(int ac, char *av[])
{
    if (ac > 1) {
        std::string arg1 = static_cast<std::string>(av[1]);
        std::cout << "Rubik's cube solver" << std::endl;
        std::cout << "Arguments: [-h/--help] for help." << std::endl;
        std::cout << "\nUSAGE:" << std::endl;
        std::cout << "INPUTS:" << std::endl;
        std::cout << "\t[U/D/F/B/R/L/X/Y/Z/M/E/S]: movements while the window is open." << std::endl;
        std::cout << "\tEvery movement is wrote on the STDOUT (standard output) while running." << std::endl;
        std::cout << "\tEvery movement is clockwise for convenience purposes." << std::endl;
        std::cout << "\tMovements description:" << std::endl;
        std::cout << "\t\tU:UP\n\t\tD:DOWN\n\t\tF:FRONT\n\t\tB:BACK\n\t\tR:RIGHT\n\t\tL:LEFT\n\t\tX:X axis rotation\n\t\tY:Y axis rotation" << std::endl;
        std::cout << "\t\tZ:Z axis rotation\n\t\tM:MIDDLE\n\t\tE:EQUATOR\n\t\tS:STANDING" << std::endl;
        std::cout << "\t[LEFT CLICK]: Solve the cube (as far as the algorithm goes for now)." << std::endl;
        std::cout << "\t[RIGHT CLICK]: Scramble the cube. Movements are put on the STDOUT." << std::endl;
        return (arg1 == "-h" || arg1 == "--help") ? 0 : 84;
    }

    Pattern::Pattern pattern;

    Pattern::FaceColor logicalCube[6][3][3];
    const auto& sourceCube = pattern.getLogicalCube();

    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 3; k++) {
                logicalCube[i][j][k] = sourceCube[i][j][k];
            }
        }
    }
    Display disp(logicalCube, pattern);
    disp.run();
    return 0;
}
