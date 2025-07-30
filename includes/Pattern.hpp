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

    class Pattern {
        public:
            Pattern();
            ~Pattern();
            bool isDoable();
            std::string solve();
            void reset();
            const FaceColor (&getLogicalCube() const)[6][3][3] {
                return _logicalCube;
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
            void rotateFaceP(int face_index);
            void printLogicalCube();

        protected:
        private:
            FaceColor _logicalCube[6][3][3];
    };

    // class Square {
    //     public:
    //         Square();
    //         ~Square();
    //         void setColor();
    //     private:
    //         sf::RectangleShape _rect;
    //         sf::Color _color;
    //         int _coordinates[3];
    //         std::pair<int, int> _real_cos;
    // };

    // class IFace {
    //     public:
    //         virtual ~IFace() = default;
    //         virtual void setGlobalColor() = 0;
    //         virtual void setCoordinates() = 0; // top left
    //         virtual void setSize() = 0;
    //         virtual void show() = 0;
    //         virtual std::pair<int, int> getCoordinates() = 0;
    //         virtual sf::Color getGlobalColor() = 0;
    //     protected:
    //         sf::Color _color;
    //         std::vector<std::shared_ptr<Square>> _squares;
    // };

    // class CenterFace : public IFace {
    //     public:
    //         CenterFace();
    //         ~CenterFace();
    //         void setGlobalColor() override;
    //         void setCoordinates() override;
    //         void setSize() override;
    //         void show() override;
    //         std::pair<int, int> getCoordinates() override;
    //         sf::Color getGlobalColor() override;
    // };

    // class TopFace : public IFace {
    //     public:
    //         TopFace();
    //         ~TopFace();
    //         void setGlobalColor() override;
    //         void setCoordinates() override;
    //         void setSize() override;
    //         void show() override;
    //         std::pair<int, int> getCoordinates() override;
    //         sf::Color getGlobalColor() override;
    // };

    // class BottomFace : public IFace {
    //     public:
    //         BottomFace();
    //         ~BottomFace();
    //         void setGlobalColor() override;
    //         void setCoordinates() override;
    //         void setSize() override;
    //         void show() override;
    //         std::pair<int, int> getCoordinates() override;
    //         sf::Color getGlobalColor() override;
    // };

    // class RightFace : public IFace {
    //     public:
    //         RightFace();
    //         ~RightFace();
    //         void setGlobalColor() override;
    //         void setCoordinates() override;
    //         void setSize() override;
    //         void show() override;
    //         std::pair<int, int> getCoordinates() override;
    //         sf::Color getGlobalColor() override;
    // };

    // class LeftFace : public IFace {
    //     public:
    //         LeftFace();
    //         ~LeftFace();
    //         void setGlobalColor() override;
    //         void setCoordinates() override;
    //         void setSize() override;
    //         void show() override;
    //         std::pair<int, int> getCoordinates() override;
    //         sf::Color getGlobalColor() override;
    // };

    // class BackFace : public IFace {
    //     public:
    //         BackFace();
    //         ~BackFace();
    //         void setGlobalColor() override;
    //         void setCoordinates() override;
    //         void setSize() override;
    //         void show() override;
    //         std::pair<int, int> getCoordinates() override;
    //         sf::Color getGlobalColor() override;
    // };
}
