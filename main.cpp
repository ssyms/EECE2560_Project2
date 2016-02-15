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


// using namespace std;



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
    node<Card> *firstCard;
    firstCard = new node<Card> (headCard);
    headDeck = firstCard;

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
    /*
    node<Card>* current = headDeck->next;
    node<Card>* previous;

    while(current != NULL)
    //while there is a current node
    {
        previous = current;
        current = current -> next;
        delete previous;
    }
*/
} //end of destructor


void Deck::shuffle()
//shuffles the deck
{
    //that is in the range fifty thousand to five million
    //int shuffles = rand() % 5000000 + 50000;
    int shuffles = rand() % 500 + 50;
    std::cout << "\n\nWe will shuffle the cards " << shuffles 
              << " times!!" << std::endl;
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
                                cardHolderLocation2Prev->next = cardHolderSwitch1;
                                cardHolderSwitch1 = cardHolderLocation1->next;
                                cardHolderLocation1->next = cardHolderLocation2->next;
                                cardHolderLocation2->next = cardHolderSwitch1;
                            } //end of first card edge case
                            else if (shuffleLocation2 == 0)
                            //swap two cards edge case - second card is head
                            {
                                cardHolderSwitch1 = cardHolderLocation2;
                                headDeck = cardHolderLocation1;
                                cardHolderLocation1Prev->next = cardHolderSwitch1;
                                cardHolderSwitch1 = cardHolderLocation2->next;
                                cardHolderLocation2->next = cardHolderLocation1->next;
                                cardHolderLocation1->next = cardHolderSwitch1;
                            } //end of second card edge case
                            else
                            //otherwise swap the two cards
                            {
                                cardHolderSwitch1 = cardHolderLocation1;
                                cardHolderLocation1Prev->next = cardHolderLocation2;
                                cardHolderLocation2Prev->next = cardHolderSwitch1;
                                cardHolderSwitch1 = cardHolderLocation1->next;
                                cardHolderLocation1->next = cardHolderLocation2->next;
                                cardHolderLocation2->next = cardHolderSwitch1;
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
    std::cout << "\nWE COMPLETED THE SHUFFLE" << std::endl;
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
    Card dealtCard;
    node<Card> *dealCard = headDeck;
    headDeck = headDeck->next;
    dealtCard = dealCard->nodeValue;
    std::cout << "\nThe code gets here";
    delete dealCard;
    std::cout << "\nThe code gets here2";
    return dealtCard;
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

          std::cout << currentNode->nodeValue;
          currentNode = currentNode->next;
          i++;

    } //end of for loop for print

    return ostr;

} //end of << overload for deck



//------------Global Functions--------------
double getPoints(Card &c, double score)
//returns the current score
{
    switch(c.getValue())
    //switches based on value of the card
    {
      case 1: score += 10;
              break;
      case 11:
      case 12:
      case 13: score += 5;
              break;
      case 8:
      case 9:
      case 10: score = score;
              break;
      case 7: score = score/2;
              break;
      case 6:
      case 5:
      case 4:
      case 3:
      case 2: score = 0;
              break;
      default: score = score;
              break;
    } // end of switch statement to assign valueScore

    if(c.getSuit() == 3)
    //adds bonus point if suit is a heart
    {
      score++;
    }

    return score;
} // end of getPoints function

