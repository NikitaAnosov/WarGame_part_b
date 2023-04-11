#include "player.hpp"

using namespace ariel;
using namespace std;

// create a new player
Player::Player(string name) : playerName(name),
                              _sumOfCardsTaken(0), _stillPlay(false) {}

void Player::AddCard(Card new_Card){
    this->_stack.push_back(new_Card);// add card to player stack
}

void Player::DeleteCard(){
    this->_stack.pop_back();
}

int Player::stacksize() const { return this->_stack.size(); } 

Card Player::player_card(){
    // return last card from the stack
    Card card = this->_stack.back();
    DeleteCard();
    return card;
}