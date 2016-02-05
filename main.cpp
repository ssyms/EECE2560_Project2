// main.cpp
// Problem Set 2a                                 Chris Canal
// Team cansym                                    canal.c@husky.neu.edu
//                                                Sarada Symonds
//                                                symonds.s@husky.neu.edu
//
// Main program file for homework 2a.
#include "d_node.h"
#include "Card.h"

using namespace std;
//------------Global Operator Overloading---------------
ostream&  operator << (ostream & ostr, Card cardObj)
{
    ostr << "(" << cardObj.getSuit() << ", ";
    ostr << cardObj.getValue() << ")";

    return ostr;
}

//-------------------Card Class Functions----------------------

Card::Card()
//default Card constructor
{
    value = "King";

    suit = "club";
}

Card::Card(string newValue, string newSuit)
//Card constructor to set initial value and suit
{
    set(newValue, newSuit);
}


void Card::set(string newValue, string newSuit)
//sets the value and suit of the Card class
{
    value = newValue;

    suit = newSuit;
}

void Card::setSuit(string newSuit)
//set the suit of the card
{
    suit = newSuit;
}

void Card::setValue(string newValue)
//set the value of the card
{
    value = newValue;
}

string Card::getValue()
//returns value of card
{
    return value;
}

string Card::getSuit()
//returns suit of card
{
    return suit;
}

int main () {

  Card testCard;
  cout << testCard << endl;

  return 0;
}
