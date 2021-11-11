#ifndef PLAYERVIEW_HPP
#define PLAYERVIEW_HPP

#include<string>
using std::string;
#include"Player.hpp"

class PlayerView {
public:
    PlayerView(Player* ptr, const string& fp) : player(ptr), filePath(fp) {}

    const string getFP() const{
        return filePath;
    }
    void update(double time){
        player->update(time);
    }

private:
    Player* player;
    string filePath;
};


#endif //PLAYERVIEW_HPP