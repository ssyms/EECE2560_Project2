// main.cpp
// Problem Set 2a                                 Chris Canal
// Team cansym                                    canal.c@husky.neu.edu
//                                                Sarada Symonds
//                                                symonds.s@husky.neu.edu
//
// Main program file for homework 2a.
#include "d_node.h"
#include "Card.h"
#include "Deck.h"
#include <iostream>
#include <time.h>    //for making rand() more random

using namespace std;

//------------Global Operator Overloading---------------
ostream&  operator << (ostream & ostr, Card cardObj)
//<< overload for the card class
{
    ostr << "(" << cardObj.getSuitString() << ", ";
    ostr << cardObj.getValueString() << ")";

    return ostr;
}

ostream&  operator << (ostream & ostr, Deck deckObj)
//<< overload for deck class that prints each card in deck
{
    node<Card> *currentNode;
    currentNode = deckObj.getHeadDeck();

    for(int i = 0; i < 52; i++)
    //prints out each card
    {
          if((i % 13) == 0)
          //if loop to split up lines
          {
              ostr << "\n";
          }

          cout << currentNode->nodeValue;
          currentNode = currentNode->next;

    //end of for loop for print
    }

    return ostr;

//end of << overload for deck
}

//-------------------Card Class Functions----------------------

Card::Card()
//default Card constructor
{
    value = 13;

    suit = 1;
}

Card::Card(int newValue, int newSuit)
//Card constructor to set initial value and suit
{
    set(newValue, newSuit);
}


void Card::set(int newValue, int newSuit)
//sets the value and suit of the Card class
{
    value = newValue;

    suit = newSuit;
}

void Card::setSuit(int newSuit)
//set the suit of the card
{
    suit = newSuit;
}

void Card::setValue(int newValue)
//set the value of the card
{
    value = newValue;
}

int Card::getValue()
//returns value of card
{
    return value;
}

int Card::getSuit()
//returns suit of card
{
    return suit;
}

string Card::getValueString()
//returns value of card as a string
{
  string stringValue;
  switch(value)
  //switches based on integer value
  {
    case 1: stringValue = "Ace";
            break;
    case 2: stringValue = "2";
            break;
    case 3: stringValue = "3";
            break;
    case 4: stringValue = "4";
            break;
    case 5: stringValue = "5";
            break;
    case 6: stringValue = "6";
            break;
    case 7: stringValue = "7";
            break;
    case 8: stringValue = "8";
            break;
    case 9: stringValue = "9";
            break;
    case 10: stringValue = "10";
            break;
    case 11: stringValue = "Jack";
            break;
    case 12: stringValue = "Queen";
            break;
    case 13: stringValue = "King";
            break;

  //switch statement to assign a string value
  }

  return stringValue;

//end of get value string
}

string Card::getSuitString()
//returns suit as a string
{

  string suitString;
  switch(suit)
  //switches based on suit value
  {
    case 1: suitString = "Club";
            break;
    case 2: suitString = "Diamond";
            break;
    case 3: suitString = "Heart";
            break;
    case 4: suitString = "Spade";
            break;

  //end of switch statement to assign suit
  }

  return suitString;

//end of get suit string
}

//-------------------Deck Class Functions----------------------

Deck::Deck()
//default constructor that creates a deck in order
{
    Card headCard(1,1); //Set head card to Ace of Clubs
    headDeck->nodeValue  = headCard;
    node<Card> *currentCard;
    currentCard = headDeck;
    for(int i = 1; i <= 4; i++)
    //goes through each suit
    {
        for(int j = 1; j <= 13; j++)
        //goes through each value of cards
        {
            if (i != 1 || j != 1){
                Card nextCard(j, i);
                currentCard->next = new node<Card> (nextCard);
                currentCard = currentCard->next;
            }

        //end of for loop to set values
        }

    //end of for loop to set suit
    }

//end of deck constructor
}

