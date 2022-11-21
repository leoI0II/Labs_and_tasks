#ifndef GAMESTATS_HPP
#define GAMESTATS_HPP

#include"Player.hpp"
#include<chrono>

class GameStats
{
public:
	GameStats(Player*);
	std::chrono::steady_clock::time_point& GetStartTime();
	void startTime();
	void kill();
	size_t getHowMuchKills() const;

private:
	Player* playerChecker = nullptr;
	size_t killedEnemies = 0;
	std::chrono::steady_clock::time_point gameStartTime;
};


#endif //GAMESTATS_HPP