#ifndef LOGGER_HPP
#define LOGGER_HPP

#include<fstream>
#include<chrono>
#include<ctime>
#include<iostream>
#include <iomanip>      // std::put_time

enum class LogType {FILE, CONSOLE, BOTH};

template<LogType T>
class Logger
{
public:
	Logger();

	template<class object_type>
	void log(const object_type& obj);
	void log(const std::string& str);
	void logTime();

private:
	std::ofstream outFile;
};

#endif //LOGGER_HPP

template<LogType T>
Logger<T>::Logger() : outFile("log.txt")
{
}

template<LogType T>
inline void Logger<T>::log(const std::string& str)
{
	if (T == LogType::BOTH) {
		std::cout << str << std::endl << std::endl;
		outFile << str << std::endl << std::endl;
	}
	else if (T == LogType::CONSOLE)
		std::cout << str << std::endl << std::endl;
	else
		outFile << str << str::endl << std::endl;
}

template<LogType T>
void Logger<T>::logTime()
{
	std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

	struct std::tm* ptm = std::localtime(&now);
	if (T == LogType::BOTH) {
		std::cout << std::put_time(ptm, "%c") << std::endl;
		outFile << std::put_time(ptm, "%c") << std::endl;
	}
	else if(T == LogType::CONSOLE)
		std::cout << std::put_time(ptm, "%c") << std::endl;
	else
		outFile << std::put_time(ptm, "%c") << std::endl;
}

template<LogType T>
template<class object_type>
void Logger<T>::log(const object_type& obj)
{
	std::string objName(typeid(object_type).name());
	size_t n = objName.find(" ");

	if (T == LogType::BOTH) {
		std::cout << objName.c_str() + n + 1 << ": " << obj.GetX() << " " << obj.GetY() <<
			"; Current HP: " << obj.GetHP() << std::endl << std::endl;
		outFile << objName.c_str() + n + 1 << ": " << obj.GetX() << " " << obj.GetY() <<
			"; Current HP: " << obj.GetHP() << std::endl << std::endl;
	}
	else if (T == LogType::CONSOLE) {
		std::cout << objName.c_str() + n + 1 << ": " << obj.GetX() << " " << obj.GetY() <<
			"; Current HP: " << obj.GetHP() << std::endl << std::endl;
	}
	else {
		outFile << objName.c_str() + n + 1 << ": " << obj.GetX() << " " << obj.GetY() <<
			"; Current HP: " << obj.GetHP() << std::endl << std::endl;
	}
}