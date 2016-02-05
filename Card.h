// Card.h
// Problem Set 2a                                 Chris Canal
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

        //constructor
        Card(string newValue, string newSuit);

        //set both values
        void set(string newValue, string newSuit);

        //set value function
        void setValue(string newValue);

        //set suit function
        void setSuit(string newSuit);

        //get value function
        string getValue();

        //get suit
        string getSuit();

    private:

        //value of the card (Ace - King)
        string value;

        //suit of card - spade, heart, club, diamond
        string suit;

//end of card class
};

#endif
