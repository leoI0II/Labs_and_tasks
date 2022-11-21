#include "ILogger.hpp"

ILogger::ILogger(Entity* ent) : entity(ent)
{
}

void ILogger::SetEntity(Entity* ent)
{
	entity = ent;
}

void ILogger::DelEntity()
{
	entity = nullptr;
}

Entity* ILogger::GetEntity()
{
	return entity;
}
