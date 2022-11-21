#include "GameStats.hpp"

GameStats::GameStats(Player* player)
{
	playerChecker = player;
}

std::chrono::steady_clock::time_point& GameStats::GetStartTime()
{
	// TODO: вставьте здесь оператор return
	return gameStartTime;
}

void GameStats::startTime()
{
	gameStartTime = std::chrono::steady_clock::now();
}

void GameStats::kill()
{
	++killedEnemies;
}

size_t GameStats::getHowMuchKills() const
{
	return killedEnemies;
}


