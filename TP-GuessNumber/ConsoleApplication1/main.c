#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
    const int MAX = 100, MIN = 1;
    srand(time(NULL));
    int randomNumber = (rand() % (MAX - MIN + 1)) + MIN;
    int searchedNumber;

    do {
        printf("Choose your number: ");
        scanf_s("%d", &searchedNumber);
        if (randomNumber < searchedNumber) {
            printf("Your number is superior.\n");
        } else if (randomNumber > searchedNumber) {
            printf("Your number is inferior.\n");
        } else {
            printf("Congratulation you found the number\n");
        }
    } while (randomNumber != searchedNumber);

    return 0;
}

