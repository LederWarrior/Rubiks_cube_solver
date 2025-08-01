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
    std::cout << "Turned to center: " << getColor(face) << std::endl;
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
    if ((annex[0] == annex2[0] && annex[1] == annex2[1]) || (annex[0] == annex2[1] && annex[1] == annex2[0]))
        return true;
    return false;
}

void Pattern::Pattern::whiteCorners()
{
    while (checkWhiteCorners() == false) {
        turnToCenter(YELLOW);
        if (_logicalCube[FRONT][0][2] == WHITE || _logicalCube[UP][2][2] == WHITE || _logicalCube[RIGHT][0][0] == WHITE) {
            std::vector<FaceColor> annex = {_logicalCube[FRONT][0][2], _logicalCube[UP][2][2], _logicalCube[RIGHT][0][0]};
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
            }
            rotatex();
            rotatey();
            std::array<FaceColor, 2> centers = {_logicalCube[FRONT][1][1], _logicalCube[RIGHT][1][1]};
            while (_logicalCube[DOWN][0][2] != WHITE || _logicalCube[FRONT][2][2] != centers[0] || _logicalCube[RIGHT][2][0] != centers[1]) {
                centers = {_logicalCube[FRONT][1][1], _logicalCube[RIGHT][1][1]};
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
            rotateFace(FRONT);
            continue;
        } if (_logicalCube[FRONT][2][0] == WHITE || _logicalCube[DOWN][0][0] == WHITE || _logicalCube[LEFT][2][2] == WHITE) {
            rotateFace(FRONT);
            rotateFace(FRONT);
            continue;
        } if (_logicalCube[FRONT][2][2] == WHITE || _logicalCube[DOWN][0][2] == WHITE || _logicalCube[RIGHT][2][0] == WHITE) {
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

bool Pattern::Pattern::checkSecondCrown()
{
    turnToCenter(YELLOW);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (_logicalCube[BACK][i][j] != WHITE)
                return false;
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            if (_logicalCube[LEFT][i][j] != _logicalCube[LEFT][1][1])
                return false;
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            if (_logicalCube[UP][i][j] != _logicalCube[UP][1][1])
                return false;
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 1; j < 3; j++) {
            if (_logicalCube[RIGHT][i][j] != _logicalCube[RIGHT][1][1])
                return false;
        }
    }
    for (int i = 1; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (_logicalCube[DOWN][i][j] != _logicalCube[DOWN][1][1])
                return false;
        }
    }
    return true;
}

