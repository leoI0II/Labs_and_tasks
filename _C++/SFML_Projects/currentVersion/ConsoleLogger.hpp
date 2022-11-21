#ifndef CONSOLELOGGER_HPP
#define CONSOLELOGGER_HPP

#include"ILogger.hpp"
#include<iostream>

class Entity;
class Character;

class ConsoleLogger : virtual public ILogger
{
public:
	ConsoleLogger(Entity* ent = nullptr);
	ConsoleLogger(const ConsoleLogger&) = delete;
	ConsoleLogger& operator=(const ConsoleLogger&) = delete;

	friend std::ostream& operator<<(std::ostream& out, ConsoleLogger& log);
	void Update();
	void Update(Character*);

};

#endif //CONSOLELOGGER_HPP