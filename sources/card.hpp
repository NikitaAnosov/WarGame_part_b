#ifndef CARD_HPP
#define CARD_HPP
#include <string>
using namespace std;

namespace ariel
{
    // cards list
    enum Suit
    {
        CLUBS = 1,
        DIAMONDS,
        HEARTS,
        SPADES //=4
    };
    enum Rank
    {
        ACE = 1,
        TWO,
        THREE,
        FOUR,
        FIVE,
        SIX,
        SEVEN,
        EIGHT,
        NINE,
        TEN,
        JACK,
        QUEEN,
        KING // == 13
    };

    class Card
    {
    public:
        Card(Rank rank, Suit suit);
        string toString() const;
        Rank getRank() const { return _rank; }; // inline for efficiency
        Suit getSuit() const { return _suit; }; // inline for efficiency
        int compareTo_card(Card);   // if p1 card bigger return 1 if smaller return -1 else 0          

    private:
        Rank _rank;// 13 cards for own suit
        Suit _suit;//4 suits
    };
};
#endif
