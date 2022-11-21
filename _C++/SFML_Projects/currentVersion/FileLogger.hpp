#ifndef FILELOGGER_HPP
#define FILELOGGER_HPP

#include"ILogger.hpp"
#include<fstream>

class Entity;
class Character;

class FileLogger : virtual public ILogger {
public:
	FileLogger(Entity* ent = nullptr);
	FileLogger(const FileLogger&) = delete;
	FileLogger& operator=(const FileLogger&) = delete;
	~FileLogger();

	friend std::ofstream& operator<<(std::ofstream& out, FileLogger& log);
	void Update();
	void Update(Character*);

private:
	std::ofstream file;
};

#endif //FILELOGGER_HPP