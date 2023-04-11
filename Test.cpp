#include "doctest.h"
#include <stdexcept>          // exptions
#include "sources/player.hpp" /////
#include "sources/game.hpp"   //libaries
#include "sources/card.hpp"   /////

using namespace ariel;
using namespace std;

// CHECK TEST #17

TEST_CASE("Stating game when every player gets his cards(26)")
{
    Player p1("Nikita");
    Player p2("Ruth");
    Game game(p1, p2);                               // every own gets 26 cards
    int sum_cards_p1_taken = p1.stacksize();         // 26
    int sum_cards_p2_taken = p2.stacksize();         // 26
    CHECK(sum_cards_p1_taken == sum_cards_p2_taken); ///////[CHECK]
    int sum_cards_p1_won = p1.cardesTaken();         // 0
    int sum_cards_p2_won = p2.cardesTaken();         // 0
    CHECK(sum_cards_p1_won == sum_cards_p2_won);     ///////[CHECK]
    // play own turn
    CHECK_NOTHROW(game.playTurn());      ///////[CHECK]
    CHECK_NOTHROW(game.printLastTurn()); ///////[CHECK]
    CHECK_THROWS(game.printWiner());     ///////[CHECK]
    CHECK(p1.stacksize() != 26);         ///////[CHECK]
    CHECK(p2.stacksize() != 26);         ///////[CHECK]
    // p1 one gets 1 card p2 gets 0 cards OR p1 one gets 0 cardS p2 gets 1 card
    CHECK(p1.cardesTaken() != p2.cardesTaken()); ///////[CHECK]
}

TEST_CASE("Play the game until the end and check what happens after the end")
{
    Player p1("Nikita");
    Player p2("Ruth");
    Game game(p1, p2);                   // every own gets 26 cards
    CHECK_NOTHROW(game.playAll());       ///////[CHECK]
    CHECK_NOTHROW(game.printWiner());    ///////[CHECK]
    CHECK_NOTHROW(game.printLog());      ///////[CHECK]
    CHECK_NOTHROW(game.printStats());    ///////[CHECK]
    CHECK_NOTHROW(game.printLastTurn()); ///////[CHECK]
    // game already end
    CHECK_THROWS(game.playTurn()); ///////[CHECK]
    CHECK_THROWS(game.playAll());  ///////[CHECK]
}

TEST_CASE("Errors with creation of Player Class and Game Class")
{
    CHECK_NOTHROW(Player p1("Nikita")); ///////[CHECK]
    Player p1("Nikita");
    Player p2("Ruth");
    CHECK_NOTHROW(Game game(p1, p2)); ///////[CHECK]
}

TEST_CASE("Play 4 turns and check what happens")
{
    Player p1("Nikita");
    Player p2("Ruth");
    Game game3(p1, p2);
    for (int i = 0; i < 4; i++)
    {
        game3.playTurn();
    }
    CHECK_NOTHROW(game3.printLastTurn()); ///////[CHECK]
    CHECK(p1.stacksize() < 26);           ///////[CHECK]
    CHECK(p2.stacksize() > 0);            ///////[CHECK]
    CHECK_THROWS(game3.playTurn());       ///////[CHECK]
    CHECK_THROWS(game3.playAll());        ///////[CHECK]
}
