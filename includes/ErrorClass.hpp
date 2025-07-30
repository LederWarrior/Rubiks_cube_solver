/*
** EPITECH PROJECT, 2025
** Rubiks_cube_solver
** File description:
** ErrorClass
*/

#pragma once

#include "libs.hpp"

namespace ErrorNS
{
    class ErrorClass : public std::exception
    {
        public:
            ErrorClass() = default;
            explicit ErrorClass(const std::string &message);
            ~ErrorClass() = default;
            void updateMessage(const std::string &message);
            void updateMessage(const char *message);
            void addMessage(const std::string &message);
            void addMessage(const char *message);
            const char *what() const noexcept override;
        protected:
            std::string _Message;
    };
    class ExecError : public ErrorClass {
        public:
            ExecError(const std::string &message);
            ~ExecError() = default;
    };
}
