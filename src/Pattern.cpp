/*
** EPITECH PROJECT, 2025
** rubiks_cube_solver
** File description:
** Pattern
*/

#include "../includes/Pattern.hpp"

Pattern::Pattern::Pattern() : _begin(0)
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
    // FaceColor other_temp[3][3];

    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            temp[i][j] = _logicalCube[face_index][i][j];
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            _logicalCube[face_index][j][2 - i] = temp[i][j];
    // _logicalCube[face_index][0][0] = temp[2][0];
    // _logicalCube[face_index][0][1] = temp[2][1];
    // _logicalCube[face_index][0][2] = temp[2][2];
    // _logicalCube[face_index][2][0] = temp[0][0];
    // _logicalCube[face_index][2][1] = temp[0][1];
    // _logicalCube[face_index][2][2] = temp[0][2];
    // for (int j = 0; j < 3; ++j)
    //     for (int f = 0; f < 3; ++f)
    //         other_temp[j][f] = _logicalCube[face_index][j][f];
    // _logicalCube[face_index][0][1] = other_temp[1][0];
    // _logicalCube[face_index][0][2] = other_temp[2][0];
    // _logicalCube[face_index][1][0] = other_temp[0][1];
    // _logicalCube[face_index][2][0] = other_temp[0][2];
    // _logicalCube[face_index][2][1] = other_temp[1][2];
    // _logicalCube[face_index][1][2] = other_temp[2][1];
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
        _logicalCube[BACK][0][2 - i] = _logicalCube[LEFT][0][2 - i];
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
        _logicalCube[BACK][2][i] = _logicalCube[RIGHT][2][i];
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
    std::cout << "X" << std::endl;
    FaceColor temp[6][3][3];
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++)
                temp[i][j][k] = _logicalCube[i][j][k];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            _logicalCube[UP][i][j] = temp[FRONT][i][j];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            _logicalCube[BACK][i][j] = temp[UP][2 - i][2 - j];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            _logicalCube[DOWN][i][j] = temp[BACK][2 - i][2 - j];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            _logicalCube[FRONT][i][j] = temp[DOWN][i][j];
    for (int i = 0; i < 3; i++)
        classicRotate(LEFT);
    classicRotate(RIGHT);
}

void Pattern::Pattern::rotatey()
{
    std::cout << "Y" << std::endl;
    FaceColor temp[6][3][3];
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++)
                temp[i][j][k] = _logicalCube[i][j][k];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            _logicalCube[FRONT][i][j] = temp[RIGHT][i][j];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            _logicalCube[LEFT][i][j] = temp[FRONT][i][j];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            _logicalCube[BACK][i][j] = temp[LEFT][i][j];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            _logicalCube[RIGHT][i][j] = temp[BACK][i][j];
    classicRotate(UP);
    for (int i = 0; i < 3; i++)
        classicRotate(DOWN);
}

void Pattern::Pattern::rotatez()
{
    std::cout << "Z" << std::endl;
    FaceColor temp[6][3][3];

    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++)
                temp[i][j][k] = _logicalCube[i][j][k];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            _logicalCube[RIGHT][i][j] = temp[UP][2 - j][i];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            _logicalCube[DOWN][i][j] = temp[RIGHT][2 - j][i];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            _logicalCube[LEFT][i][j] = temp[DOWN][2 - j][i];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            _logicalCube[UP][i][j] = temp[LEFT][2 - j][i];
    classicRotate(FRONT);
    for (int i = 0; i < 3; i++)
        classicRotate(BACK);
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
    if (face == Pattern::MIDDLE)
        return "MIDDLE";
    if (face == Pattern::STANDING)
        return "STANDING";
    if (face == Pattern::EQUATOR)
        return "EQUATOR";
    return nullptr;
}

void Pattern::Pattern::rotateFace(int face_index)
{
    std::cout << getFace(static_cast<FaceName>(face_index)) << std::endl;
    switch (face_index) {
        case MIDDLE:
            rotateFace(RIGHT);
            for (int i = 0; i < 3; i++)
                rotateFace(LEFT);
            rotatex();
            return;
        case EQUATOR:
            rotateFace(UP);
            for (int i = 0; i < 3; i++)
                rotateFace(DOWN);
            for (int i = 0; i < 3; i++)
                rotatey();
            return;
        case STANDING:
            for (int i = 0; i < 3; i++)
                rotateFace(FRONT);
            rotateFace(BACK);
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

void Pattern::Pattern::enBas(FaceColor color)
{
    int i = 0;

    for (; i < 6; i++)
        if (_logicalCube[i][1][1] == color)
            break;
    while (_logicalCube[DOWN][1][1] != color) {
        if (_logicalCube[UP][1][1] == color
            || _logicalCube[BACK][1][1] == color
            || _logicalCube[FRONT][1][1] == color) {
            rotatex();
            continue;
        } else {
            rotatez();
            continue;
        }
    }
}

void Pattern::Pattern::scramble(int nb)
{
    const std::vector<char> moves = {
        'U', 'D', 'F', 'B', 'R', 'L', 'M', 'E', 'S', 'X', 'Y', 'Z'
    };

    std::mt19937 rng(static_cast<unsigned int>(std::time(nullptr)));
    std::uniform_int_distribution<> dist(0, moves.size() - 1);

    for (int i = 0; i < nb; ++i) {
        char move = moves[dist(rng)];

        switch (move) {
            case 'U': rotateFace(UP); break;
            case 'D': rotateFace(DOWN); break;
            case 'F': rotateFace(FRONT); break;
            case 'B': rotateFace(BACK); break;
            case 'L': rotateFace(LEFT); break;
            case 'R': rotateFace(RIGHT); break;
            case 'X': rotatex(); break;
            case 'Y': rotatey(); break;
            case 'Z': rotatez(); break;
            default: break;
        }
    }
    std::cout << "After scramble:" << std::endl;
    printLogicalCube();
}

bool Pattern::Pattern::isSolved()
{
    FaceColor center;

    for (int i = 0; i < 6; i++) {
        center = _logicalCube[i][1][1];
        for (int j = 0; j < 3; j++) {
            for (int f = 0; f < 3; f++) {
                if (_logicalCube[i][j][f] != center)
                    return false;
            }
        }
    }
    return true;
}
