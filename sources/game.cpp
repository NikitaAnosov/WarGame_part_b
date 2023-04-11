#include "game.hpp"
#include "player.hpp"
#include "card.hpp"
#include <algorithm>
#include <random>
#include <iostream>

using namespace ariel;
using namespace std;

// create a new Game!
Game::Game(Player &p1, Player &p2) : _player_1(p1), _player_2(p2), _count_turns(0),
                                    _count_GameDraws(0), _numOfPlayingCards(0)
{
    // check if the players are play different game
    if (_player_1.isPlaying() == true && _player_2.isPlaying() == true)
    {
        throw invalid_argument("player/s still play different game");
    }
    // update the stsatus of the players
    _player_1.gameStatusPlayer(true);
    _player_2.gameStatusPlayer(true);
    // give for each player 26 shuffeled cards
    this->newDeckOfCards();
}

void Game::playTurn()
{
    // check case_test one person
    if (&this->_player_1 == &this->_player_2)
    {
        throw exception();
    }
    // check case_test Activating another turn after the game is over
    if (this->_player_1.stacksize() == 0 || this->_player_2.stacksize() == 0)
    {
        throw exception();
    }

    int num_draw_round = 0;
    // each player got 26 cards so game runs not more 26 rounds
    if (this->_numOfPlayingCards < 26) // starts from 0
    {
        this->_numOfPlayingCards++;
        this->_count_turns++;
        Card p1_card = this->_player_1.player_card();
        Card p2_card = this->_player_2.player_card();

        // add data to last turn
        // example: Alice played Queen of Hearts Bob played 5 of Spades. Alice wins.
        this->_turn_stats = this->_player_1.gePlayertName() + " played " + p1_card.toString() + " " +
                            this->_player_2.gePlayertName() + " played " + p2_card.toString() + ". ";

        //
        // if p1 card bigger return 1 if smaller return -1 else 0 //
        //

        // player 1 == player 2
        while (p1_card.compareTo_card(p2_card) == 0)
        {
            this->_turn_stats += " Draw. "; // update last turn stats
            this->_count_GameDraws++;
            this->_numOfPlayingCards++; // loop of draws
            num_draw_round++;
            // check if stack size is 1 card or none
            if (this->_player_1.stacksize() == 1 && this->_player_2.stacksize() == 1)
            {
                // p1= 1 card up + 1 card down (also for p2)
                this->_player_1.AddToCountCardsTaken();
                this->_player_1.DeleteCard();
                this->_player_1.AddToCountCardsTaken();

                this->_player_2.AddToCountCardsTaken();
                this->_player_2.DeleteCard();
                this->_player_2.AddToCountCardsTaken();
                return;
            }
            if (this->_player_1.stacksize() == 0 && this->_player_2.stacksize() == 0)
            {
                // return 1 card for each player
                this->_player_1.AddToCountCardsTaken();
                this->_player_2.AddToCountCardsTaken();

                return;
            }

            // delete own upsdie downcard from each player
            this->_player_1.DeleteCard();
            this->_player_2.DeleteCard();
            // get two new cards
            p1_card = this->_player_1.player_card();
            p2_card = this->_player_2.player_card();
            // add data to last turn - after the "Draw"
            this->_turn_stats = this->_player_1.gePlayertName() + " played " + p1_card.toString() + " " +
                                this->_player_2.gePlayertName() + " played " + p2_card.toString() + ". ";
        }

        // player 1 > player 2
        if (p1_card.compareTo_card(p2_card) == 1)
        {
            // if num_draw_round = 1 -> 2 cards put upside down and 2 cards put up
            // so :  4 * (each round of draw)
            for (int i = 0; i < num_draw_round * 4; i++)
            {
                this->_player_1.AddToCountCardsTaken();
            }
            // 2 cards 1 from winner + 1 from looser
            this->_player_1.AddToCountCardsTaken();
            this->_player_1.AddToCountCardsTaken();
            this->_turn_stats += this->_player_1.gePlayertName() + " wins."; // update last turn stats
        }

        // player 1 < player 2
        if (p1_card.compareTo_card(p2_card) == -1)
        {
            // if num_draw_round = 1 -> 2 cards put upside down and 2 cards put up
            // so :  4 * (each round of draw)
            for (int i = 0; i < num_draw_round * 4; i++)
            {
                this->_player_2.AddToCountCardsTaken();
            }
            this->_player_2.AddToCountCardsTaken();
            this->_player_2.AddToCountCardsTaken();
            this->_turn_stats += this->_player_2.gePlayertName() + " wins."; // update last turn stats
        }
        // add all turn stats to game stats
        this->_game_stats += this->_turn_stats + "\n";
    }
};