void Deck::shuffle()
//shuffles the deck
{
    //that is in the range fifty thousand to five million
    int shuffles = rand() % 5000000 + 50000;
    cout << "\n\nWe will shuffle the cards " << shuffles << " times!!" << endl;
    int shuffleLocation1;
    int shuffleLocation2;
    node<Card>* cardHolderSwitch1 = headDeck;
    node<Card>* cardHolderLocation1Prev = headDeck;
    node<Card>* cardHolderLocation1 = headDeck;
    node<Card>* cardHolderLocation2Prev = headDeck;
    node<Card>* cardHolderLocation2 = headDeck;

    for (int i = 0; i < shuffles; i++)
    //for loop to shuffle deck a random amount of times
    {
        cardHolderSwitch1 = headDeck;
        cardHolderLocation1Prev = headDeck;
        cardHolderLocation1 = headDeck;
        cardHolderLocation2Prev = headDeck;
        cardHolderLocation2 = headDeck;
        shuffleLocation1 = rand() % 52;
        shuffleLocation2 = rand() % 52;
        if (shuffleLocation1 != shuffleLocation2
          && abs(shuffleLocation2 - shuffleLocation1) > 2)
        //if we are not are at the location or 2 nodes from location
        {

            for (int j = 0; j <= shuffleLocation1; j++)
            //chooses random card - goes to shufflesLocation1
            {

                if (j == shuffleLocation1)
                //if reached the random location in list
                {

                    for (int k = 0; k <= shuffleLocation2; k++)
                    //goes to shuffle location 2
                    {

                        if (k == shuffleLocation2)
                        //if we're at shuffle location 2
                        {
                            if (shuffleLocation1 == 0)
                            //swap two cards edge case - first card is head
                            {
                                cardHolderSwitch1 = cardHolderLocation1;
                                headDeck = cardHolderLocation2;
                                cardHolderLocation2Prev->next =
                                    cardHolderSwitch1;
                                cardHolderSwitch1 = cardHolderLocation1->next;
                                cardHolderLocation1->next =
                                    cardHolderLocation2->next;
                                cardHolderLocation2->next = cardHolderSwitch1;
                            //end of first card edge case
                            }
                            else if (shuffleLocation2 == 0)
                            //swap two cards edge case - second card is head
                            {
                                cardHolderSwitch1 = cardHolderLocation2;
                                headDeck = cardHolderLocation1;
                                cardHolderLocation1Prev->next =
                                    cardHolderSwitch1;
                                cardHolderSwitch1 = cardHolderLocation2->next;
                                cardHolderLocation2->next =
                                    cardHolderLocation1->next;
                                cardHolderLocation1->next = cardHolderSwitch1;
                            //end of second card edge case
                            }
                            else
                            //otherwise swap the two cards
                            {
                                cardHolderSwitch1 = cardHolderLocation1;
                                cardHolderLocation1Prev->next =
                                    cardHolderLocation2;
                                cardHolderLocation2Prev->next =
                                    cardHolderSwitch1;
                                cardHolderSwitch1 = cardHolderLocation1->next;
                                cardHolderLocation1->next =
                                    cardHolderLocation2->next;
                                cardHolderLocation2->next = cardHolderSwitch1;
                            //end of if statement to swap cards
                            }

                        //end of if statement for a shuffle location 2
                        }
                        else
                        //if we are not at a swap location
                        {
                            cardHolderLocation2Prev = cardHolderLocation2;
                            cardHolderLocation2 = cardHolderLocation2->next;
                        //end of check if we are at shuffle location 2
                        }

                    //end of for loop to get to shuffle location 2
                    }

                //end of if we are at shuffle location 1 statement
                }
                else
                //if we are not at shuffle location 1
                {
                    cardHolderLocation1Prev = cardHolderLocation1;
                    cardHolderLocation1 = cardHolderLocation1->next;
                //end of if we  are at shuffle location 1
                }

            //end of if statement for if we are at random card 1
            }

        //end of for leap to reach random card 1
        }

    //end of for loop to shuffle a random amount of times
    }

//end of shuffle function
}


node<Card>* Deck::getHeadDeck()
//returns head of the deck
{
    return headDeck;
}

//-----------------Main Function-------------------
int main ()
//main function
{
    cout << "Clock time: " << clock() << endl;
    srand (time(NULL));   //Uses time to make rand more random
    clock_t t1,t2;

    t1=clock();


    Deck testDeck;
    cout << testDeck;
    testDeck.shuffle();
    cout << testDeck;

    t2=clock();
    float diff = ((float)t2-(float)t1);

    float seconds = diff / CLOCKS_PER_SEC;
    cout<< "\n\nRuntime of program: "<< seconds << " seconds" << endl;

    return 0;

//end of main function
}
