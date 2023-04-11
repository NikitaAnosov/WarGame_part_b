#ifndef GAME_HPP
#define GAME_HPP

#include "player.hpp"


namespace ariel {
    class Game {
    public:
        Game();
        Game(Player , Player );
        void playTurn();
        void playAll();
        void printLastTurn() ;
        void printWiner() ;
        void printLog() ;
        void printStats() ;
    private:
        Player p1;
        Player p2;

    };
}

#endif
