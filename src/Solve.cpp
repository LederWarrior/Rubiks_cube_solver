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

void Pattern::Pattern::whiteCross()
{
    makeMargueritte();
    turnToYellowCenter();
    while(_logicalCube[DOWN][0][1] == _logicalCube[DOWN][1][1])
        rotateFace(FRONT);
    rotateFace(DOWN);
    rotateFace(DOWN);
    while(_logicalCube[RIGHT][1][0] == _logicalCube[RIGHT][1][1])
        rotateFace(FRONT);
    rotateFace(RIGHT);
    rotateFace(RIGHT);
    while(_logicalCube[UP][2][1] == _logicalCube[UP][1][1])
        rotateFace(FRONT);
    rotateFace(UP);
    rotateFace(UP);
    while(_logicalCube[LEFT][1][0] == _logicalCube[LEFT][1][1])
        rotateFace(FRONT);
    rotateFace(LEFT);
    rotateFace(LEFT);
}

bool Pattern::Pattern::isBadCorner(const Corner& corner)
{
    FaceColor c1 = _logicalCube[corner.firstFace][corner.firstX][corner.firstY];
    FaceColor c2 = _logicalCube[corner.secondFace][corner.secondX][corner.secondY];
    FaceColor c3 = _logicalCube[corner.thirdFace][corner.thirdX][corner.thirdY];

    FaceColor center1 = _logicalCube[corner.firstFace][1][1];
    FaceColor center2 = _logicalCube[corner.secondFace][1][1];
    FaceColor center3 = _logicalCube[corner.thirdFace][1][1];

    bool hasWhite = (c1 == WHITE || c2 == WHITE || c3 == WHITE);
    bool whiteNotFacingCenter = 
        (c1 == WHITE && center1 != WHITE) ||
        (c2 == WHITE && center2 != WHITE) ||
        (c3 == WHITE && center3 != WHITE);

    bool colorNotMatchingCenter = 
        (c1 != WHITE && c1 != center1) ||
        (c2 != WHITE && c2 != center2) ||
        (c3 != WHITE && c3 != center3);

    return hasWhite && (whiteNotFacingCenter || colorNotMatchingCenter);
}

std::vector<Pattern::Pattern::Corner> Pattern::Pattern::getDownCorners(const std::vector<Pattern::Corner>& allCorners) {
    std::vector<Corner> result;
    for (const Corner& c : allCorners) {
        if (c.firstFace == DOWN || c.secondFace == DOWN || c.thirdFace == DOWN) {
            result.push_back(c);
        }
    }
    return result;
}

