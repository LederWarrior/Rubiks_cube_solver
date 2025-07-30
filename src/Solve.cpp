/*
** EPITECH PROJECT, 2025
** Rubiks_cube_solver
** File description:
** Solve
*/

#include "../includes/Pattern.hpp"

void Pattern::Pattern::turnToYellowCenter()
{
    int i = 0;

    for (; i < 6; i++)
        if (_logicalCube[i][1][1] == YELLOW)
            break;
    while (_logicalCube[FRONT][1][1] != YELLOW) {
        if (_logicalCube[UP][1][1] == YELLOW
            || _logicalCube[BACK][1][1] == YELLOW
            || _logicalCube[DOWN][1][1] == YELLOW) {
            std::cout << "X" << std::endl;
            rotatex();
            continue;
        } else {
            std::cout << "Y" << std::endl;
            rotatey();
            continue;
        }
    }
}

bool checkMargueritte(Pattern::FaceColor _logicalCube[6][3][3])
{
    if (_logicalCube[Pattern::FRONT][0][1] == Pattern::WHITE
        && _logicalCube[Pattern::FRONT][1][0] == Pattern::WHITE
        && _logicalCube[Pattern::FRONT][2][1] == Pattern::WHITE
        && _logicalCube[Pattern::FRONT][1][2] == Pattern::WHITE)
            return true;
    return false;
}

void Pattern::Pattern::makeMargueritte()
{
    turnToYellowCenter();
    while (_logicalCube[FRONT][0][1] != WHITE
        || _logicalCube[FRONT][1][0] != WHITE
        || _logicalCube[FRONT][2][1] != WHITE
        || _logicalCube[FRONT][1][2] != WHITE) {
        if (_logicalCube[RIGHT][0][1] == WHITE || _logicalCube[BACK][0][1] == WHITE || _logicalCube[LEFT][0][1] == WHITE) {
            while (_logicalCube[FRONT][0][1] == WHITE)
                rotateFace(FRONT);
            while (_logicalCube[FRONT][0][1] != WHITE)
                rotateFace(UP);
        } if (_logicalCube[RIGHT][2][1] == WHITE || _logicalCube[BACK][2][1] == WHITE || _logicalCube[LEFT][2][1] == WHITE) {
            while (_logicalCube[FRONT][2][1] == WHITE)
                rotateFace(FRONT);
            while (_logicalCube[FRONT][2][1] != WHITE)
                rotateFace(DOWN);
        } if ( _logicalCube[UP][1][2] == WHITE || _logicalCube[DOWN][1][2] == WHITE || _logicalCube[BACK][1][0] == WHITE) {
            while (_logicalCube[FRONT][1][2] == WHITE)
                rotateFace(FRONT);
            while (_logicalCube[FRONT][1][2] != WHITE)
                rotateFace(RIGHT);
        } if ( _logicalCube[UP][1][0] == WHITE || _logicalCube[DOWN][1][0] == WHITE || _logicalCube[BACK][1][2] == WHITE) {
            while (_logicalCube[FRONT][2][1] == WHITE)
                rotateFace(FRONT);
            while (_logicalCube[FRONT][1][0] != WHITE)
                rotateFace(LEFT);
        }
        if (checkMargueritte(_logicalCube) == false) {
            while (_logicalCube[FRONT][0][1] == WHITE)
                rotateFace(FRONT);
            rotateFace(UP);
            rotateFace(FRONT);
            rotateFace(RIGHT);
            rotateFace(FRONT);
            rotateFace(DOWN);
            rotateFace(FRONT);
            rotateFace(LEFT);
            rotateFace(FRONT);
        }
    }
}
