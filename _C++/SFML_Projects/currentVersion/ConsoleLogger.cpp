#define _CRT_SECURE_NO_WARNINGS
#include "ConsoleLogger.hpp"
#include"Player.hpp"
#include"Enemy.hpp"
#include<chrono>
#include<iomanip>

ConsoleLogger::ConsoleLogger(Entity* ent) : ILogger(ent)
{
}

void ConsoleLogger::Update()
{
	std::cout << *this;
}

void ConsoleLogger::Update(Character* enem)
{
	std::string objName(typeid(*(GetEntity())).name());
	size_t n = objName.find(" ");
	std::cout << objName.c_str() + n + 1 << " attacked ";
	
	objName.clear();
	objName = std::string((typeid(*(enem)).name()));
	n = objName.find(" ");
	std::cout << objName.c_str() + n + 1 << "!" << std::endl;
}

std::ostream& operator<<(std::ostream& out, ConsoleLogger& log)
{
	std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	struct std::tm* ptm = std::localtime(&now);
	out << std::put_time(ptm, "%c") << ";\t";

	if (typeid(*(log.GetEntity())) == typeid(Player) ||
		typeid(*(log.GetEntity())) == typeid(Enemy1) ||
		typeid(*(log.GetEntity())) == typeid(Enemy2) ||
		typeid(*(log.GetEntity())) == typeid(Enemy3)) {
		Character* tmp = dynamic_cast<Character*>(log.GetEntity());
		if (tmp) {
			std::string objName(typeid(*(log.GetEntity())).name());
			size_t n = objName.find(" ");
			out << objName.c_str() + n + 1 << ";" << std::endl;
			out << "HP " << tmp->GetHP() << "; X " << tmp->GetX() << ", Y " << tmp->GetY() << "." << std::endl << std::endl;
		}
		else
			std::cout << "TROUBLES!!!!" << std::endl;
	}
	else if (typeid(*(log.GetEntity())) == typeid(Item)) {
		std::string objName(typeid(*(log.GetEntity())).name());
		size_t n = objName.find(" ");
		out << objName.c_str() + n + 1 << " WAS USED!" << std::endl;
	}

	return out;
}