void Pattern::Pattern::secondCrown()
{
    while (checkSecondCrown() == false) {
        turnToCenter(YELLOW);
        printLogicalCube();
        std::array<FaceColor, 4> face_centers = {_logicalCube[UP][1][1], _logicalCube[DOWN][1][1], _logicalCube[RIGHT][1][1], _logicalCube[LEFT][1][1]};
        std::array<FaceColor, 2> arrete_haut = {_logicalCube[FRONT][0][1], _logicalCube[UP][2][1]};
        std::array<FaceColor, 2> arrete_droit = {_logicalCube[FRONT][1][2], _logicalCube[RIGHT][1][0]};
        std::array<FaceColor, 2> arrete_bas = {_logicalCube[FRONT][2][1], _logicalCube[DOWN][0][1]};
        std::array<FaceColor, 2> arrete_gauche = {_logicalCube[FRONT][1][0], _logicalCube[LEFT][1][2]};

        if (arrete_haut[0] != YELLOW && arrete_haut[1] != YELLOW) {
            if (arrete_haut[1] == face_centers[0]) {
                rotatex();
                rotatey();
                rotatey();
            } else if (arrete_haut[1] == face_centers[2]) {
                rotateFace(FRONT);
                rotatex();
                rotatey();
            } else if (arrete_haut[1] == face_centers[1]) {
                rotateFace(FRONT);
                rotateFace(FRONT);
                rotatex();
            } else if (arrete_haut[1] == face_centers[3]) {
                rotateFace(FRONT);
                rotateFace(FRONT);
                rotateFace(FRONT);
                rotatex();
                rotatey();
                rotatey();
                rotatey();
            }
            if (arrete_haut[0] == _logicalCube[LEFT][1][1]) {
                for (int i = 0; i < 3; i++)
                    rotateFace(UP);
                for (int i = 0; i < 3; i++)
                    rotateFace(LEFT);
                rotateFace(UP);
                rotateFace(LEFT);
                rotateFace(UP);
                for (int i = 0; i < 3; i++)
                    rotatey();
                rotateFace(RIGHT);
                for (int i = 0; i < 3; i++)
                    rotateFace(UP);
                for (int i = 0; i < 3; i++)
                    rotateFace(RIGHT);
                rotatey();
            } else if (arrete_haut[0] == _logicalCube[RIGHT][1][1]) {
                rotateFace(UP);
                rotateFace(RIGHT);
                for (int i = 0; i < 3; i++)
                    rotateFace(UP);
                for (int i = 0; i < 3; i++)
                    rotateFace(RIGHT);
                for (int i = 0; i < 3; i++)
                    rotateFace(UP);
                rotatey();
                for (int i = 0; i < 3; i++)
                    rotateFace(LEFT);
                rotateFace(UP);
                rotateFace(LEFT);
                for (int i = 0; i < 3; i++)
                    rotatey();
            }
            continue;
        } if (arrete_droit[0] != YELLOW && arrete_droit[1] != YELLOW) {
            for (int i = 0; i < 3; i++)
                rotateFace(FRONT);
            continue;
        } if (arrete_bas[0] != YELLOW && arrete_bas[1] != YELLOW) {
            rotateFace(FRONT);
            rotateFace(FRONT);
            continue;
        }  if (arrete_gauche[0] != YELLOW && arrete_gauche[1] != YELLOW) {
            rotateFace(FRONT);
            continue;
        }
        std::array<FaceColor, 2> ar_hd = {_logicalCube[UP][1][2], _logicalCube[RIGHT][0][1]};
        std::array<FaceColor, 2> ar_bd = {_logicalCube[RIGHT][2][1], _logicalCube[DOWN][1][2]};
        std::array<FaceColor, 2> ar_bg = {_logicalCube[DOWN][1][0], _logicalCube[LEFT][2][1]};
        std::array<FaceColor, 2> ar_hg = {_logicalCube[LEFT][0][1], _logicalCube[UP][1][0]};

        if (ar_hd[0] != YELLOW && ar_hd[1] != YELLOW) {
            rotatex();
            rotatey();
            for (int i = 0; i < 3; i++)
                rotateFace(UP);
            for (int i = 0; i < 3; i++)
                rotateFace(LEFT);
            rotateFace(UP);
            rotateFace(LEFT);
            rotateFace(UP);
            for (int i = 0; i < 3; i++)
                rotatey();
            rotateFace(RIGHT);
            for (int i = 0; i < 3; i++)
                rotateFace(UP);
            for (int i = 0; i < 3; i++)
                rotateFace(RIGHT);
            rotatey();
            continue;
        } if (ar_bd[0] != YELLOW && ar_bd[1] != YELLOW) {
            rotatex();
            for (int i = 0; i < 3; i++)
                rotateFace(UP);
            for (int i = 0; i < 3; i++)
                rotateFace(LEFT);
            rotateFace(UP);
            rotateFace(LEFT);
            rotateFace(UP);
            for (int i = 0; i < 3; i++)
                rotatey();
            rotateFace(RIGHT);
            for (int i = 0; i < 3; i++)
                rotateFace(UP);
            for (int i = 0; i < 3; i++)
                rotateFace(RIGHT);
            rotatey();
            continue;
        } if (ar_bg[0] != YELLOW && ar_bg[1] != YELLOW) {
            rotatex();
            for (int i = 0; i < 3; i++)
                rotatey();
            for (int i = 0; i < 3; i++)
                rotateFace(UP);
            for (int i = 0; i < 3; i++)
                rotateFace(LEFT);
            rotateFace(UP);
            rotateFace(LEFT);
            rotateFace(UP);
            for (int i = 0; i < 3; i++)
                rotatey();
            rotateFace(RIGHT);
            for (int i = 0; i < 3; i++)
                rotateFace(UP);
            for (int i = 0; i < 3; i++)
                rotateFace(RIGHT);
            rotatey();
            continue;
        } if (ar_hg[0] != YELLOW && ar_hg[1] != YELLOW) {
            rotatex();
            rotatey();
            rotatey();
            for (int i = 0; i < 3; i++)
                rotateFace(UP);
            for (int i = 0; i < 3; i++)
                rotateFace(LEFT);
            rotateFace(UP);
            rotateFace(LEFT);
            rotateFace(UP);
            for (int i = 0; i < 3; i++)
                rotatey();
            rotateFace(RIGHT);
            for (int i = 0; i < 3; i++)
                rotateFace(UP);
            for (int i = 0; i < 3; i++)
                rotateFace(RIGHT);
            rotatey();
            continue;
        }
    }
}

