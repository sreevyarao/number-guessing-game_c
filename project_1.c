#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice, max, attempts, guessed;
    char playAgain;
    int bestScore = 0;

    srand(time(0));

    printf("==== Smart Number Guessing Game ====\n");

    do {
        printf("\nSelect Difficulty:\n");
        printf("1. Easy (1-50, 10 attempts)\n");
        printf("2. Medium (1-100, 7 attempts)\n");
        printf("3. Hard (1-200, 5 attempts)\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if(choice == 1) {
            max = 50; attempts = 10;
        } else if(choice == 2) {
            max = 100; attempts = 7;
        } else {
            max = 200; attempts = 5;
        }

        int randomNumber = (rand() % max) + 1;
        int count = 0;
        int won = 0;

        printf("\nGuess the number between 1 and %d\n", max);

        while(count < attempts) {
            printf("Attempt %d/%d: ", count + 1, attempts);
            scanf("%d", &guessed);

            count++;

            if(guessed == randomNumber) {
                printf("Correct! You guessed it in %d attempts.\n", count);
                int score = (attempts - count + 1) * 10;
                printf("Your Score: %d\n", score);

                if(score > bestScore) {
                    bestScore = score;
                    printf("New High Score!\n");
                }

                won = 1;
                break;
            }

            int diff = abs(guessed - randomNumber);

            if(diff <= 3)
                printf("Very close!\n");
            else if(diff <= 10)
                printf("Close!\n");

            if(guessed > randomNumber)
                printf("Lower number!\n");
            else
                printf("Higher number!\n");
        }

        if(!won) {
            printf("Out of attempts! The number was %d\n", randomNumber);
        }

        printf("Best Score so far: %d\n", bestScore);

        printf("\nDo you want to play again? (y/n): ");
        scanf(" %c", &playAgain);

    } while(playAgain == 'y' || playAgain == 'Y');

    printf("Thanks for playing!\n");
    return 0;
}