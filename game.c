#include <stdlib.h>
#include "game.h"

const char* move_to_string(char move)
{
    switch (move)
    {
        case 'r': return "ROCK";
        case 'p': return "PAPER";
        case 's': return "SCISSORS";
        default: return "UNKNOWN";
    }
}

int rock_paper_scissors(char we, char computer)
{
    if (we == computer) return EQUAL;

    if (we == 'r' && computer == 'p') return COMPUTER_WINS;
    if (we == 'p' && computer == 'r') return USER_WINS;
    if (we == 'r' && computer == 's') return USER_WINS;
    if (we == 's' && computer == 'r') return COMPUTER_WINS;
    if (we == 'p' && computer == 's') return COMPUTER_WINS;
    if (we == 's' && computer == 'p') return USER_WINS;

    return -2;
}

char generate_computer_choice(void)
{
    int number = rand() % 100;

    if (number < RANGE_STONE) return 'r';
    else if (number < RANGE_PAPER) return 'p';
    else return 's';
}

