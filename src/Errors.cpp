/*
** EPITECH PROJECT, 2025
** bsraytracer
** File description:
** ErrorClass
*/

#include "../includes/ErrorClass.hpp"

ErrorNS::ErrorClass::ErrorClass(const std::string &message) : _Message{message}
{}

void ErrorNS::ErrorClass::addMessage(const std::string &message)
{
    _Message += message;
}

void ErrorNS::ErrorClass::addMessage(const char *message)
{
    _Message += message;
}

void ErrorNS::ErrorClass::updateMessage(const std::string &message)
{
    _Message = message;
}

void ErrorNS::ErrorClass::updateMessage(const char *message)
{
    _Message = message;
}

const char *ErrorNS::ErrorClass::what() const noexcept
{
    return _Message.c_str();
}
