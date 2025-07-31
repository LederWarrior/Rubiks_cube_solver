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
    std::cout << "Margueritte:" << std::endl;
    printLogicalCube();
    while(_logicalCube[DOWN][0][1] != _logicalCube[DOWN][1][1]) {
        std::cout << "DEbug" << std::endl;
        rotateFace(FRONT);
    }
    rotateFace(DOWN);
    rotateFace(DOWN);
    while(_logicalCube[RIGHT][1][0] != _logicalCube[RIGHT][1][1]) {
        std::cout << "DEbug2" << std::endl;
        rotateFace(FRONT);
    }
    rotateFace(RIGHT);
    rotateFace(RIGHT);
    while(_logicalCube[UP][2][1] != _logicalCube[UP][1][1]) {
        std::cout << "DEbug3" << std::endl;
        rotateFace(FRONT);
    }
    rotateFace(UP);
    rotateFace(UP);
    while(_logicalCube[LEFT][1][2] != _logicalCube[LEFT][1][1]) {
        std::cout << "DEbug4" << std::endl;
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
    if ((annex[0] == annex2[0] && annex[1] == annex2[1]) || (annex[0] == annex2[1] && annex[1] == annex2[0]))
        return true;
    return false;
}

void Pattern::Pattern::whiteCorners()
{
    bool err = false;

    while (checkWhiteCorners() == false) {
        err = false;
        turnToCenter(YELLOW);
        if (_logicalCube[FRONT][0][2] == WHITE || _logicalCube[UP][2][2] == WHITE || _logicalCube[RIGHT][0][0] == WHITE) {
            std::vector<FaceColor> annex = {_logicalCube[FRONT][0][2], _logicalCube[UP][2][2], _logicalCube[RIGHT][0][0]};
            std::vector<FaceColor> tempon = annex;
            for (int i = 0; i < 3; i++) {
                if (annex[i] == WHITE) {
                    annex.erase(annex.begin() + i);
                    break;
                }
            }
            std::array<FaceColor, 2> annex2 = {_logicalCube[RIGHT][1][1], _logicalCube[UP][1][1]};
            while (checkAnnex(annex, annex2) == false) {
                rotateFace(FRONT);
                for (int i = 0; i < 3; i++)
                    rotatez();
                annex2 = {_logicalCube[RIGHT][1][1], _logicalCube[UP][1][1]};
                std::cout << "checking annex: " << getColor(annex[0]) << "," << getColor(annex[1]) << " & annex2: " << getColor(annex2[0])<<  "," << getColor(annex2[1]) << std::endl;
                std::cout << "tempon: " << getColor(tempon[0]) << "," << getColor(tempon[1]) << "," << getColor(tempon[2]) << "," << std::endl;
                printLogicalCube();
            }
            std::cout << "Redresse" << std::endl;
            rotatex();
            rotatey();
            printLogicalCube();
            std::array<FaceColor, 2> centers = {_logicalCube[FRONT][1][1], _logicalCube[RIGHT][1][1]};
            while (_logicalCube[DOWN][0][2] != WHITE && _logicalCube[FRONT][2][2] != centers[0] && _logicalCube[RIGHT][0][0] != centers[1]) {
                rotateFace(RIGHT);
                rotateFace(UP);
                for (int i = 0; i < 3; i++)
                    rotateFace(RIGHT);
                for (int i = 0; i < 3; i++)
                    rotateFace(UP);
            }
            turnToCenter(YELLOW);
        }
        if (_logicalCube[FRONT][0][0] == WHITE || _logicalCube[UP][2][0] == WHITE || _logicalCube[LEFT][0][2] == WHITE) {
            std::cout << "Bite" << std::endl;
            rotateFace(FRONT);
            continue;
        } else if (_logicalCube[FRONT][2][0] == WHITE || _logicalCube[DOWN][0][0] == WHITE || _logicalCube[LEFT][2][2] == WHITE) {
            std::cout << "Bite" << std::endl;
            rotateFace(FRONT);
            rotateFace(FRONT);
            continue;
        } else if (_logicalCube[FRONT][2][2] == WHITE || _logicalCube[DOWN][0][2] == WHITE || _logicalCube[RIGHT][2][0] == WHITE) {
            std::cout << "Bite" << std::endl;
            for (int i = 0; i < 3; i++)
                rotateFace(FRONT);
            continue;
        }
        turnToCenter(WHITE);
        std::array<FaceColor, 3> cornerHD = {_logicalCube[FRONT][0][2], _logicalCube[UP][2][2], _logicalCube[RIGHT][0][0]};
        std::array<FaceColor, 3> cornerHG = {_logicalCube[FRONT][0][0], _logicalCube[LEFT][0][2], _logicalCube[UP][2][0]};
        std::array<FaceColor, 3> cornerBD = {_logicalCube[FRONT][2][2], _logicalCube[DOWN][0][2], _logicalCube[RIGHT][2][0]};
        std::array<FaceColor, 3> cornerBG = {_logicalCube[FRONT][2][0], _logicalCube[DOWN][0][0], _logicalCube[LEFT][2][2]};

        std::array<FaceColor, 3> centerHD = {_logicalCube[FRONT][1][1], _logicalCube[UP][1][1], _logicalCube[RIGHT][1][1]};
        std::array<FaceColor, 3> centerHG = {_logicalCube[FRONT][1][1], _logicalCube[LEFT][1][1], _logicalCube[UP][1][1]};
        std::array<FaceColor, 3> centerBD = {_logicalCube[FRONT][1][1], _logicalCube[DOWN][1][1], _logicalCube[RIGHT][1][1]};
        std::array<FaceColor, 3> centerBG = {_logicalCube[FRONT][1][1], _logicalCube[DOWN][1][1], _logicalCube[LEFT][1][1]};

        if (checkOneCorner(cornerHD, WHITE) == true) {
            for (int i = 0; i < 3; i++) {
                if (cornerHD[i] != centerHD[i])
                    err = true;
            }
            if (err == true) {
                for (int j = 0; j < 3; j++)
                    rotatex();
                rotateFace(RIGHT);
                rotateFace(UP);
                for (int j = 0; j < 3; j++)
                    rotateFace(RIGHT);
                for (int j = 0; j < 3; j++)
                    rotateFace(UP);
                turnToCenter(WHITE);
                std::cout << "OK!1" << std::endl;
                continue;
            }
        } else if (checkOneCorner(cornerHG, WHITE) == true) {
            for (int i = 0; i < 3; i++) {
                if (cornerHG[i] != centerHG[i])
                    err = true;
            }
            if (err == true) {
                for (int j = 0; j < 3; j++)
                    rotatex();
                for (int j = 0; j < 3; j++)
                    rotatey();
                rotateFace(RIGHT);
                rotateFace(UP);
                for (int j = 0; j < 3; j++)
                    rotateFace(RIGHT);
                for (int j = 0; j < 3; j++)
                    rotateFace(UP);
                turnToCenter(WHITE);
                std::cout << "OK!2" << std::endl;
                continue;
            }
        } else if (checkOneCorner(cornerBD, WHITE) == true) {
            for (int i = 0; i < 3; i++) {
                if (cornerBD[i] != centerBD[i])
                    err = true;
            }
            if (err == true) {
                for (int j = 0; j < 3; j++)
                    rotatex();
                rotatey();
                rotatey();
                rotateFace(RIGHT);
                rotateFace(UP);
                for (int j = 0; j < 3; j++)
                    rotateFace(RIGHT);
                for (int j = 0; j < 3; j++)
                    rotateFace(UP);
                turnToCenter(WHITE);
                std::cout << "OK!3" << std::endl;
                continue;
            }
        } else if (checkOneCorner(cornerBG, WHITE) == true) {
            for (int i = 0; i < 3; i++) {
                if (cornerBG[i] != centerBG[i])
                    err = true;
            }
            if (err == true) {
                for (int j = 0; j < 3; j++)
                    rotatex();
                rotatey();
                rotateFace(RIGHT);
                rotateFace(UP);
                for (int j = 0; j < 3; j++)
                    rotateFace(RIGHT);
                for (int j = 0; j < 3; j++)
                    rotateFace(UP);
                turnToCenter(WHITE);
                std::cout << "OK!4" << std::endl;
                continue;
            }
        }
    }
}

