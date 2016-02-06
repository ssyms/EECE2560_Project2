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
    ostr << "(" << cardObj.getSuit() << ", ";
    ostr << cardObj.getValue() << ")";

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
          if((i % 12) == 0)
          //if loop to split up lines
          {
              ostr << "\n";
          }

          cout << currentNode->nodeValue;
          currentNode = currentNode->next;

    //end of for loop for print
    }
    cout << "\n\nThe final card points to:" << currentNode;

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
    cout << "currentCard:" << currentCard << "   currentCard->next:" << currentCard->next << endl;
    if (currentCard->next == NULL){
        cout << "It's True!!!" << endl;
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
        if (shuffleLocation1 != shuffleLocation2 && abs(shuffleLocation2 - shuffleLocation1) > 2){

            for (int j = 0; j <= shuffleLocation1; j++)
            //chooses random card
            {
                if (j == shuffleLocation1)
                //if reached the random location in list
                {
                    for (int k = 0; k <= shuffleLocation2; k++){

                        if (k == shuffleLocation2){
                            if (shuffleLocation1 == 0){
                                cardHolderSwitch1 = cardHolderLocation1;
                                headDeck = cardHolderLocation2;
                                cardHolderLocation2Prev->next = cardHolderSwitch1;
                                cardHolderSwitch1 = cardHolderLocation1->next;
                                cardHolderLocation1->next = cardHolderLocation2->next;
                                cardHolderLocation2->next = cardHolderSwitch1;
                            }else if (shuffleLocation2 == 0){
                                cardHolderSwitch1 = cardHolderLocation2;
                                headDeck = cardHolderLocation1;
                                cardHolderLocation1Prev->next = cardHolderSwitch1;
                                cardHolderSwitch1 = cardHolderLocation2->next;
                                cardHolderLocation2->next = cardHolderLocation1->next;
                                cardHolderLocation1->next = cardHolderSwitch1;
                            } else {
                                cardHolderSwitch1 = cardHolderLocation1;
                                cardHolderLocation1Prev->next = cardHolderLocation2;
                                cardHolderLocation2Prev->next = cardHolderSwitch1;
                                cardHolderSwitch1 = cardHolderLocation1->next;
                                cardHolderLocation1->next = cardHolderLocation2->next;
                                cardHolderLocation2->next = cardHolderSwitch1;
                            }
                        } else {
                            cardHolderLocation2Prev = cardHolderLocation2;
                            cardHolderLocation2 = cardHolderLocation2->next;
                        }
                    }
                } else {
                    cardHolderLocation1Prev = cardHolderLocation1;
                    cardHolderLocation1 = cardHolderLocation1->next;
                }
            }

        }
    }
}
/*
void Deck::shuffle()
//shuffle function for deck class
{
      node<Card> *currentHead = headDeck;
      node<Card> *currentNode = headDeck;
      node<Card> *previousNode;

      for(int i = 0; i < 52; i++)
      //"shuffles" 52 times
      {

          int shuffles = rand() % 51;
          for(int j = 0; j <= shuffles; j++)
          //finds random node
          {
              if(j == (shuffles - 1))
              //previous node to connect to next
              {
                    node<Card> *previousNode = currentNode;
              }

              if(j == shuffles)
              //if we are at random node, random node re-inserted at beginning
              {
                  if(currentNode->next != NULL)
                  {
                    node<Card> *nextNode = currentNode->next;
                    currentNode->next = currentHead;
                    currentHead = currentNode;
                    previousNode->next = nextNode;
                  }
                  else
                  {
                    currentNode->next = currentHead;
                    currentHead = currentNode;
                    previousNode->next = NULL;
                  }

              }
              else
              //if we have not reached the random node at shuffles
              {

                  currentNode = currentNode->next;
              }

          //has reached random node
          }

      //shuffles 52 times
      }

//end of shuffles functions
}*/

node<Card>* Deck::getHeadDeck()
//returns head of the deck
{
    return headDeck;
}

//-----------------Main Function-------------------
int main ()
//main function
{
    cout << "Clcok time: " << clock() << endl;
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
}
