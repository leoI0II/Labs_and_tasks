#define _CRT_SECURE_NO_WARNINGS
#include "FileLogger.hpp"
#include<chrono>
#include<ctime>
#include<iomanip>
//#include<iostream>

#include"Entity.hpp"
#include"Player.hpp"
#include"Enemy.hpp"

std::ofstream& operator<<(std::ofstream& out, FileLogger& log)
{
	std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	struct std::tm* ptm = std::localtime(&now);
	out << std::put_time(ptm, "%c");
	out << std::endl;

	if (typeid(*(log.GetEntity())) == typeid(Player) ||
		typeid(*(log.GetEntity())) == typeid(Enemy1) ||
		typeid(*(log.GetEntity())) == typeid(Enemy2) ||
		typeid(*(log.GetEntity())) == typeid(Enemy3)) {
		Character* tmp = dynamic_cast<Character*>(log.GetEntity());
		if (tmp) {
			std::string objName(typeid(*(log.GetEntity())).name());
			size_t n = objName.find(" ");
			out << objName.c_str() + n + 1;
			out << ";";
			out << std::endl;
			out << "HP ";
			out << tmp->GetHP();
			out << "; X ";
			out << tmp->GetX();
			out << ", Y ";
			out << tmp->GetY();
			out << ".";
			out << std::endl;
			out << std::endl;
			out.flush();
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

FileLogger::FileLogger(Entity* ent) : ILogger(ent), file("_log.txt", std::ios_base::out | std::ios_base::trunc)
{
	if (!file.is_open()) {
		std::cout << "Cant Open log file." << std::endl;
		exit(EXIT_FAILURE);
	}
}

FileLogger::~FileLogger()
{
	file.close();
}


void FileLogger::Update()
{
	file << *this;
}

void FileLogger::Update(Character* enem)
{
	/*Character* tmpCh = dynamic_cast<Character*>(entity);
	if (tmpCh) {*/
		std::string objName(typeid(*(GetEntity())).name());
		size_t n = objName.find(" ");
		file << objName.c_str() + n + 1 << " attacked ";
		
		objName.clear();
		objName = std::string((typeid(*(enem)).name()));
		n = objName.find(" ");
		file << objName.c_str() + n + 1 << "!" << std::endl;
	//}
}
