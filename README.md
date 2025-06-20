Rock Paper Scissors (Best-of-3) - C Console Game

A simple and interactive Rock-Paper-Scissors game written in C.  
Each game is played in a Best-of-3 format — the first to 2 wins takes the round.

  Features

- Username input at game start
- Best-of-3 tournament mode
- Tracks wins, losses, and draws
- Tracks best win streak
- All scores are saved to `score.txt`
- Displays entire score history from file after each game session

  Project Structure
 ```plaintext
rock_paper_scissor/
├── main.c
├── game.c
├── game.h
├── Makefile
└── score.txt
 ```

  Requirements

- gcc (or any C99-compatible compiler)

- make (optional, if using the Makefile)