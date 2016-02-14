// Card.h
// Problem Set 2b                                 Chris Canal
// Team cansym                                    canal.c@husky.neu.edu
//                                                Sarada Symonds
//                                                symonds.s@husky.neu.edu
//
// Card header file for homework 2a. Contains
// declarations for the Card Class
#include <iostream>

using namespace std;
#ifndef Card_Card_h
#define Card_Card_h

class Card
//Card class declaration
{
    public:

        //default constructor
        Card();

        //constructor that sets the card value
        Card(int newValue, int newSuit);

        //copy constructor
        Card(const Card &copyCard);

        //set both values
        void set(int newValue, int newSuit);

        //set value function
        void setValue(int newValue);

        //set suit function
        void setSuit(int newSuit);

        //get value function
        int getValue() const;

        //get suit
        int getSuit() const;

        //returns the value as a string
        string getValueString();

        //returns suit as a string
        string getSuitString();

        void operator= (Card &cardSource);

    private:

        //value of the card (Ace=1 - King=13)
        int value;

        //suit of card - club=1, diamond=2, heart=3, spade=4,
        int suit;

}; //end of card class

#endif

//end of card header file
