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

void Pattern::Pattern::up(FaceColor temp[3])
{
    std::cout << "Rotating UP face" << std::endl;
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
    std::cout << "Rotating DOWN face" << std::endl;
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
    std::cout << "Rotating FRONT face" << std::endl;
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
    std::cout << "Rotating RIGHT face" << std::endl;
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
    std::cout << "Rotating LEFT face" << std::endl;
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
    std::cout << "Rotating BACK face" << std::endl;
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

void Pattern::Pattern::rotateFace(int face_index)
{
    if (face_index == MIDDLE) {
        rotateFace(RIGHT);
        rotateFaceP(LEFT);
        return;
    } if (face_index == EQUATOR) {
        rotateFace(UP);
        rotateFaceP(DOWN);
        return;
    } if (face_index == STANDING) {
        rotateFaceP(FRONT);
        rotateFace(BACK);
        return;
    }

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
