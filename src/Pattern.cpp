/*
** EPITECH PROJECT, 2025
** rubiks_cube_solver
** File description:
** Pattern
*/

#include "../includes/Pattern.hpp"

Pattern::Pattern::Pattern()
{
    for (int f = 0; f < 6; ++f) {
        FaceColor color = static_cast<FaceColor>(f);
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                _logicalCube[f][i][j] = color;
    }
}

Pattern::Pattern::~Pattern()
{
}

void Pattern::Pattern::classicRotate(int face_index)
{
    FaceColor temp[3][3];
    FaceColor other_temp[3][3];

    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            temp[i][j] = _logicalCube[face_index][i][j];
    _logicalCube[face_index][0][0] = temp[2][0];
    _logicalCube[face_index][0][1] = temp[2][1];
    _logicalCube[face_index][0][2] = temp[2][2];
    _logicalCube[face_index][2][0] = temp[0][0];
    _logicalCube[face_index][2][1] = temp[0][1];
    _logicalCube[face_index][2][2] = temp[0][2];
    for (int j = 0; j < 3; ++j)
        for (int f = 0; f < 3; ++f)
            other_temp[j][f] = _logicalCube[face_index][j][f];
    _logicalCube[face_index][0][1] = other_temp[1][0];
    _logicalCube[face_index][0][2] = other_temp[2][0];
    _logicalCube[face_index][1][0] = other_temp[0][1];
    _logicalCube[face_index][2][0] = other_temp[0][2];
    _logicalCube[face_index][2][1] = other_temp[1][2];
    _logicalCube[face_index][1][2] = other_temp[2][1];
}

void Pattern::Pattern::up(FaceColor temp[3])
{
    for (int i = 0; i < 3; ++i)
        temp[i] = _logicalCube[FRONT][0][i];
    for (int i = 0; i < 3; ++i)
        _logicalCube[FRONT][0][i] = _logicalCube[RIGHT][0][i];
    for (int i = 0; i < 3; ++i)
        _logicalCube[RIGHT][0][i] = _logicalCube[BACK][0][i];
    for (int i = 0; i < 3; ++i)
        _logicalCube[BACK][0][2 - i] = _logicalCube[LEFT][0][i];
    for (int i = 0; i < 3; ++i)
        _logicalCube[LEFT][0][i] = temp[i];
}

void Pattern::Pattern::down(FaceColor temp[3])
{
    for (int i = 0; i < 3; ++i)
        temp[i] = _logicalCube[FRONT][2][i];
    for (int i = 0; i < 3; ++i)
        _logicalCube[FRONT][2][i] = _logicalCube[LEFT][2][i];
    for (int i = 0; i < 3; ++i)
        _logicalCube[LEFT][2][i] = _logicalCube[BACK][2][i];
    for (int i = 0; i < 3; ++i)
        _logicalCube[BACK][2][2 - i] = _logicalCube[RIGHT][2][i];
    for (int i = 0; i < 3; ++i)
        _logicalCube[RIGHT][2][i] = temp[i];
}

void Pattern::Pattern::front(FaceColor temp[3])
{
    for (int i = 0; i < 3; ++i)
        temp[i] = _logicalCube[UP][2][i];
    for (int i = 0; i < 3; ++i)
        _logicalCube[UP][2][i] = _logicalCube[LEFT][2 - i][2];
    for (int i = 0; i < 3; ++i)
        _logicalCube[LEFT][i][2] = _logicalCube[DOWN][0][i];
    for (int i = 0; i < 3; ++i)
        _logicalCube[DOWN][0][i] = _logicalCube[RIGHT][2 - i][0];
    for (int i = 0; i < 3; ++i)
        _logicalCube[RIGHT][i][0] = temp[i];
}

void Pattern::Pattern::right(FaceColor temp[3])
{
    for (int i = 0; i < 3; ++i)
        temp[i] = _logicalCube[UP][i][2];
    for (int i = 0; i < 3; ++i)
        _logicalCube[UP][i][2] = _logicalCube[FRONT][i][2];
    for (int i = 0; i < 3; ++i)
        _logicalCube[FRONT][i][2] = _logicalCube[DOWN][i][2];
    for (int i = 0; i < 3; ++i)
        _logicalCube[DOWN][i][2] = _logicalCube[BACK][2 - i][0];
    for (int i = 0; i < 3; ++i)
        _logicalCube[BACK][2 - i][0] = temp[i];
}

void Pattern::Pattern::left(FaceColor temp[3])
{
    for (int i = 0; i < 3; ++i)
        temp[i] = _logicalCube[UP][i][0];
    for (int i = 0; i < 3; ++i)
        _logicalCube[UP][i][0] = _logicalCube[BACK][2 - i][2];
    for (int i = 0; i < 3; ++i)
        _logicalCube[BACK][i][2] = _logicalCube[DOWN][2 - i][0];
    for (int i = 0; i < 3; ++i)
        _logicalCube[DOWN][i][0] = _logicalCube[FRONT][i][0];
    for (int i = 0; i < 3; ++i)
        _logicalCube[FRONT][i][0] = temp[i];
}

void Pattern::Pattern::back(FaceColor temp[3])
{
    for (int i = 0; i < 3; ++i)
        temp[i] = _logicalCube[UP][0][i];
    for (int i = 0; i < 3; ++i)
        _logicalCube[UP][0][i] = _logicalCube[RIGHT][i][2];
    for (int i = 0; i < 3; ++i)
        _logicalCube[RIGHT][i][2] = _logicalCube[DOWN][2][2 - i];
    for (int i = 0; i < 3; ++i)
        _logicalCube[DOWN][2][i] = _logicalCube[LEFT][i][0];
    for (int i = 0; i < 3; ++i)
        _logicalCube[LEFT][i][0] = temp[2 - i];
}

