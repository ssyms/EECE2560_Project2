// main.cpp
// Problem Set 2b                                 Chris Canal
// Team cansym                                    canal.c@husky.neu.edu
//                                                Sarada Symonds
//                                                symonds.s@husky.neu.edu
//
// Main program file for homework 2a.
#include "d_node.h"
#include "Card.h"
#include "Deck.h"
#include <iostream>
#include <cstdlib>
#include <time.h>    //for making rand() more random
#include <vector>


using namespace std;



//-------------------Card Class Functions----------------------

Card::Card()
//default Card constructor
{
    value = 13;

    suit = 1;
}

Card::Card(int newValue, int newSuit)
//card constructor to set initial value and suit
{
    set(newValue, newSuit);
}

Card::Card(const Card &copyCard)
//card copy constructor
{
    set(copyCard.getValue(), copyCard.getSuit());
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

int Card::getValue() const
//returns value of card
{
    return value;
}

int Card::getSuit() const
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

  } //switch statement to assign a string value

  return stringValue;

} //end of get value string

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

  } //end of switch statement to assign suit

  return suitString;

} //end of get suit string

void Card::operator= (Card &cardSource)
//enables the = to assign an object of the card class
{
    // do the copy
    value = cardSource.value;
    suit = cardSource.suit;

    // return the existing objec
}

//-------------------Deck Class Functions----------------------

Deck::Deck()
//default constructor that creates a deck in order
{
    Card headCard(1,1); //Set head card to Ace of Clubs
    headDeck->nodeValue  =  headCard;
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

        } //end of for loop to set values

     } //end of for loop to set suit

} //end of deck constructor

Deck& Deck::operator= (Deck &deckSource)
//enables the = to assign an object of the card class
{
    // do the copy
    headDeck = deckSource.getHeadDeck();

    // return the existing object
    return *this;
}

Deck::Deck(const Deck &deckCard)
//card copy constructor
{
    headDeck = new node<Card>;
    headDeck = deckCard.headDeck;
}

Deck::~Deck()
//destructor
{
    node<Card>* current = headDeck->next;
    node<Card>* previous;

    while(current != NULL)
    //while there is a current node
    {
        previous = current;
        current = current -> next;
        delete previous;
    }

} //end of destructor


void Deck::shuffle()
//shuffles the deck
{
    //that is in the range fifty thousand to five million
    //int shuffles = rand() % 5000000 + 50000;
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
                                /*
                                cardHolderSwitch1 = cardHolderLocation1;
                                headDeck = cardHolderLocation2;
                                cardHolderLocation2Prev->next =
                                    cardHolderSwitch1;
                                cardHolderSwitch1 = cardHolderLocation1->next;
                                cardHolderLocation1->next =
                                    cardHolderLocation2->next;
                                cardHolderLocation2->next = cardHolderSwitch1;
                                */
                            } //end of first card edge case
                            else if (shuffleLocation2 == 0)
                            //swap two cards edge case - second card is head
                            {
                                /*
                                cardHolderSwitch1 = cardHolderLocation2;
                                headDeck = cardHolderLocation1;
                                cardHolderLocation1Prev->next =
                                    cardHolderSwitch1;
                                cardHolderSwitch1 = cardHolderLocation2->next;
                                cardHolderLocation2->next =
                                    cardHolderLocation1->next;
                                cardHolderLocation1->next = cardHolderSwitch1;
                                */
                            } //end of second card edge case
                            else
                            //otherwise swap the two cards
                            {
                                /*
                                cardHolderSwitch1 = cardHolderLocation1;
                                cardHolderLocation1Prev->next =
                                    cardHolderLocation2;
                                cardHolderLocation2Prev->next =
                                    cardHolderSwitch1;
                                cardHolderSwitch1 = cardHolderLocation1->next;
                                cardHolderLocation1->next =
                                    cardHolderLocation2->next;
                                cardHolderLocation2->next = cardHolderSwitch1;
                                */
                            } //end of if statement to swap cards

                        } //end of if statement for a shuffle location 2
                        else
                        //if we are not at a swap location
                        {
                            cardHolderLocation2Prev = cardHolderLocation2;
                            cardHolderLocation2 = cardHolderLocation2->next;
                        } //end of check if we are at shuffle location 2

                    } //end of for loop to get to shuffle location 2

                } //end of if we are at shuffle location 1 statement
                else
                //if we are not at shuffle location 1
                {
                    cardHolderLocation1Prev = cardHolderLocation1;
                    cardHolderLocation1 = cardHolderLocation1->next;
                } //end of if we  are at shuffle location 1

            } //end of if statement for if we are at random card 1

        } //end of for leap to reach random card 1

    } //end of for loop to shuffle a random amount of times
    cout << "\nWE COMPLETED THE SHUFFLE" << endl;
    cardHolderSwitch1 = NULL;
    cardHolderLocation1Prev = NULL;
    cardHolderLocation1 = NULL;
    cardHolderLocation2Prev = NULL;
    cardHolderLocation2 = NULL;
} //end of shuffle function


node<Card> *Deck::getHeadDeck() const
//returns head of the deck
{
    return headDeck;
}

