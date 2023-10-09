#include <stdio.h>
#include <stdlib.h>

enum State
{
    ROCK,
    PAPER,
    SCISSORS,
    WIN,
    LOSE,
    DRAW,
    NONE
};

struct Round
{
    char enemy;
    char me;
    int points;
};

int main()
{
    FILE *fptr;
    char *line = NULL;
    size_t len = 0;
    size_t read;

    struct Round round[2000];
    struct Round roundElement;
    struct Round resetRound;

    fptr = fopen("./input.txt", "r");
    if (fptr == NULL)
        exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, fptr)) != -1)
    {
        roundElement.enemy = line[0];
        roundElement.me = line[2];
        }

    exit(EXIT_SUCCESS);
}