void Pattern::Pattern::whiteCorners()
{
    std::vector<Corner> corners = {
        { FRONT, 0, 0, UP, 2, 0, LEFT, 0, 2 },   // FRONT-UP-LEFT
        { FRONT, 0, 2, UP, 2, 2, RIGHT, 0, 0 },  // FRONT-UP-RIGHT
        { FRONT, 2, 0, DOWN, 0, 0, LEFT, 2, 2 }, // FRONT-DOWN-LEFT
        { FRONT, 2, 2, DOWN, 0, 2, RIGHT, 2, 0 },// FRONT-DOWN-RIGHT
        { BACK, 0, 0, UP, 0, 2, RIGHT, 0, 2 },   // BACK-UP-RIGHT
        { BACK, 0, 2, UP, 0, 0, LEFT, 0, 0 },    // BACK-UP-LEFT
        { BACK, 2, 0, DOWN, 2, 2, RIGHT, 2, 2 }, // BACK-DOWN-RIGHT
        { BACK, 2, 2, DOWN, 2, 0, LEFT, 2, 0 },  // BACK-DOWN-LEFT
    };

    std::vector<Corner> downCorners = getDownCorners(corners);

    while (!std::all_of(downCorners.begin(), downCorners.end(), 
    [this](const Corner& c) { return !isBadCorner(c); })) {
        if (_logicalCube[FRONT][0][0] == WHITE || _logicalCube[FRONT][0][2] == WHITE || _logicalCube[FRONT][2][0] == WHITE || _logicalCube[FRONT][2][2] == WHITE
            || _logicalCube[UP][2][0] == WHITE || _logicalCube[UP][2][2] == WHITE || _logicalCube[LEFT][0][2] == WHITE || _logicalCube[LEFT][2][2] == WHITE
            || _logicalCube[DOWN][0][0] == WHITE || _logicalCube[UP][0][2] == WHITE || _logicalCube[RIGHT][0][0] == WHITE || _logicalCube[LEFT][2][0] == WHITE) {

            FaceColor color1;
            FaceColor color2;

            int i = 0;

            for (const Corner& c : corners) {
                FaceColor a = _logicalCube[c.firstFace][c.firstX][c.firstY];
                FaceColor b = _logicalCube[c.secondFace][c.secondX][c.secondY];
                FaceColor cColor = _logicalCube[c.thirdFace][c.thirdX][c.thirdY];

                if (a == WHITE || b == WHITE || cColor == WHITE) {
                    if (a == WHITE) {
                        color1 = b;
                        color2 = cColor;
                    } else if (b == WHITE) {
                        color1 = a;
                        color2 = cColor;
                    } else {
                        color1 = a;
                        color2 = b;
                    }
                    break;
                }
                i++;
            }
            // FaceColor centerUP = _logicalCube[UP][1][1];
            // FaceColor centerRIGHT = _logicalCube[RIGHT][1][1];
            // FaceColor centerDOWN = _logicalCube[DOWN][1][1];
            // FaceColor centerLEFT = _logicalCube[LEFT][1][1];
            int maxTries = 4;
            while (maxTries--) {
                FaceColor centers[4] = {
                    _logicalCube[UP][1][1],
                    _logicalCube[RIGHT][1][1],
                    _logicalCube[DOWN][1][1],
                    _logicalCube[LEFT][1][1]
                };
                bool foundColor1 = false;
                bool foundColor2 = false;
                for (int i = 0; i < 4; ++i) {
                    if (centers[i] == color1) foundColor1 = true;
                    if (centers[i] == color2) foundColor2 = true;
                }
                if (foundColor1 && foundColor2)
                    break;
                rotateFace(FRONT);
            }
            enBas(WHITE);
            while (!std::set<FaceColor>{WHITE, color1, color2}.count(_logicalCube[FRONT][0][2])
                || !std::set<FaceColor>{WHITE, color1, color2}.count(_logicalCube[UP][2][2])
                || !std::set<FaceColor>{WHITE, color1, color2}.count(_logicalCube[RIGHT][0][0])) {
                    rotatey();
            }
            corners = {
                { FRONT, 0, 0, UP, 2, 0, LEFT, 0, 2 },   // FRONT-UP-LEFT
                { FRONT, 0, 2, UP, 2, 2, RIGHT, 0, 0 },  // FRONT-UP-RIGHT
                { FRONT, 2, 0, DOWN, 0, 0, LEFT, 2, 2 }, // FRONT-DOWN-LEFT
                { FRONT, 2, 2, DOWN, 0, 2, RIGHT, 2, 0 },// FRONT-DOWN-RIGHT
                { BACK, 0, 0, UP, 0, 2, RIGHT, 0, 2 },   // BACK-UP-RIGHT
                { BACK, 0, 2, UP, 0, 0, LEFT, 0, 0 },    // BACK-UP-LEFT
                { BACK, 2, 0, DOWN, 2, 2, RIGHT, 2, 2 }, // BACK-DOWN-RIGHT
                { BACK, 2, 2, DOWN, 2, 0, LEFT, 2, 0 },  // BACK-DOWN-LEFT
            };
            while (isBadCorner(corners[1])) {
                std::cout << "Boucle inf!" << "\n\n" << std::endl;
                printLogicalCube();
                rotateFace(RIGHT);
                rotateFace(UP);
                for (int i = 0; i < 3; i++)
                    rotateFace(RIGHT);
                for (int i = 0; i < 3; i++)
                    rotateFace(UP);
            }
        } else {
            enBas(WHITE);
            while (isBadCorner({ FRONT, 2, 2, DOWN, 0, 2, RIGHT, 2, 0 })) {
                rotatey();
            }
            auto getColors = [&](const Corner& c) -> std::vector<FaceColor> {
                return {
                    _logicalCube[c.firstFace][c.firstX][c.firstY],
                    _logicalCube[c.secondFace][c.secondX][c.secondY],
                    _logicalCube[c.thirdFace][c.thirdX][c.thirdY]
                };
            };

            auto colorsMatch = [&](const Corner& a, const Corner& b) -> bool {
                std::vector<FaceColor> colorsA = getColors(a);
                std::vector<FaceColor> colorsB = getColors(b);
                std::sort(colorsA.begin(), colorsA.end());
                std::sort(colorsB.begin(), colorsB.end());
                return colorsA == colorsB;
            };

            Corner currentCorner = { FRONT, 2, 2, DOWN, 0, 2, RIGHT, 2, 0 };
            Corner targetCorner  = { FRONT, 0, 2, UP,   2, 2, RIGHT, 0, 0 };

            while (!colorsMatch(currentCorner, targetCorner)) {
                rotateFace(RIGHT);
                rotateFace(UP);
                for (int i = 0; i < 3; i++)
                    rotateFace(RIGHT);
                for (int i = 0; i < 3; i++)
                    rotateFace(UP);
            }
        }
        downCorners = getDownCorners(corners);
    }
}