// bool Pattern::Pattern::isBadCorner(const Corner& corner)
// {
//     FaceColor c1 = _logicalCube[corner.firstFace][corner.firstX][corner.firstY];
//     FaceColor c2 = _logicalCube[corner.secondFace][corner.secondX][corner.secondY];
//     FaceColor c3 = _logicalCube[corner.thirdFace][corner.thirdX][corner.thirdY];

//     FaceColor center1 = _logicalCube[corner.firstFace][1][1];
//     FaceColor center2 = _logicalCube[corner.secondFace][1][1];
//     FaceColor center3 = _logicalCube[corner.thirdFace][1][1];

//     bool hasWhite = (c1 == WHITE || c2 == WHITE || c3 == WHITE);
//     bool whiteNotFacingCenter = 
//         (c1 == WHITE && center1 != WHITE) ||
//         (c2 == WHITE && center2 != WHITE) ||
//         (c3 == WHITE && center3 != WHITE);

//     bool colorNotMatchingCenter = 
//         (c1 != WHITE && c1 != center1) ||
//         (c2 != WHITE && c2 != center2) ||
//         (c3 != WHITE && c3 != center3);

//     return hasWhite && (whiteNotFacingCenter || colorNotMatchingCenter);
// }

// std::vector<Pattern::Pattern::Corner> Pattern::Pattern::getDownCorners(const std::vector<Pattern::Corner>& allCorners)
// {
    // std::vector<Corner> result;
    // for (const Corner& c : allCorners) {
        // if (c.firstFace == DOWN || c.secondFace == DOWN || c.thirdFace == DOWN) {
            // result.push_back(c);
        // }
    // }
    // return result;
