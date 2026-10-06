# 🃏 PokerPal - Card Game Analysis App

**PokerPal** is a C++ application that simulates deck shuffling, card dealing, and poker hand evaluation using Object-Oriented Programming (OOP) principles, 2D arrays, pointers, and custom sorting algorithms. 

Developed as part of the CS2 / Data Structures I course under the guidance of **Dr. Victor Govindaswamy**.

---

## 📌 Features

* **Deck Representation:** Standard 52-card deck modeled as a $4 \times 13$ 2D array (4 suits $\times$ 13 ranks).
* **High-Performance Shuffling:** Iterative array-swapping algorithm utilizing raw C++ pointers to randomize card locations.
* **Duplicate Prevention:** Hand dealing tracks used cards via a 2D boolean grid to prevent duplicate cards from being drawn.
* **Hand Evaluation Engine:** Algorithmic detection for key 5-card poker combinations:
  * Pair
  * Two Pair
  * Three of a Kind
  * Four of a Kind
  * Flush
  * Straight (including Ace-low straights: A-2-3-4-5)
* **Terminal UI:** Clean CLI interface formatted with ASCII borders and suit symbols (`♠`, `♥`, `♣`, `♦`).

---

## 🛠️ Tech Stack & Concepts Applied

* **Language:** C++ (C++11 or higher recommended)
* **Architecture:** Modular Header/Implementation separation (`CardGame.h`, `CardGame.cpp`, `CardGameTest.cpp`)
* **Concepts:** 
  * 2D Arrays & Matrix Indexing
  * Enums (`Suit`, `Rank`)
  * Raw Pointers for Memory Manipulation
  * Randomization (`cstdlib`, `ctime`)
  * Sorting & Array Frequency Analysis
 
---

## How to Run
Compile and run the program using a C++ compiler:

```bash
g++ *.cpp -o CardGame.exe
./CardGame.exe
```
