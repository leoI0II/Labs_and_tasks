#include "CAFLogger.hpp"

CAFLogger::CAFLogger(Entity* ent) : ILogger(ent), ConsoleLogger(ent), FileLogger(ent)
{
}

void CAFLogger::Update()
{
	ConsoleLogger::Update();
	FileLogger::Update();
}

void CAFLogger::Update(Character* ch)
{
	ConsoleLogger::Update(ch);
	FileLogger::Update(ch);
}
