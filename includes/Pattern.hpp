/*
** EPITECH PROJECT, 2025
** rubiks_cube_solver
** File description:
** Pattern
*/

#pragma once
#include "libs.hpp"

namespace Pattern
{
    enum FaceColor {
        WHITE = 0,   // UP
        YELLOW,  // DOWN
        GREEN,   // FRONT
        BLUE,    // BACK
        ORANGE,  // LEFT
        RED      // RIGHT
    };

    enum FaceName {
        UP = 0,
        DOWN,
        FRONT,
        BACK,
        LEFT,
        RIGHT,
        MIDDLE,
        EQUATOR,
        STANDING,
        X,
        Y,
        Z
    };

    enum Dictionary {
        UP_ = 0,
        DOWN_,
        RIGHT_,
        LEFT_
    };

    class Pattern {
        public:
            Pattern();
            ~Pattern();
            std::string solve();
            void reset();
            const FaceColor (&getLogicalCube() const)[6][3][3] {
                return _logicalCube;
            }
            int getBegin() const {
                return _begin;
            }
            void setBegin(int begin) {
                _begin = begin;
            }

            void classicRotate(int face_index);
            void up(FaceColor temp[3]);
            void down(FaceColor temp[3]);
            void front(FaceColor temp[3]);
            void right(FaceColor temp[3]);
            void left(FaceColor temp[3]);
            void back(FaceColor temp[3]);
            void rotatex();
            void rotatey();
            void rotatez();
            void rotateFace(int face_index);
            void scramble(int nb);
            bool isDoable();
            bool isSolved();

            void printLogicalCube();
            void turnToCenter(FaceColor face);
            void enBas(FaceColor color);
            void makeMargueritte();
            void whiteCross();
            bool checkWhiteCorners();
            bool checkOneCorner(std::array<FaceColor, 3> corner, FaceColor color);
            void whiteCorners();
            bool checkSecondCrown();
            void secondCrown();
            void yellowCross();

        protected:
        private:
            FaceColor _logicalCube[6][3][3];
            std::string _solution;
            int _begin;
    };
}
