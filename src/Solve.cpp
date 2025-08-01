/*
** EPITECH PROJECT, 2025
** Rubiks_cube_solver
** File description:
** Solve
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

void Pattern::Pattern::turnToCenter(FaceColor face)
{
    int i = 0;

    for (; i < 6; i++)
        if (_logicalCube[i][1][1] == face)
            break;
    while (_logicalCube[FRONT][1][1] != face) {
        if (_logicalCube[UP][1][1] == face
            || _logicalCube[BACK][1][1] == face
            || _logicalCube[DOWN][1][1] == face) {
            rotatex();
            continue;
        } else {
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
    turnToCenter(YELLOW);
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
        } if (_logicalCube[UP][1][2] == WHITE || _logicalCube[DOWN][1][2] == WHITE || _logicalCube[BACK][1][0] == WHITE) {
            while (_logicalCube[FRONT][1][2] == WHITE)
                rotateFace(FRONT);
            while (_logicalCube[FRONT][1][2] != WHITE)
                rotateFace(RIGHT);
        } if (_logicalCube[UP][1][0] == WHITE || _logicalCube[DOWN][1][0] == WHITE || _logicalCube[BACK][1][2] == WHITE) {
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

void Pattern::Pattern::whiteCross()
{
    makeMargueritte();
    std::cout << "Margueritte:" << std::endl;
    printLogicalCube();
    while(_logicalCube[DOWN][0][1] != _logicalCube[DOWN][1][1]) {
        rotateFace(FRONT);
    }
    rotateFace(DOWN);
    rotateFace(DOWN);
    while(_logicalCube[RIGHT][1][0] != _logicalCube[RIGHT][1][1]) {
        rotateFace(FRONT);
    }
    rotateFace(RIGHT);
    rotateFace(RIGHT);
    while(_logicalCube[UP][2][1] != _logicalCube[UP][1][1]) {
        rotateFace(FRONT);
    }
    rotateFace(UP);
    rotateFace(UP);
    while(_logicalCube[LEFT][1][2] != _logicalCube[LEFT][1][1]) {
        rotateFace(FRONT);
    }
    rotateFace(LEFT);
    rotateFace(LEFT);
}

bool Pattern::Pattern::checkWhiteCorners()
{
    turnToCenter(WHITE);
    std::array<FaceColor, 3> cornerHD = {_logicalCube[FRONT][0][2], _logicalCube[UP][2][2], _logicalCube[RIGHT][0][0]};
    std::array<FaceColor, 3> cornerHG = {_logicalCube[FRONT][0][0], _logicalCube[LEFT][0][2], _logicalCube[UP][2][0]};
    std::array<FaceColor, 3> cornerBD = {_logicalCube[FRONT][2][2], _logicalCube[DOWN][0][2], _logicalCube[RIGHT][2][0]};
    std::array<FaceColor, 3> cornerBG = {_logicalCube[FRONT][2][0], _logicalCube[DOWN][0][0], _logicalCube[LEFT][2][2]};

    std::array<FaceColor, 3> centerHD = {_logicalCube[FRONT][1][1], _logicalCube[UP][1][1], _logicalCube[RIGHT][1][1]};
    std::array<FaceColor, 3> centerHG = {_logicalCube[FRONT][1][1], _logicalCube[LEFT][1][1], _logicalCube[UP][1][1]};
    std::array<FaceColor, 3> centerBD = {_logicalCube[FRONT][1][1], _logicalCube[DOWN][1][1], _logicalCube[RIGHT][1][1]};
    std::array<FaceColor, 3> centerBG = {_logicalCube[FRONT][1][1], _logicalCube[DOWN][1][1], _logicalCube[LEFT][1][1]};

    for (int i = 0; i < 3; i++) {
        if (cornerHD[i] != centerHD[i] || cornerHG[i] != centerHG[i]
        || cornerBD[i] != centerBD[i] || cornerBG[i] != centerBG[i])
            return false;
    }
    return true;
}

bool Pattern::Pattern::checkOneCorner(std::array<FaceColor, 3> corner, FaceColor color)
{
    for (int i = 0; i < 3; i++) {
        if (corner[i] == color)
            return true;
    }
    return false;
}

bool checkAnnex(std::vector<Pattern::FaceColor> annex, std::array<Pattern::FaceColor, 2> annex2)
{
    std::cout << "Annex:" << getColor(annex[0]) << "," << getColor(annex[1]) << std::endl;
    std::cout << "Annex2:" << getColor(annex2[0]) << "," << getColor(annex2[1]) << std::endl;
    if ((annex[0] == annex2[0] && annex[1] == annex2[1]) || (annex[0] == annex2[1] && annex[1] == annex2[0]))
        return true;
    return false;
}

void Pattern::Pattern::whiteCorners()
{
    while (checkWhiteCorners() == false) {
        std::cout << "Début" << std::endl;
        turnToCenter(YELLOW);
        if (_logicalCube[FRONT][0][2] == WHITE || _logicalCube[UP][2][2] == WHITE || _logicalCube[RIGHT][0][0] == WHITE) {
            std::cout << "Entered solve if" << std::endl;
            std::vector<FaceColor> annex = {_logicalCube[FRONT][0][2], _logicalCube[UP][2][2], _logicalCube[RIGHT][0][0]};
            for (int i = 0; i < 3; i++) {
                if (annex[i] == WHITE) {
                    annex.erase(annex.begin() + i);
                    break;
                }
            }
            std::array<FaceColor, 2> annex2 = {_logicalCube[RIGHT][1][1], _logicalCube[UP][1][1]};
            while (checkAnnex(annex, annex2) == false) {
                std::cout << "Il est la ce fdp" << std::endl;
                rotateFace(FRONT);
                for (int i = 0; i < 3; i++)
                    rotatez();
                annex2 = {_logicalCube[RIGHT][1][1], _logicalCube[UP][1][1]};
            }
            std::cout << "Redresse" << std::endl;
            rotatex();
            rotatey();
            printLogicalCube();
            std::array<FaceColor, 2> centers = {_logicalCube[FRONT][1][1], _logicalCube[RIGHT][1][1]};
            std::cout << "Centers:" << getColor(centers[0]) << "," << getColor(centers[1]) << std::endl;
            while (_logicalCube[DOWN][0][2] != WHITE || _logicalCube[FRONT][2][2] != centers[0] || _logicalCube[RIGHT][2][0] != centers[1]) {
                centers = {_logicalCube[FRONT][1][1], _logicalCube[RIGHT][1][1]};
                rotateFace(RIGHT);
                rotateFace(UP);
                for (int i = 0; i < 3; i++)
                    rotateFace(RIGHT);
                for (int i = 0; i < 3; i++)
                    rotateFace(UP);
                std::cout << "Sexy move" << std::endl;
                printLogicalCube();
            }
            turnToCenter(YELLOW);
            std::cout << "At the end of solve if:" << std::endl;
            printLogicalCube();
        }
        if (_logicalCube[FRONT][0][0] == WHITE || _logicalCube[UP][2][0] == WHITE || _logicalCube[LEFT][0][2] == WHITE) {
            std::cout << "Bite" << std::endl;
            rotateFace(FRONT);
            continue;
        } if (_logicalCube[FRONT][2][0] == WHITE || _logicalCube[DOWN][0][0] == WHITE || _logicalCube[LEFT][2][2] == WHITE) {
            std::cout << "Bite" << std::endl;
            rotateFace(FRONT);
            rotateFace(FRONT);
            continue;
        } if (_logicalCube[FRONT][2][2] == WHITE || _logicalCube[DOWN][0][2] == WHITE || _logicalCube[RIGHT][2][0] == WHITE) {
            std::cout << "Bite test hey" << std::endl;
            for (int i = 0; i < 3; i++)
                rotateFace(FRONT);
            continue;
        }

        turnToCenter(YELLOW);
        rotatex();
        for (int i = 0; i < 4; i++) {
            std::array<FaceColor, 3> corner = {_logicalCube[DOWN][0][2], _logicalCube[FRONT][2][2], _logicalCube[RIGHT][2][0]};
            std::array<FaceColor, 3> center = {_logicalCube[DOWN][1][1], _logicalCube[FRONT][1][1], _logicalCube[RIGHT][1][1]};
            for (int j = 0; j < 3; j++) {
                if (corner[j] != center[j]) {
                    rotateFace(RIGHT);
                    rotateFace(UP);
                    for (int f = 0; f < 3; f++)
                        rotateFace(RIGHT);
                    for (int f = 0; f < 3; f++)
                        rotateFace(UP);
                    break;
                }
            }
            rotatey();
        }
    }
}
