#include "CardGame.h"

// function prototypes
void displayMenu();
void handleMenuOption(CardGame &game, int option);

int main() {
    CardGame game;

    int choice = 0;

    while(choice != 6) {
        // CardGame game;
        displayMenu();

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore();
            cout << endl << "❌ [ERROR] Invalid entry. Please enter a valid menu integer." << endl;
            continue;
        }
        handleMenuOption(game, choice);
    }
}

void displayMenu() {
    cout << endl << "╔══════════════════════════════════════╗" << endl;
    cout << "║        ♠♥♣♦ POKERPAL MENU ♦♣♥♠       ║" << endl;
    cout << "╠══════════════════════════════════════╣" << endl;
    cout << "║  1. Shuffle Deck                     ║" << endl;
    cout << "║  2. Deal Hand                        ║" << endl;
    cout << "║  3. Display Hand                     ║" << endl;
    cout << "║  4. Evaluate Hand                    ║" << endl;
    cout << "║  5. Display Full Deck                ║" << endl;
    cout << "║  6. Exit                             ║" << endl;
    cout << "╚══════════════════════════════════════╝" << endl;
    cout << "👉 Enter your choice [1-6]: ";
}

void handleMenuOption(CardGame &game, int option) {
    switch (option) {
        case 1:
            game.shuffleDeck();
            break;
        case 2:
            game.dealHand();
            break;
        case 3:
            game.displayHand();
            break;
        case 4:
            game.evaluateHand();
            break;
        case 5:
            game.displayDeck();
            break;
        case 6:
            cout << endl << "========================================" << endl;
            cout << "   Thanks for playing PokerPal! 👋      " << endl;
            cout << "========================================" << endl << endl;
            break;
        default:
            cout << endl << "⚠️  [INVALID] Choice out of bounds! Choose between 1 and 6." << endl;
            break;
    }
}