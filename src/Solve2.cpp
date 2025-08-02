/*
** EPITECH PROJECT, 2025
** Rubiks_cube_solver
** File description:
** Solve2
*/

#include "../includes/Pattern.hpp"

static std::string getColor(Pattern::FaceColor color)
{
    if (color == Pattern::WHITE)
        return "WHITE";
    if (color == Pattern::YELLOW)
        return "YELLOW";
    if (color == Pattern::BLUE)
        return "BLUE";
    if (color == Pattern::GREEN)
        return "GREEN";
    if (color == Pattern::RED)
        return "RED";
    if (color == Pattern::ORANGE)
        return "ORANGE";
    return nullptr;
}

int Pattern::Pattern::countInList(std::vector<FaceColor> list, FaceColor color)
{
    int count = 0;

    for (int i = 0; i < 3; i++)
        if (list[i] == color)
            count++;
    return count;
}

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

bool Pattern::Pattern::doesMatch(std::vector<FaceColor> list1, std::vector<FaceColor> list2)
{
    std::cout << "List1: " << getColor(list1[0]) << "," << getColor(list1[1]) << "," << getColor(list1[2]) << std::endl;
    std::cout << "List2: " << getColor(list2[0]) << "," << getColor(list2[1]) << "," << getColor(list2[2]) << std::endl;
    for (int i = 0; i < 3; i++) {
        if (list1[i] == YELLOW)
            list1.erase(list1.begin() + i);
    }
    for (int i = 0; i < 3; i++) {
        if (list2[i] == YELLOW)
            list2.erase(list2.begin() + i);
    }
    if ((list1[0] == list2[0] && list1[1] == list2[1]) || (list1[0] == list2[1] && list1[1] == list2[0]))
        return true;
    return false;
}

bool Pattern::Pattern::checkYellowCorners()
{
    turnToCenter(YELLOW);
    for (int i = 0; i < 3; i++)
        rotatex();
    std::vector<FaceColor> cornerHD = {_logicalCube[FRONT][0][2], _logicalCube[UP][2][2], _logicalCube[RIGHT][0][0]};
    std::vector<FaceColor> cornerHG = {_logicalCube[FRONT][0][0], _logicalCube[LEFT][0][2], _logicalCube[UP][2][0]};
    std::vector<FaceColor> cornerBD = {_logicalCube[FRONT][2][2], _logicalCube[DOWN][0][2], _logicalCube[RIGHT][2][0]};
    std::vector<FaceColor> cornerBG = {_logicalCube[FRONT][2][0], _logicalCube[DOWN][0][0], _logicalCube[LEFT][2][2]};

    std::vector<FaceColor> centerHD = {_logicalCube[FRONT][1][1], _logicalCube[UP][1][1], _logicalCube[RIGHT][1][1]};
    std::vector<FaceColor> centerHG = {_logicalCube[FRONT][1][1], _logicalCube[LEFT][1][1], _logicalCube[UP][1][1]};
    std::vector<FaceColor> centerBD = {_logicalCube[FRONT][1][1], _logicalCube[DOWN][1][1], _logicalCube[RIGHT][1][1]};
    std::vector<FaceColor> centerBG = {_logicalCube[FRONT][1][1], _logicalCube[DOWN][1][1], _logicalCube[LEFT][1][1]};

    rotatex();
    if (doesMatch(cornerHD, centerHD) == false || doesMatch(cornerHG, centerHG) == false
        || doesMatch(cornerBD, centerBD) == false || doesMatch(cornerBG, centerBG) == false)
            return false;
    return true;
}

void Pattern::Pattern::yellowCorners()
{
    std::cout << "Yellow ridges:" << std::endl;
    printLogicalCube();
    turnToCenter(YELLOW);
    std::vector<FaceColor> corner_check = {_logicalCube[FRONT][2][2], _logicalCube[RIGHT][2][0], _logicalCube[DOWN][0][2]};
    std::vector<FaceColor> center_check = {_logicalCube[FRONT][1][1], _logicalCube[RIGHT][1][1], _logicalCube[DOWN][1][1]};
    int stop2 = 0;
    while (doesMatch(corner_check, center_check) == false) {
        rotatez();
        corner_check = {_logicalCube[FRONT][2][2], _logicalCube[RIGHT][2][0], _logicalCube[DOWN][0][2]};
        center_check = {_logicalCube[FRONT][1][1], _logicalCube[RIGHT][1][1], _logicalCube[DOWN][1][1]};
        if (stop2 % 4 == 0) {
            rotatex();
            for (int i = 0; i < 3; i++)
                rotateFace(LEFT);
            rotateFace(UP);
            rotateFace(RIGHT);
            for (int i = 0; i < 3; i++)
                rotateFace(UP);
            rotateFace(LEFT);
            rotateFace(UP);
            for (int i = 0; i < 3; i++)
                rotateFace(RIGHT);
            for (int i = 0; i < 3; i++)
                rotateFace(UP);
            rotatex();
            rotatex();
            rotatex();
        }
        stop2++;
        if (stop2 >= 30)
            break;
    }
    int stop = 0;
    while (checkYellowCorners() == false) {
        rotatex();
        for (int i = 0; i < 3; i++)
            rotateFace(LEFT);
        rotateFace(UP);
        rotateFace(RIGHT);
        for (int i = 0; i < 3; i++)
            rotateFace(UP);
        rotateFace(LEFT);
        rotateFace(UP);
        for (int i = 0; i < 3; i++)
            rotateFace(RIGHT);
        for (int i = 0; i < 3; i++)
            rotateFace(UP);
        rotatex();
        rotatex();
        rotatex();
        stop++;
        if (stop >= 50)
            break;
    }
}
