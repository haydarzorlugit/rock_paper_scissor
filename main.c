#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include "game.h"

int main()
{
    srand(time(NULL));

    int win_count = 0, lose_count = 0, draw_count = 0;
    int current_streak = 0, best_streak = 0, total_games = 0;
    char play_again;
    char username[100];

    printf("Enter your name: ");
    scanf("%99s", username);

    printf("\nWelcome, %s! Let's play Rock-Paper-Scissors (Best-of-3)!\n\n", username);

    do
    {
        int user_round_wins = 0;
        int computer_round_wins = 0;

        while (user_round_wins < 2 && computer_round_wins < 2)
        {
            char we, computer;
            int result;

            printf("---------------------------\n");
            printf("---- Enter r for ROCK -----\n");
            printf("---- Enter p for PAPER ----\n");
            printf("---- Enter s for SCIS. ----\n");
            printf("---------------------------\n");

            scanf(" %c", &we);
            we = tolower(we);

            if (we != 'r' && we != 'p' && we != 's')
            {
                printf("Invalid selection\n");
                continue;
            }

            computer = generate_computer_choice();
            result = rock_paper_scissors(we, computer);

            printf("You choose:      %s\n", move_to_string(we));
            printf("Computer choose: %s\n", move_to_string(computer));

            switch (result)
            {
                case EQUAL:
                    printf(">>> DRAW <<<\n\n");
                    draw_count++;
                    break;

                case USER_WINS:
                    user_round_wins++;
                    printf(">>> You win this round! (%d - %d)\n\n", user_round_wins, computer_round_wins);
                    break;

                case COMPUTER_WINS:
                    computer_round_wins++;
                    printf(">>> Computer wins this round! (%d - %d)\n\n", user_round_wins, computer_round_wins);
                    break;

                default:
                    printf("An error occurred\n");
                    break;
            }
        }

        total_games++;

        if (user_round_wins == 2)
        {
            printf("*** YOU WON THE TOURNAMENT! ***\n\n");
            win_count++;
            current_streak++;
            if (current_streak > best_streak)
                best_streak = current_streak;
        }
        else
        {
            printf("*** COMPUTER WON THE TOURNAMENT! ***\n\n");
            lose_count++;
            current_streak = 0;
        }

        printf("Do you want to play another tournament? (y/n): ");
        scanf(" %c", &play_again);

    } while (play_again == 'y' || play_again == 'Y');


    printf("\n=============================\n");
    printf("   Final Score for %s\n", username);
    printf(" Tournament Wins:   %d\n", win_count);
    printf(" Tournament Losses: %d\n", lose_count);
    printf(" Draw Rounds:       %d\n", draw_count);
    printf(" Best Win Streak:   %d\n", best_streak);
    printf(" Total Played:      %d\n", total_games);
    printf("=============================\n");


    FILE *fp = fopen("score.txt", "a");
    if (fp == NULL)
    {
        perror("score.txt cannot be opened for writing");
        return 1;
    }

    fprintf(fp, "Username: %s\n", username);
    fprintf(fp, "Wins: %d | Losses: %d | Draws: %d | Best Streak: %d | Total Games: %d\n",
            win_count, lose_count, draw_count, best_streak, total_games);
    fprintf(fp, "-----------------------------\n");

    fclose(fp);


    printf("\n=== SCORE HISTORY ===\n");

    FILE *fr = fopen("score.txt", "r");
    if (fr == NULL)
    {
        perror("score.txt cannot be opened for reading");
    }
    else
    {
        char line[256];
        while (fgets(line, sizeof(line), fr))
        {
            printf("%s", line);
        }
        fclose(fr);
    }

    return 0;
}


