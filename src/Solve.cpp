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
            rotatex();
            continue;
        } else {
            rotatey();
            continue;
        }
    }
}

void Pattern::Pattern::makeMargueritte()
{
    while (_logicalCube[FRONT][0][1] != WHITE
        && _logicalCube[FRONT][1][0] != WHITE
        && _logicalCube[FRONT][2][1] != WHITE
        && _logicalCube[FRONT][1][2] != WHITE) {

        if (_logicalCube[FRONT][0][1] == WHITE || _logicalCube[RIGHT][0][1] == WHITE || _logicalCube[BACK][0][1] == WHITE || _logicalCube[LEFT][0][1] == WHITE) {
            while (_logicalCube[FRONT][0][1] == WHITE)
                rotateFace(FRONT);
            while (_logicalCube[FRONT][0][1] != WHITE)
                rotateFace(UP);
        } if (_logicalCube[FRONT][2][1] == WHITE || _logicalCube[RIGHT][2][1] == WHITE || _logicalCube[BACK][2][1] == WHITE || _logicalCube[LEFT][2][1] == WHITE) {
            while (_logicalCube[FRONT][2][1] == WHITE)
                rotateFace(FRONT);
            while (_logicalCube[FRONT][2][1] != WHITE)
                rotateFace(DOWN);
        } if (_logicalCube[UP][1][2] == WHITE || _logicalCube[FRONT][1][2] == WHITE || _logicalCube[DOWN][1][2] == WHITE || _logicalCube[BACK][1][2] == WHITE) {
            while (_logicalCube[FRONT][1][2] == WHITE)
                rotateFace(FRONT);
            while (_logicalCube[FRONT][1][2] != WHITE)
                rotateFace(RIGHT);
        } if (_logicalCube[UP][1][0] == WHITE || _logicalCube[FRONT][1][0] == WHITE || _logicalCube[DOWN][1][0] == WHITE || _logicalCube[BACK][1][0] == WHITE) {
            while (_logicalCube[FRONT][2][1] == WHITE)
                rotateFace(FRONT);
            while (_logicalCube[FRONT][2][1] != WHITE)
                rotateFace(DOWN);
        }
    }
}