void Pattern::Pattern::rotatex()
{
    FaceColor temp[6][3][3];

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 3; j++)
            for (int f = 0; f < 3; f++)
                temp[i][j][f] = _logicalCube[i][j][f];
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            _logicalCube[FRONT][i][j] = temp[UP][i][j];
            _logicalCube[DOWN][i][j] = temp[FRONT][i][j];
            _logicalCube[BACK][i][j] = temp[DOWN][i][j];
            _logicalCube[UP][i][j] = temp[BACK][i][j];
        }
    }
}

void Pattern::Pattern::rotatey()
{
    FaceColor temp[6][3][3];

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 3; j++)
            for (int f = 0; f < 3; f++)
                temp[i][j][f] = _logicalCube[i][j][f];
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            _logicalCube[FRONT][i][j] = temp[LEFT][i][j];
            _logicalCube[RIGHT][i][j] = temp[FRONT][i][j];
            _logicalCube[BACK][i][j] = temp[RIGHT][i][j];
            _logicalCube[LEFT][i][j] = temp[BACK][i][j];
        }
    }
}

void Pattern::Pattern::rotatez()
{
    FaceColor temp[6][3][3];

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 3; j++)
            for (int f = 0; f < 3; f++)
                temp[i][j][f] = _logicalCube[i][j][f];
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            _logicalCube[UP][i][j] = temp[RIGHT][i][j];
            _logicalCube[LEFT][i][j] = temp[UP][i][j];
            _logicalCube[DOWN][i][j] = temp[LEFT][i][j];
            _logicalCube[RIGHT][i][j] = temp[DOWN][i][j];
        }
    }
    for (int i = 0; i < 3; i++) {
        classicRotate(UP);
        classicRotate(LEFT);
        classicRotate(DOWN);
        classicRotate(RIGHT);
        classicRotate(FRONT);
        classicRotate(BACK);
    }
}

void Pattern::Pattern::rotateFace(int face_index)
{
    switch (face_index) {
        case MIDDLE:
            rotateFace(RIGHT);
            rotateFaceP(LEFT);
            rotatex();
            return;
        case EQUATOR:
            rotateFace(UP);
            rotateFaceP(DOWN);
            rotatey();
            return;
        case STANDING:
            rotateFaceP(FRONT);
            rotateFace(BACK);
            for (int i = 0; i < 3; i++)
                rotatez();
            return;
        default:
            break;
    }

    classicRotate(face_index);
    FaceColor temp2[3];
    if (face_index == UP) {
        up(temp2);
    } else if (face_index == DOWN) {
        down(temp2);
    } else if (face_index == FRONT) {
        front(temp2);
    } else if (face_index == BACK) {
        back(temp2);
    } else if (face_index == RIGHT) {
        right(temp2);
    } else if (face_index == LEFT) {
        left(temp2);
    } else if (face_index == X) {
        rotatex();
    } else if (face_index == Y) {
        rotatey();
    } else if (face_index == Z) {
        rotatez();
    }
}

void Pattern::Pattern::rotateFaceP(int face_index)
{
    FaceColor temp[3][3];
    FaceColor other_temp[3][3];

    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            temp[i][j] = _logicalCube[face_index][i][j];
    _logicalCube[face_index][0][0] = temp[2][0];
    _logicalCube[face_index][0][1] = temp[2][1];
    _logicalCube[face_index][0][2] = temp[2][2];
    _logicalCube[face_index][2][0] = temp[0][0];
    _logicalCube[face_index][2][1] = temp[0][1];
    _logicalCube[face_index][2][2] = temp[0][2];
    for (int j = 0; j < 3; ++j)
        for (int f = 0; f < 3; ++f)
            other_temp[j][f] = _logicalCube[face_index][j][f];
    _logicalCube[face_index][0][1] = other_temp[1][0];
    _logicalCube[face_index][0][2] = other_temp[2][0];
    _logicalCube[face_index][1][0] = other_temp[0][1];
    _logicalCube[face_index][2][0] = other_temp[0][2];
    _logicalCube[face_index][2][1] = other_temp[1][2];
    _logicalCube[face_index][1][2] = other_temp[2][1];
    FaceColor temp2[3];
    if (face_index == UP) {
        for (int i = 0; i < 3; i++)
            up(temp2);
    } else if (face_index == DOWN) {
        for (int i = 0; i < 3; i++)
            down(temp2);
    } else if (face_index == FRONT) {
        for (int i = 0; i < 3; i++)
            front(temp2);
    } else if (face_index == BACK) {
        for (int i = 0; i < 3; i++)
            back(temp2);
    } else if (face_index == RIGHT) {
        for (int i = 0; i < 3; i++)
            right(temp2);
    } else if (face_index == LEFT) {
        for (int i = 0; i < 3; i++)
            left(temp2);
    }
}

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

static std::string getFace(Pattern::FaceName face)
{
    if (face == Pattern::UP)
        return "UP";
    if (face == Pattern::DOWN)
        return "DOWN";
    if (face == Pattern::FRONT)
        return "FRONT";
    if (face == Pattern::RIGHT)
        return "RIGHT";
    if (face == Pattern::LEFT)
        return "LEFT";
    if (face == Pattern::BACK)
        return "BACK";
    return nullptr;
}

void Pattern::Pattern::printLogicalCube()
{
    for (int f = 0; f < 6; ++f) {
        std::cout << "Face " << getFace(static_cast<FaceName>(f)) << ":" << std::endl;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j)
                std::cout << getColor(_logicalCube[f][i][j]) << " ";
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}