void Pattern::Pattern::yellowCross()
{
    std::cout << "After second crown:" << std::endl;
    printLogicalCube();
    int stop = 0;
    int count = 0;
    while (_logicalCube[FRONT][0][1] != YELLOW || _logicalCube[FRONT][1][0] != YELLOW
        || _logicalCube[FRONT][2][1] != YELLOW || _logicalCube[FRONT][1][2] != YELLOW || stop > 20) {
        turnToCenter(YELLOW);
        count = 0;
        std::array<FaceColor, 4> comptage_jaune = {_logicalCube[FRONT][0][1], _logicalCube[FRONT][1][2], _logicalCube[FRONT][2][1], _logicalCube[FRONT][1][0]};
        for (int i = 0; i < 4; i++) {
            if (comptage_jaune[i] == YELLOW)
                count++;
        }
        if (count == 0 || count == 1) {
            rotateFace(FRONT);
            rotateFace(RIGHT);
            rotateFace(UP);
            for (int i = 0; i < 3; i++)
                rotateFace(RIGHT);
            for (int i = 0; i < 3; i++)
                rotateFace(UP);
            for (int i = 0; i < 3; i++)
                rotateFace(FRONT);
        } if (count == 2 || count == 3) {
            if (comptage_jaune[0] == YELLOW && comptage_jaune[2] == YELLOW)
                rotateFace(UP);
            if (comptage_jaune[3] == YELLOW || comptage_jaune[1] == YELLOW) {
                rotateFace(FRONT);
                rotateFace(RIGHT);
                rotateFace(UP);
                for (int i = 0; i < 3; i++)
                    rotateFace(RIGHT);
                for (int i = 0; i < 3; i++)
                    rotateFace(UP);
                for (int i = 0; i < 3; i++)
                    rotateFace(FRONT);
                break;
            }
        } else {
            if (_logicalCube[FRONT][1][0] == YELLOW && _logicalCube[FRONT][2][1] == YELLOW)  {
                rotateFace(FRONT);
                rotateFace(FRONT);
                rotateFace(RIGHT);
                rotateFace(UP);
                for (int i = 0; i < 3; i++)
                    rotateFace(RIGHT);
                for (int i = 0; i < 3; i++)
                    rotateFace(UP);
                for (int i = 0; i < 3; i++)
                    rotateFace(FRONT);
            } else if (_logicalCube[FRONT][2][1] == YELLOW && _logicalCube[FRONT][1][2] == YELLOW) {
                rotateFace(FRONT);
                rotateFace(FRONT);
                rotateFace(FRONT);
                rotateFace(RIGHT);
                rotateFace(UP);
                for (int i = 0; i < 3; i++)
                    rotateFace(RIGHT);
                for (int i = 0; i < 3; i++)
                    rotateFace(UP);
                for (int i = 0; i < 3; i++)
                    rotateFace(FRONT);
            } else if (_logicalCube[FRONT][0][1] == YELLOW && _logicalCube[FRONT][1][2] == YELLOW) {
                // 4 F, so no need
                rotateFace(RIGHT);
                rotateFace(UP);
                for (int i = 0; i < 3; i++)
                    rotateFace(RIGHT);
                for (int i = 0; i < 3; i++)
                    rotateFace(UP);
                for (int i = 0; i < 3; i++)
                    rotateFace(FRONT);
            } else {
                rotateFace(FRONT);
                rotateFace(RIGHT);
                rotateFace(UP);
                for (int i = 0; i < 3; i++)
                    rotateFace(RIGHT);
                for (int i = 0; i < 3; i++)
                    rotateFace(UP);
                for (int i = 0; i < 3; i++)
                    rotateFace(FRONT);
            }
        }
        stop++;
    } 
}
