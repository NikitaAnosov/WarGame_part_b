#include "game.hpp"
// simple realiztion
using namespace ariel;

//defult
Game::Game(){
}
Game::Game(Player firstPlayer, Player secondPlayer)
{
    this->p1 = firstPlayer;
    this->p2 = secondPlayer;
}

void Game::playTurn()
{//Nothing
}
//playes the game untill the end
void Game::playAll()
{//Nothing
}
// print the last turn stats
void Game::printLastTurn()
{//Nothing
}
// prints the name of the winning player
void Game::printWiner() 
{//Nothing
}
// prints all the turns played one 
//line per turn (same format as game.printLastTurn())
void Game::printLog()
{//Nothing
}
// for each player prints basic statistics: win rate, 
//cards won, <other stats you want to print>. Also print the draw rate and 
//amount of draws that happand. (draw within a draw counts as 2 draws. )
void Game::printStats()
{//Nothing
}
