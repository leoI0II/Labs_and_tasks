#define _CRT_SECURE_NO_WARNINGS

#include "Logger.hpp"
//#include <iomanip>      // std::put_time

//template<LogType T>
//Logger<T>::Logger() : outFile("log.txt")
//{
//}
//
//template<LogType T>
//void Logger<T>::logTime()
//{
//	std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
//
//	struct std::tm* ptm = std::localtime(&now);
//	std::cout << std::put_time(ptm, "%c") << '\n';
//}