void Game::playAll()
{
    while (this->_player_1.stacksize() > 0 && this->_player_1.stacksize() > 0)
    {
        // call to playTurn() func (max 26 times)
        this->playTurn();
    }
};

void Game::newDeckOfCards()
{
    this->_stackGame.clear(); // clean stack
    // create a deck of 52 cards
    for (int i = 1; i < 14; i++) // 13 cards of own suit
    {
        for (int j = 1; j < 5; j++) // 4 suits
        {
            // Card(Rank rank, Suit suit);
            this->_stackGame.push_back(Card(static_cast<Rank>(i), static_cast<Suit>(j)));
        }
    }

    // shuffle with random
    random_device randomCard;   // generates non deterministic random numbers
    mt19937 rand(randomCard()); // pseudorandom number generator
    shuffle(this->_stackGame.begin(), this->_stackGame.end(), rand);

    // split the deck (52/2 = 26)
    int half_Deck_Size = 52 / 2;
    while (half_Deck_Size > 0)
    {
        // each player get card from the stack of cards and after it pop the card from
        //  the stack so the second will get different card and the stack in the last
        //  iteration will be empty

        // first player gets 26 cards
        this->_player_1.AddCard(this->_stackGame.back());
        this->_stackGame.pop_back();
        // second player gets 26 cards
        this->_player_2.AddCard(this->_stackGame.back());
        this->_stackGame.pop_back();
        half_Deck_Size--;
    }
}

void Game::printWiner() const
{
    // player 1 > player 2
    if (this->_player_1.cardesTaken() > this->_player_2.cardesTaken())
    {
        cout << this->_player_1.gePlayertName() << " wins!" << endl;
    }

    // player 1 < player 2
    if (this->_player_1.cardesTaken() < this->_player_2.cardesTaken())
    {
        cout << this->_player_2.gePlayertName() << " wins!" << endl;
    }

    // player 1 = player 2
    if (this->_player_1.cardesTaken() == this->_player_2.cardesTaken())
    {
        cout << "Its a Draw!" << endl;
    }
};
void Game::printStats() const {
    // for each player prints basic statistics:
    // win rate, cards won, <other stats you want to print>.
    // Also print the draw rate and amount of draws that happand. (draw within a draw counts as 2 draws. )
    cout << "\nPlayers statistics: "<< endl;

    //player 1
    double p1_cards =  (double)this->_player_1.cardesTaken();
    cout << "Player 1: " << this->_player_1.gePlayertName() << endl;
    double win_rate = 100 * p1_cards / 52;
    cout << "\twin rate: " << win_rate << "%" << endl;
    cout << "\tcards won: " << p1_cards <<endl;

    //player 2
    double p2_cards =  (double)this->_player_2.cardesTaken();
    cout << "Player 2: " << this->_player_2.gePlayertName() << endl;
    win_rate = 100 * p2_cards / 52;
    cout << "\twin rate: " << win_rate << "%" << endl;
    cout << "\tcards won: " << p2_cards << endl;

    cout << "Turns amount: " << this->_count_turns << endl;
    double drate = (double)this->_count_GameDraws / this->_count_turns ;
    int draw_rate = drate * 100;
    cout << "Draw rate: " << draw_rate <<"%" << endl;
    cout << "Draw amount: " << this->_count_GameDraws << endl;

};