#ifndef ILOGGER_HPP
#define ILOGGER_HPP

#include"Observer.hpp"
#include"Entity.hpp"

class ILogger : public Observer
{
public:
	ILogger(Entity* ent = nullptr);
	ILogger(const ILogger&) = delete;
	ILogger& operator=(const ILogger&) = delete;

	void SetEntity(Entity* ent);
	void DelEntity();

	Entity* GetEntity();

private:
	Entity* entity;
};

#endif //ILOGGER_HPP