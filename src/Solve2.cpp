/*
** EPITECH PROJECT, 2025
** Rubiks_cube_solver
** File description:
** Solve2
*/

#include "../includes/Pattern.hpp"

bool Pattern::Pattern::checkYellowRidges()
{
    turnToCenter(YELLOW);
    if (_logicalCube[FRONT][1][0] != YELLOW || _logicalCube[FRONT][0][1] != YELLOW
        || _logicalCube[FRONT][1][2] != YELLOW || _logicalCube[FRONT][2][1] != YELLOW
        || _logicalCube[FRONT][1][1] != YELLOW)
            return false;
    if (_logicalCube[RIGHT][1][0] != _logicalCube[RIGHT][1][1])
        return false;
    if (_logicalCube[UP][2][1] != _logicalCube[UP][1][1])
        return false;
    if (_logicalCube[LEFT][1][2] != _logicalCube[LEFT][1][1])
        return false;
    if (_logicalCube[DOWN][0][1] != _logicalCube[DOWN][1][1])
        return false;
    return true;
}

void Pattern::Pattern::yellowRidge()
{
    int stop = 0;
    std::cout << "Où qu'on en est?" << std::endl;
    printLogicalCube();
    while (checkYellowRidges() == false) {
        turnToCenter(YELLOW);
        if (_logicalCube[UP][2][1] == _logicalCube[UP][1][1] && _logicalCube[RIGHT][1][0] == _logicalCube[RIGHT][1][1]) {
            rotatex();
            rotateFace(RIGHT);
            rotateFace(UP);
            for (int i = 0; i < 3; i++)
                rotateFace(RIGHT);
            rotateFace(UP);
            rotateFace(RIGHT);
            rotateFace(UP);
            rotateFace(UP);
            for (int i = 0; i < 3; i++)
                rotateFace(RIGHT);
            for (int i = 0; i < 3; i++)
                rotatex();
            int stop2 = 0;
            while (checkYellowRidges() == false) {
                rotateFace(FRONT);
                stop2++;
                if (stop2 >= 20)
                    break;
            }
        } else if (_logicalCube[LEFT][1][2] == _logicalCube[LEFT][1][1] && _logicalCube[UP][2][1] == _logicalCube[UP][1][1]) {
            rotatez();
        } else if (_logicalCube[LEFT][1][2] == _logicalCube[LEFT][1][1] && _logicalCube[DOWN][0][1] == _logicalCube[DOWN][1][1]) {
            rotatez();
            rotatez();
        } else if (_logicalCube[DOWN][0][1] == _logicalCube[DOWN][1][1] && _logicalCube[RIGHT][1][0] == _logicalCube[RIGHT][1][1]) {
            rotatez();
            rotatez();
            rotatez();
        }
        else if (_logicalCube[UP][2][1] == _logicalCube[UP][1][1] && _logicalCube[DOWN][0][1] == _logicalCube[DOWN][1][1]) {
            rotatex();
            rotateFace(RIGHT);
            rotateFace(UP);
            for (int i = 0; i < 3; i++)
                rotateFace(RIGHT);
            rotateFace(UP);
            rotateFace(RIGHT);
            rotateFace(UP);
            rotateFace(UP);
            for (int i = 0; i < 3; i++)
                rotateFace(RIGHT);
        } else if (_logicalCube[LEFT][1][2] == _logicalCube[LEFT][1][1] && _logicalCube[RIGHT][1][0] == _logicalCube[RIGHT][1][1]) {
            rotatez();
        } else {
            rotateFace(FRONT);
        }
        stop++;
        if (stop >= 20)
            break;
    }
}
