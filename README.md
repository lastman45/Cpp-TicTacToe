# Tic Tac Toe — C++ Console Game

A two-player Tic Tac Toe game for the terminal, written in C++. Players take turns entering numbered positions to place their marks, and the game detects wins, draws, and invalid moves automatically.

---

## Table of Contents

- [Features](#features)
- [Requirements](#requirements)
- [Building & Running](#building--running)
- [How to Play](#how-to-play)
- [Board Layout](#board-layout)
- [Game Rules](#game-rules)
- [Project Structure](#project-structure)
- [Code Overview](#code-overview)
- [Known Limitations](#known-limitations)

---

## Features

- Two-player local gameplay (Player 1 = `X`, Player 2 = `O`)
- Automatic win detection (rows, columns, and diagonals)
- Draw detection when all squares are filled with no winner
- Input validation — invalid or already-occupied moves are rejected
- Replay prompt after each game ("TieBreaker" mode)
- Board resets cleanly between games

---

## Requirements

| Requirement | Details |
|---|---|
| Compiler | Any C++11-compliant compiler (g++, clang++, MSVC) |
| OS | Windows (uses `system("cls")` for screen clearing) |
| Standard Library | `<iostream>` only — no external dependencies |

> **Note:** The game calls `system("cls")` to clear the screen, which is Windows-specific. On Linux/macOS, replace `"cls"` with `"clear"` in the `Check()` function.

---

## Building & Running

### Windows (g++ / MinGW)

```bash
g++ -o tictactoe TicTacToe.cpp
./tictactoe
```

### Windows (MSVC)

```bash
cl TicTacToe.cpp /Fe:tictactoe.exe
tictactoe.exe
```

### Linux / macOS (after replacing `cls` with `clear`)

```bash
g++ -o tictactoe TicTacToe.cpp
./tictactoe
```

---

## How to Play

1. The board is displayed with numbered positions `1–9`.
2. **Player 1 (X)** goes first. Enter the number of the cell you want to occupy and press Enter.
3. **Player 2 (O)** goes next and does the same.
4. Players alternate turns until someone wins or the board is full (draw).
5. After the game ends, you are asked whether you want to play again (`Y/N`).

---

## Board Layout

Positions are numbered as follows:

```
     |     |
  1  |  2  |  3
_____|_____|_____
     |     |
  4  |  5  |  6
_____|_____|_____
     |     |
  7  |  8  |  9
     |     |
```

Enter the number corresponding to the cell you wish to play. Once a cell is occupied, it cannot be chosen again.

**Example mid-game board:**

```
     |     |
  X  |  2  |  O
_____|_____|_____
     |     |
  4  |  X  |  6
_____|_____|_____
     |     |
  7  |  8  |  O
     |     |
```

---

## Game Rules

- The first player to get **three marks in a row** — horizontally, vertically, or diagonally — wins.
- If all nine cells are filled and no player has three in a row, the game is a **draw**.
- Entering a number outside `1–9`, or choosing an already-occupied cell, is treated as an **invalid move** — the player is prompted to try again without losing their turn.

---

## Project Structure

```
TicTacToe.cpp       # Single-file source — all game logic lives here
README.md           # This file
```

### Source file breakdown

| Function | Responsibility |
|---|---|
| `main()` | Game loop, player switching, input handling, replay prompt |
| `Winner()` | Checks all 8 win conditions + draw condition; returns `1` (win), `0` (draw), or `-1` (continue) |
| `Check()` | Clears the screen and re-renders the current board state |
| `ResetGame()` | Resets `GameElements[]` back to digits `1–9` for a fresh game |

### Key data structure

```cpp
char GameElements[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
```

Index `0` is unused. Indices `1–9` hold the current state of each cell: either its original digit (unplayed) or `'X'` / `'O'` (played).

---

## Code Overview

### Player switching

```cpp
Player = (Player % 2) ? 1 : 2;
```

Before each turn, `Player` is mapped to `1` or `2` based on its parity. At the end of the turn it is incremented with `Player++`, so it naturally alternates.

### Move validation

```cpp
if (c >= 1 && c <= 9 && GameElements[c] == '0' + c)
```

A move is valid only if the input is in range **and** the cell still holds its original digit (i.e., it hasn't been played yet).

### Win detection

`Winner()` checks all eight possible three-in-a-row combinations:

- 3 horizontal rows
- 3 vertical columns
- 2 diagonals

A draw is detected when every cell has been replaced (none still equals its original digit).

---

## Known Limitations

- **Windows-only screen clearing** — `system("cls")` will not work on Linux/macOS without modification.
- **No single-player / AI mode** — both players must be human.
- **Console input only** — no GUI.
- **Global state** — `GameElements` is a global array; the design is not easily extensible to multiple concurrent games.
- **No input type checking** — entering a non-integer (e.g. a letter) will cause `cin` to enter a fail state and loop infinitely. Adding `cin.clear()` and `cin.ignore()` after bad input would make the game more robust.