void playFlip(Deck &gameDeck)
//plays the game flip
{

    double score = 0.0;
    vector<int> guessVector;
    guessVector.resize(24);
    int userResponse;
    std::cout << "line 419\n";
    /*
    for(int i = 0; i < 3; i++)
    //shuffles game deck three times
    {
      gameDeck.shuffle();
      std::cout << "line 424\n";
      std::cout << gameDeck;
    }
    */

    node<Card> *playerDeck = new node<Card> (gameDeck.deal());
    std::cout << "\nplayerDeck->next = " << playerDeck->next << std::endl;
    std::cout << "\nplayerDeck = " << playerDeck << std::endl;
    std::cout << "playerDeck node value: " << playerDeck->nodeValue << std::endl;
    node <Card> *currentCard;
    currentCard = playerDeck;

    std::cout << "line 431\n";

    for(int i = 0; i < 23; i++)
    //draws 24 cards that are face down
    {
        std::cout << "\n______________________\nFor loop number " << i;
        currentCard->next = new node<Card> (gameDeck.deal());

        std::cout << "\nCurrentCard->next = " << currentCard->next;
        std::cout << "\nCurrentCard = " << currentCard;
        std::cout << "\ncurrentCard->nodeValue = " << currentCard->nodeValue << std::endl;
        std::cout << "\nThe code gets here3";
        std::cout << "\nThe code gets here4";
        if (i != 22){
            std::cout << "\nThe code gets here5";
            if(currentCard)
                currentCard = currentCard->next;
        }
        std::cout << "\nThe code gets here6";
    }
    std::cout << "What is goint on here!";
    bool gameOn = true;
    int cardNumber = -1;
    node<Card> *drawnCard;
    std::cout << "line 468 happens";
    node<Card> *thisCard = playerDeck;
    std::cout << "line 470 happens";

    guessVector.push_back(cardNumber);

    while(gameOn)
    //asks user to flip a card and adds to their score
    {
        while (cardNumber == -1)
        //while cardNumber is not valid
        {
            thisCard = playerDeck;
            std::cout << "These are the cards you have not choosen: (";
            for (int i = 0; i < 24; i++)
            //goes through chosen card numbers
            {
                if (i != 23){
                    if (i !=  guessVector[i])
                    //checks if card was chosen
                    {
                        std::cout << i << " , ";
                    } else {
                        std::cout << "- , ";
                    }
                } else {
                    if (i !=  guessVector[i])
                    //checks if card was chosen
                    {
                        std::cout << i << " )\n";
                    } else {
                        std::cout << "- )\n";
                    }
                }
            }
            std::cout << "Please pick a card number 0-23\n";

            //Player picks a card
            cin >> cardNumber;

            if (cardNumber > 23 || cardNumber < 0)
            //if card entered is outside range of the player deck
            {
                std::cout << "invalid choice!!!" << std::endl;
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
                        std::cout << "You have already choosen that card." << std::endl;
                        std::cout << "Remeber?" << std::endl;
                        cardNumber = -1;
                        i = guessVector.size();
                    }
                }
            }

        }

        std::cout << "You chose card number: " << cardNumber << "\n";

        for(int i = 0; i <= cardNumber; i++)
        //get to drawn cardNumber
        {
          if(i == cardNumber)
          //if it is the card that was drawn
          {
            std::cout << "thisCard Drawn:" << std::endl;
            std::cout << thisCard->nodeValue;
            drawnCard = thisCard;
          }
          thisCard = thisCard->next;
        }
        score = getPoints(drawnCard->nodeValue, score);
        guessVector.push_back(cardNumber);
        cardNumber = -1;


        std::cout << "Your current score is " << score << std::endl;
        std::cout << "\nWould you like to keep playing? (1 for yes, 2 for no)" << std::endl;
        cin >> userResponse;

        if (userResponse == 1){
            std::cout << "\nGreat! Lets play some more!" << std::endl;

        } else if (userResponse == 2){
            std::cout << "\nYour final score was " << score << std::endl;
            std::cout << "\nI hope you learned your lesson... Gambling is bad!\n";
            std::cout << "\nThanks for playing! Have an awesome day!" << std::endl;
            gameOn = false;

        } else {
            std::cout << "I didn't understand your input..." << std::endl;
            std::cout << "Oh well, lets play again!!!" << std::endl;
        }
    }

}



//-----------------Main Function-------------------
int main ()
//main function
{
    std::cout << "Clock time: " << clock() << std::endl;
    srand (time(NULL));   //Uses time to make rand more random
    clock_t t1,t2;

    t1=clock();

    Deck testDeck;

    std::cout << testDeck;

    playFlip(testDeck);

    t2=clock();
    float diff = ((float)t2-(float)t1);

    float seconds = diff / CLOCKS_PER_SEC;
    std::cout << "\n\nRuntime of program: "<< seconds << " seconds" << std::endl;

    return 0;

} //end of main function

//end of main file