Card Deck::deal()
//deals the top card and
{
    node<Card> *dealCard = headDeck;
    headDeck = headDeck->next;
    return dealCard->nodeValue;
}

void Deck::replace(Card c)
//adds a new card to the bottom of the deck
{
    node<Card> *currentCard = headDeck;

    while(currentCard->next != NULL)
    //while loop moves to bottom of deck
    {
      currentCard = currentCard->next;
    }

    currentCard->next = new node<Card> (c);

} //end of replace function


//------------Global Operator Overloading---------------
ostream&  operator << (ostream & ostr, Card cardObj)
//<< overload for the card class
{
    ostr << "(" << cardObj.getSuitString() << ", ";
    ostr << cardObj.getValueString() << ")";

    return ostr;
}


ostream&  operator << (ostream & ostr, Deck const &deckObj)
//<< overload for deck class that prints each card in deck
{
    node<Card> *currentNode;
    currentNode = new node<Card> (*(deckObj.getHeadDeck()));
    int i = 0;
    while(currentNode != NULL)
    //prints out each card
    {
          if((i % 13) == 0)
          //if loop to split up lines
          {
              ostr << "\n";
          }

          cout << currentNode->nodeValue;
          currentNode = currentNode->next;
          i++;

    } //end of for loop for print

    return ostr;

} //end of << overload for deck



//------------Global Functions--------------
int getPoints(Card c, int score)
//returns the current score
{
    int valueScore = 0;
    switch(c.getValue())
    //switches based on value of the card
    {
      case 1: valueScore = score + 10;
              break;
      case 11:
      case 12:
      case 13: valueScore = score + 5;
              break;
      case 8:
      case 9:
      case 10: valueScore = score;
              break;
      case 7: valueScore = score/2;
              break;
      case 6:
      case 5:
      case 4:
      case 3:
      case 2: valueScore = 0;
              break;
      default: valueScore = score;
              break;
    } // end of switch statement to assign valueScore

    if(c.getSuit() == 3)
    //adds bonus point if suit is a heart
    {
      valueScore++;
    }

    return valueScore;
} // end of getPoints function

void playFlip(Deck gameDeck)
//plays the game flip
{
    cout << "line before gameDeck\n";

    cout << "line after gamedeck\n";

    int score = 0;
    vector<int> guessVector;
    int userResponse;
    cout << "line 419\n";
    for(int i = 0; i < 3; i++)
    //shuffles game deck three times
    {
      gameDeck.shuffle();
      cout << "line 424\n";
    }
/*
    node<Card> *playerDeck = new node<Card> (gameDeck.deal());
    node <Card> *currentCard;
    currentCard = playerDeck;

    cout << "line 431\n";

    for(int i = 0; i < 23; i++)
    //draws 24 cards that are face down
    {
      currentCard->next = new node<Card> (gameDeck.deal());
      currentCard = currentCard->next;
    }

    bool gameOn = true;
    int cardNumber;
    node<Card> *drawnCard;
    node<Card> *thisCard;

    while(gameOn)
    //asks user to flip a card and adds to their score
    {
        while (cardNumber == -1)
        //while cardNumber is not valid
        {
            cout << "Please pick a card number 0-23\n";

            //Player picks a card
            cin >> cardNumber;

            if (cardNumber > 23 || cardNumber < 0)
            //if card entered is outside range of the player deck
            {
                cout << "invalid choice!!!" << endl;
                cardNumber = -1;
            }
            else
            //if card is in player deck range
            {
                for (int i = 0; i < guessVector.size(); i++)
                //goes through chosen card numbers
                {
                    if (cardNumber ==  guessVector[i])
                    //checks if card was chosen
                    {
                        cout << "You have already choosen that card." << endl;
                        cout << "Remeber?" << endl;
                        cardNumber = -1;
                    }
                }
            }

        }

        cout << "You chose card number: " << cardNumber << "\n";

        for(int i = 0; i <= cardNumber; i++)
        //get to drawn cardNumber
        {
          if(i == cardNumber)
          //if it is the card that was drawn
          {
            cout << thisCard->nodeValue;
            drawnCard = thisCard;
          }
          thisCard = thisCard->next;
        }
        score = getPoints(drawnCard->nodeValue, score);
        guessVector.push_back(cardNumber);
        cardNumber = -1;


        cout << "Your current score is " << score << endl;
        cout << "\nWould you like to keep playing? (1 for yes, 2 for no)" << endl;
        cin >> userResponse;

        if (userResponse == 1){
            cout << "\nGreat! Lets play some more!" << endl;

        } else if (userResponse == 2){
            cout << "\nYour final score was " << score << endl;
            cout << "\nI hope you learned your lesson... Gambling is bad!\n";
            cout << "\nThanks for playing! Have an awesome day!" << endl;
            gameOn = false;

        } else {
            cout << "I didn't understand your input..." << endl;
            cout << "Oh well, lets play again!!!" << endl;
        }
    }*/

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

    playFlip(testDeck);

    t2=clock();
    float diff = ((float)t2-(float)t1);

    float seconds = diff / CLOCKS_PER_SEC;
    cout << "\n\nRuntime of program: "<< seconds << " seconds" << endl;

    return 0;

} //end of main function

//end of main file
