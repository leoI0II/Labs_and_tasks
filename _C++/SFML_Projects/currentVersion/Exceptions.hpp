// #pragma once
#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include<exception>

class FileOpenExcept : public std::exception {
public:
    const char* what();
};

class TileCountError : std::exception {
public:
    const char* what();
};

#endif //EXCEPTIONS_HPP