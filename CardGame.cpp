#include "CardGame.h"

// Initialize static display string arrays
const string CardGame::suitNames[4] = { "Spades", "Hearts", "Diamonds", "Clubs" };
const string CardGame::rankNames[13] = { "Ace", "2", "3", "4", "5", "6", "7", 
    "8", "9", "10", "Jack", "Queen", "King" };

// Constructor
CardGame::CardGame() {
    srand(static_cast<unsigned int>(time(0)));
    hasDealt = false;
    initializeDeck();
}

// --- Setters Implementation ---
void CardGame::setDeckCard(int suit, int rank, int value) {
    if (suit >= 0 && suit < 4 && rank >= 0 && rank < 13) {
        deck[suit][rank] = value;
    }
}

void CardGame::setHandCard(int cardIndex, int suit, int rank) {
    if (cardIndex >= 0 && cardIndex < 5 && suit >= 0 && suit < 4 && rank >= 0 && rank < 13) {
        hand[cardIndex][0] = suit;
        hand[cardIndex][1] = rank;
    }
}

void CardGame::setCardDealt(int suit, int rank, bool dealt) {
    if (suit >= 0 && suit < 4 && rank >= 0 && rank < 13) {
        dealtCards[suit][rank] = dealt;
    }
}

void CardGame::setHasDealt(bool status) {
    hasDealt = status;
}

// --- Getters Implementation ---
int CardGame::getDeckCard(int suit, int rank) {
    if (suit >= 0 && suit < 4 && rank >= 0 && rank < 13) return deck[suit][rank];
    return -1;
}

int CardGame::getHandCardSuit(int cardIndex) {
    if (cardIndex >= 0 && cardIndex < 5) return hand[cardIndex][0];
    return -1;
}

int CardGame::getHandCardRank(int cardIndex) {
    if (cardIndex >= 0 && cardIndex < 5) return hand[cardIndex][1];
    return -1;
}

bool CardGame::getIsCardDealt(int suit, int rank) {
    if (suit >= 0 && suit < 4 && rank >= 0 && rank < 13) return dealtCards[suit][rank];
    return false;
}

bool CardGame::getHasDealt() {
    return hasDealt;
}

string CardGame::getSuitName(int suitIndex) {
    if (suitIndex >= 0 && suitIndex < 4) return suitNames[suitIndex];
    return "Invalid Suit";
}

string CardGame::getRankName(int rankIndex) {
    if (rankIndex >= 0 && rankIndex < 13) return rankNames[rankIndex];
    return "Invalid Rank";
}

// Populate 2D deck array and reset tracking
void CardGame::initializeDeck() {
    int cardNum = 1;
    for (int r = 0; r < 4; ++r) {
        for (int c = 0; c < 13; ++c) {
            deck[r][c] = cardNum++;
            dealtCards[r][c] = false;
        }
    }
}

// Shuffle deck using random row/column swaps via pointers
void CardGame::shuffleDeck() {
    for (int r1 = 0; r1 < 4; ++r1) {
        for (int c1 = 0; c1 < 13; ++c1) {
            int r2 = rand() % 4;
            int c2 = rand() % 13;

            // Swap using raw pointers as requested by constraints
            int* ptr1 = &deck[r1][c1];
            int* ptr2 = &deck[r2][c2];

            int temp = *ptr1;
            *ptr1 = *ptr2;
            *ptr2 = temp;
        }
    }

    // Reset dealt flags on shuffle
    for (int r = 0; r < 4; ++r) {
        for (int c = 0; c < 13; ++c) {
            dealtCards[r][c] = false;
        }
    }
    hasDealt = false;

    cout << endl << "╔══════════════════════════════════════╗" << endl;
    cout << "║    ♠♥♣♦  Deck Shuffled!  ♦♣♥♠        ║" << endl;
    cout << "╚══════════════════════════════════════╝" << endl;
}

// Deal 5 unique unused cards into the 2D hand matrix
void CardGame::dealHand() {
    int count = 0;
    while (count < 5) {
        int r = rand() % 4;
        int c = rand() % 13;

        if (!dealtCards[r][c]) {
            dealtCards[r][c] = true;
            hand[count][0] = r; // Suit
            hand[count][1] = c; // Rank
            count++;
        }
    }
    hasDealt = true;

    cout << endl << "┌──────────────────────────────────────┐" << endl;
    cout << "│        🂠  5 Cards Dealt! 🂠           │" << endl;
    cout << "└──────────────────────────────────────┘" << endl;
}

