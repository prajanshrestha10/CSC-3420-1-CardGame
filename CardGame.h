/*
Name: Prajan Shrestha
Instructor Name: Dr. Visvasuresh Govindaswamy
Course: Data Structures and Algorithms - CSC-3420-1
Due Date: September 28, 2026
Description: The following program demonstrates concepts of pointers, 2D arrays, enums and randomization, 
    by combining card shuffling with card evaluation to crete a more functional program called PokerPal, 
    which simulates managing a standard 52-card deck, shuffling it, dealing 5-card poker hands, 
    displaying the current hand, and evaluating poker combinations using a single class named CardGame.       
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <string>
using namespace std;

// Enumerations for Suits and Ranks
enum Suit { Spades, Hearts, Diamonds, Clubs };
enum Rank { Ace, Two, Three, Four, Five, Six, Seven, 
    Eight, Nine, Ten, Jack, Queen, King };

class CardGame {
    public:
        // Constructor
        CardGame();

        // --- Setters ---
        void setDeckCard(int suit, int rank, int value);
        void setHandCard(int cardIndex, int suit, int rank);
        void setCardDealt(int suit, int rank, bool dealt);
        void setHasDealt(bool status);

        // --- Getters ---
        int getDeckCard(int suit, int rank);
        int getHandCardSuit(int cardIndex);
        int getHandCardRank(int cardIndex);
        bool getIsCardDealt(int suit, int rank);
        bool getHasDealt();
        string getSuitName(int suitIndex);
        string getRankName(int rankIndex);


        // --- Others ---
        // Core Member Functions required by specs
        void initializeDeck();
        void shuffleDeck();
        void dealHand();
        void displayDeck();
        void displayHand();

        // Hand Evaluation Member Functions
        bool isPair();
        bool isTwoPair();
        bool isThreeOfAKind();
        bool isFourOfAKind();
        bool isFlush();
        bool isStraight();
        void evaluateHand();

    private:
        int deck[4][13];        // 2D Array: 4 suits x 13 ranks (stores card numbers 1 to 52)
        int hand[5][2];         // 2D Array: 5 cards, each storing [SuitIndex, RankIndex]
        bool dealtCards[4][13]; // Tracking matrix to mark dealt cards as "used"
        bool hasDealt;          // Tracks whether a hand has been dealt

        // Helper arrays for formatting text output
        static const string suitNames[4];
        static const string rankNames[13];
};