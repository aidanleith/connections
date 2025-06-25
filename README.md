# Connections Explained
A terminal-based C program inspired by the New York Times Connections game. The goal is to group related words into sets of four. Players get 4 lives and must find all 4 groups to win.

## Features
- Linked list-based word storage
- Input validation and game logic checking
- Group removal on correct match
- Dynamic memory allocation
- Clean CLI interaction
- Tracks lives and correct guesses

## How to Play
1. A linked list of 16 words is initialized, each assigned to one of four hidden groups.
2. The player inputs 4 words they believe form a valid group.
3. If the guess is correct, those words are removed from the list.
4. The game ends when either all 4 groups are correctly found or the user runs out of lives.

## Technologies
- Language: C
- DSA: Linked Lists, Dynamic Memory Allocation, Dynamic 2D Arrays, String Manipulation