// Display 4x13 deck grid
void CardGame::displayDeck() {
    cout << endl << "====================================================================" << endl;
    cout << "                 ♠♥♣♦ CURRENT DECK MATRIX ♦♣♥♠            " << endl;
    cout << "====================================================================" << endl;
    for (int r = 0; r < 4; ++r) {
        cout << setw(8) << suitNames[r] << ": ";
        for (int c = 0; c < 13; ++c) {
            cout << setw(3) << deck[r][c] << " ";
        }
        cout << endl;
    }
    cout << "====================================================================" << endl;
}

// Display current 5-card hand
void CardGame::displayHand() {
    if (!hasDealt) {
        cout << endl << "⚠️  [ALERT] No hand dealt yet. Please deal a hand first!" << endl;
        return;
    }

    cout << endl << " YOUR HAND: ";
    for (int i = 0; i < 5; ++i) {
        int s = hand[i][0];
        int r = hand[i][1];
        cout << rankNames[r] << " of " << suitNames[s];
        if (i < 4) cout << ", ";
    }
    cout << endl;
}

// Internal helper for evaluation
static void calculateFrequencies(const int hand[5][2], int counts[13]) {
    for (int i = 0; i < 13; ++i) counts[i] = 0;
    for (int i = 0; i < 5; ++i) {
        counts[hand[i][1]]++;
    }
}

// Evaluation logic functions
bool CardGame::isPair() {
    if (!hasDealt) {
        return true;
    }
    int counts[13];
    calculateFrequencies(hand, counts);
    int pairCount = 0;
    for (int i = 0; i < 13; ++i) {
        if (counts[i] == 2) pairCount++;
    }
    return pairCount == 1;
}

bool CardGame::isTwoPair() {
    if (!hasDealt) {
        return true;
    }
    int counts[13];
    calculateFrequencies(hand, counts);
    int pairCount = 0;
    for (int i = 0; i < 13; ++i) {
        if (counts[i] == 2) pairCount++;
    }
    return pairCount == 2;
}

bool CardGame::isThreeOfAKind() {
    if (!hasDealt) {
        return true;
    }
    int counts[13];
    calculateFrequencies(hand, counts);
    for (int i = 0; i < 13; ++i) {
        if (counts[i] == 3) return true;
    }
    return false;
}

bool CardGame::isFourOfAKind() {
    if (!hasDealt) {
        return false;
    }
    int counts[13];
    calculateFrequencies(hand, counts);
    for (int i = 0; i < 13; ++i) {
        if (counts[i] == 4) return true;
    }
    return false;
}

bool CardGame::isFlush() {
    if (!hasDealt) {
        return false;
    }
    int firstSuit = hand[0][0];
    for (int i = 1; i < 5; ++i) {
        if (hand[i][0] != firstSuit) {
            return false;
        }
    }
    return true;
}

bool CardGame::isStraight() {
    if (!hasDealt) {
        return false;
    }
    int ranks[5];
    for (int i = 0; i < 5; ++i) {
        ranks[i] = hand[i][1];
    }
    sort(ranks, ranks + 5);

    bool consecutive = true;
    for (int i = 0; i < 4; ++i) {
        if (ranks[i + 1] != ranks[i] + 1) {
            consecutive = false;
            break;
        }
    }
    if (consecutive) {
        return true;
    }

    // Check Ace-low straight (Ace, 2, 3, 4, 5)
    if (ranks[0] == 0 && ranks[1] == 1 && ranks[2] == 2 && ranks[3] == 3 && ranks[4] == 12) {
        return true;
    }
    return false;
}

void CardGame::evaluateHand() {
    if (!hasDealt) {
        cout << endl << "⚠️  [ALERT] Please deal a hand before evaluating!" << endl;
        return;
    }

    cout << endl << "┌──────────────────────────────────────────┐" << endl;
    cout << "│       ♠♥♣♦ HAND EVALUATION ♦♣♥♠          │" << endl;
    cout << "├──────────────────────────────────────────┤" << endl;
    cout << "│  Pair            : " << (isPair() ? "[YES]" : "[NO ]") << "                 │" << endl;
    cout << "│  Two Pair        : " << (isTwoPair() ? "[YES]" : "[NO ]") << "                 │" << endl;
    cout << "│  Three of a Kind : " << (isThreeOfAKind() ? "[YES]" : "[NO ]") << "                 │" << endl;
    cout << "│  Four of a Kind  : " << (isFourOfAKind() ? "[YES]" : "[NO ]") << "                 │" << endl;
    cout << "│  Flush           : " << (isFlush() ? "[YES]" : "[NO ]") << "                 │" << endl;
    cout << "│  Straight        : " << (isStraight() ? "[YES]" : "[NO ]") << "                 │" << endl;
    cout << "└──────────────────────────────────────────┘" << endl;
}