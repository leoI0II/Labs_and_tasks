#include "Exceptions.hpp"

const char* TileCountError::what() { return "Error in the number of tile in a line. Recheck the file."; }

const char* FileOpenExcept::what() { return "Error opening file. Recheck the file."; }