#ifndef CAFLOGGER_HPP
#define CAFLOGGER_HPP

#include"FileLogger.hpp"
#include"ConsoleLogger.hpp"

class CAFLogger : public FileLogger, public ConsoleLogger
{
public:
	CAFLogger(Entity* ent);
	CAFLogger(const CAFLogger&) = delete;
	CAFLogger& operator=(const CAFLogger&) = delete;

	void Update();
	void Update(Character* ch);

};

#endif //CAFLOGGER_HPP