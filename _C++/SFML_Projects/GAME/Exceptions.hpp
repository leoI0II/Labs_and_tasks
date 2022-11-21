#ifndef EXCEPTIONS
#define EXCEPTIONS

#include<exception>


class FileOpenExcept : public std::exception{
public:
    const char* what(){ return "Error opening file. Recheck the file."; }

};
class TileCountError : std::exception{
public:
    const char* what(){ return "Error in the number of tile in a line. Recheck the file."; }
};



#endif ///EXCEPTIONS