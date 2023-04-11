#include "card.hpp"

using namespace ariel;
using namespace std;

//create a new card
Card::Card(Rank rank, Suit suit) : _rank(rank), _suit(suit) {}

string Card::toString() const
{
    string suitName;
    switch (_suit)
    {
    case Suit::HEARTS:
        suitName = "Heart";
        break;
    case Suit::DIAMONDS:
        suitName = "Diamond";
        break;
    case Suit::CLUBS:
        suitName = "Club";
        break;
    case Suit::SPADES:
        suitName = "Spades";
        break;
    }

    string rankName;
    switch (_rank)
    {
    case Rank::ACE:
        rankName = "Ace";
        break;
    case Rank::TWO:
        rankName = "2";
        break;
    case Rank::THREE:
        rankName = "3";
        break;
    case Rank::FOUR:
        rankName = "4";
        break;
    case Rank::FIVE:
        rankName = "5";
        break;
    case Rank::SIX:
        rankName = "6";
        break;
    case Rank::SEVEN:
        rankName = "7";
        break;
    case Rank::EIGHT:
        rankName = "8";
        break;
    case Rank::NINE:
        rankName = "9";
        break;
    case Rank::TEN:
        rankName = "10";
        break;
    case Rank::JACK:
        rankName = "Jack";
        break;
    case Rank::QUEEN:
        rankName = "Queen";
        break;
    case Rank::KING:
        rankName = "King";
        break;
    }

    return rankName + " of " + suitName; // example: "10 Hearts"
}

// card1 =/>/<  card2
int Card::compareTo_card(Card card2)
{
    Rank rank1 = this->getRank(); // card1
    Rank rank2 = card2.getRank(); // card2
    if (rank1 > rank2)            // example 3 > 2
    {
        return 1;
    }
    if (rank1 == rank2) // example 3 = 3
    {
        return 0;
    }
    // ACE looses to 2
    if (rank1 == 1 && rank2 == 2) // example ACE < 2
    {
        return -1;
    }
    // ACE looses to 2
    if (rank1 == 2 && rank2 == 1) // example 2 > ACE
    {
        return 1;
    }
    if (rank1 == 1 && rank2 != 2) // example ACE > 8
    {
        return 1;
    }
    if (rank1 != 2 && rank2 == 1) // example 8 < ACE
    {
        return -1;
    }
    else
        return -1; // rank1 < rank2
}
