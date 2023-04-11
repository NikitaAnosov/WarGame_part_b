#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>

using namespace std;

namespace ariel{
 class Player{
    public:
        Player();
        Player(string);
        int stacksize();
        int cardesTaken();
    };
}
#endif