// }

// void Pattern::Pattern::whiteCorners()
// {
//     std::vector<Corner> corners = {
//         { FRONT, 0, 0, UP, 2, 0, LEFT, 0, 2 },   // FRONT-UP-LEFT
//         { FRONT, 0, 2, UP, 2, 2, RIGHT, 0, 0 },  // FRONT-UP-RIGHT
//         { FRONT, 2, 0, DOWN, 0, 0, LEFT, 2, 2 }, // FRONT-DOWN-LEFT
//         { FRONT, 2, 2, DOWN, 0, 2, RIGHT, 2, 0 },// FRONT-DOWN-RIGHT
//         { BACK, 0, 0, UP, 0, 2, RIGHT, 0, 2 },   // BACK-UP-RIGHT
//         { BACK, 0, 2, UP, 0, 0, LEFT, 0, 0 },    // BACK-UP-LEFT
//         { BACK, 2, 0, DOWN, 2, 2, RIGHT, 2, 2 }, // BACK-DOWN-RIGHT
//         { BACK, 2, 2, DOWN, 2, 0, LEFT, 2, 0 },  // BACK-DOWN-LEFT
//     };

//     std::vector<Corner> downCorners = getDownCorners(corners);

//     while (!std::all_of(downCorners.begin(), downCorners.end(), 
//     [this](const Corner& c) { return !isBadCorner(c); })) {
//         if (_logicalCube[FRONT][0][0] == WHITE || _logicalCube[FRONT][0][2] == WHITE || _logicalCube[FRONT][2][0] == WHITE || _logicalCube[FRONT][2][2] == WHITE
//             || _logicalCube[UP][2][0] == WHITE || _logicalCube[UP][2][2] == WHITE || _logicalCube[LEFT][0][2] == WHITE || _logicalCube[LEFT][2][2] == WHITE
//             || _logicalCube[DOWN][0][0] == WHITE || _logicalCube[UP][0][2] == WHITE || _logicalCube[RIGHT][0][0] == WHITE || _logicalCube[LEFT][2][0] == WHITE) {

//             FaceColor color1;
//             FaceColor color2;

//             int i = 0;

//             for (const Corner& c : corners) {
//                 FaceColor a = _logicalCube[c.firstFace][c.firstX][c.firstY];
//                 FaceColor b = _logicalCube[c.secondFace][c.secondX][c.secondY];
//                 FaceColor cColor = _logicalCube[c.thirdFace][c.thirdX][c.thirdY];

