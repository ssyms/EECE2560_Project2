// Deck.h
// Problem Set 2a                                 Chris Canal
// Team cansym                                    canal.c@husky.neu.edu
//                                                Sarada Symonds
//                                                symonds.s@husky.neu.edu
//
// Deck header file for homework 2a. Contains
// declarations for the Deck Class
#include <iostream>

using namespace std;

#ifndef Deck_Deck_h
#define Deck_Deck_h

class Deck
//declaration of the deck class
{
    public:

        //default constructor
        Deck();

        //shuffles the deck
        void shuffle();

        //getHeadDeck function retrieves the head of the deck
        node<Card> *getHeadDeck();

    private:

        //pointer to first card in deck
        node <Card> *headDeck;

}; //end of deck class

#endif //Deck class

//end of deck header file
