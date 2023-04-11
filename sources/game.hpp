#ifndef GAME_HPP
#define GAME_HPP

#include "player.hpp"
#include "card.hpp"
#include <iostream>
#include <vector>
#include <random>

namespace ariel
{
    class Game
    {
    public:
        Game(Player &player1, Player &player2);
        void playTurn();
        void playAll();
        void newDeckOfCards(); // create a new deck of 52 cards (shuffeled)

        //print the last turn stats
        void printLastTurn() const {cout << "\nLast turn stats:\n" << _turn_stats << endl;};

        // prints the name of the winning player
        void printWiner() const;

        //prints all the turns played one line per turn
        void printLog() const {cout << "\nAll the turns that be played:\n" << _game_stats << endl;};

        //for each player prints basic statistics: win rate, cards won, <other stats you want to print>.
        // Also print the draw rate and amount of draws that happand. 
        //(draw within a draw counts as 2 draws. )
        void printStats() const;

    private:
        Player &_player_1;
        Player &_player_2;
        vector<Card> _stackGame;// stack of all cards
        int _count_turns;// how many turns left
        int _count_GameDraws;// how many draws
        int _numOfPlayingCards;// how many cards players use
        string _turn_stats;
        string _game_stats;
    };
}

#endif