//                 if (a == WHITE || b == WHITE || cColor == WHITE) {
//                     if (a == WHITE) {
//                         color1 = b;
//                         color2 = cColor;
//                     } else if (b == WHITE) {
//                         color1 = a;
//                         color2 = cColor;
//                     } else {
//                         color1 = a;
//                         color2 = b;
//                     }
//                     break;
//                 }
//                 i++;
//             }
//             // FaceColor centerUP = _logicalCube[UP][1][1];
//             // FaceColor centerRIGHT = _logicalCube[RIGHT][1][1];
//             // FaceColor centerDOWN = _logicalCube[DOWN][1][1];
//             // FaceColor centerLEFT = _logicalCube[LEFT][1][1];
//             int maxTries = 4;
//             while (maxTries--) {
//                 FaceColor centers[4] = {
//                     _logicalCube[UP][1][1],
//                     _logicalCube[RIGHT][1][1],
//                     _logicalCube[DOWN][1][1],
//                     _logicalCube[LEFT][1][1]
//                 };
//                 bool foundColor1 = false;
//                 bool foundColor2 = false;
//                 for (int i = 0; i < 4; ++i) {
//                     if (centers[i] == color1) foundColor1 = true;
//                     if (centers[i] == color2) foundColor2 = true;
//                 }
//                 if (foundColor1 && foundColor2)
//                     break;
//                 rotateFace(FRONT);
//             }
//             enBas(WHITE);
//             while (!std::set<FaceColor>{WHITE, color1, color2}.count(_logicalCube[FRONT][0][2])
//                 || !std::set<FaceColor>{WHITE, color1, color2}.count(_logicalCube[UP][2][2])
//                 || !std::set<FaceColor>{WHITE, color1, color2}.count(_logicalCube[RIGHT][0][0])) {
//                     rotatey();
//             }
//             corners = {
//                 { FRONT, 0, 0, UP, 2, 0, LEFT, 0, 2 },   // FRONT-UP-LEFT
//                 { FRONT, 0, 2, UP, 2, 2, RIGHT, 0, 0 },  // FRONT-UP-RIGHT
//                 { FRONT, 2, 0, DOWN, 0, 0, LEFT, 2, 2 }, // FRONT-DOWN-LEFT
//                 { FRONT, 2, 2, DOWN, 0, 2, RIGHT, 2, 0 },// FRONT-DOWN-RIGHT
//                 { BACK, 0, 0, UP, 0, 2, RIGHT, 0, 2 },   // BACK-UP-RIGHT
//                 { BACK, 0, 2, UP, 0, 0, LEFT, 0, 0 },    // BACK-UP-LEFT
//                 { BACK, 2, 0, DOWN, 2, 2, RIGHT, 2, 2 }, // BACK-DOWN-RIGHT
//                 { BACK, 2, 2, DOWN, 2, 0, LEFT, 2, 0 },  // BACK-DOWN-LEFT
//             };
//             while (isBadCorner(corners[1])) {
//                 rotateFace(RIGHT);
//                 rotateFace(UP);
//                 for (int i = 0; i < 3; i++)
//                     rotateFace(RIGHT);
//                 for (int i = 0; i < 3; i++)
//                     rotateFace(UP);
//             }
//         } else {
//             enBas(WHITE);
//             while (isBadCorner({ FRONT, 2, 2, DOWN, 0, 2, RIGHT, 2, 0 })) {
//                 rotatey();
//             }
//             auto getColors = [&](const Corner& c) -> std::vector<FaceColor> {
//                 return {
//                     _logicalCube[c.firstFace][c.firstX][c.firstY],
//                     _logicalCube[c.secondFace][c.secondX][c.secondY],
//                     _logicalCube[c.thirdFace][c.thirdX][c.thirdY]
//                 };
//             };

//             auto colorsMatch = [&](const Corner& a, const Corner& b) -> bool {
//                 std::vector<FaceColor> colorsA = getColors(a);
//                 std::vector<FaceColor> colorsB = getColors(b);
//                 std::sort(colorsA.begin(), colorsA.end());
//                 std::sort(colorsB.begin(), colorsB.end());
//                 return colorsA == colorsB;
//             };

//             Corner currentCorner = { FRONT, 2, 2, DOWN, 0, 2, RIGHT, 2, 0 };
//             Corner targetCorner  = { FRONT, 0, 2, UP,   2, 2, RIGHT, 0, 0 };

//             while (!colorsMatch(currentCorner, targetCorner)) {
//                 rotateFace(RIGHT);
//                 rotateFace(UP);
//                 for (int i = 0; i < 3; i++)
//                     rotateFace(RIGHT);
//                 for (int i = 0; i < 3; i++)
//                     rotateFace(UP);
//             }
//         }
//         downCorners = getDownCorners(corners);
//     }
// }
