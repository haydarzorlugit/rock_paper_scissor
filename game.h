#ifndef GAME_H
#define GAME_H

#define RANGE_STONE     33
#define RANGE_PAPER     66
#define RANGE_SCISSORS  99

#define USER_WINS       1
#define COMPUTER_WINS   0
#define EQUAL           -1


char generate_computer_choice(void);


int rock_paper_scissors(char we, char computer);


const char* move_to_string(char move);

#endif

