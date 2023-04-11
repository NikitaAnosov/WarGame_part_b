#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <vector>
#include "card.hpp"

using namespace std;

namespace ariel
{
    class Player
    {
    public:
        Player(string name); // name does not change
        string gePlayertName() const { return playerName; };
        int stacksize() const;//outline
        int cardesTaken() const { return _sumOfCardsTaken; }// inline //get
        bool isPlaying() const { return _stillPlay; }; // true/false if player still play
        void AddCard(Card);
        void AddToCountCardsTaken(){_sumOfCardsTaken++;}
        void DeleteCard();
        void gameStatusPlayer(bool status){ this->_stillPlay = status;}; // update if player still play the game
        Card player_card();

    private:
        string playerName;
        vector<Card> _stack;
        int _sumOfCardsTaken; // how many cards player won (starts from 0)
        bool _stillPlay;      // true/false if player still play
    };
}
#endif

