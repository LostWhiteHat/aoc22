#include <stdio.h>
#include <stdlib.h>

struct Round
{
    char enemy;
    char me;
    int points;
};

void part_one()
{
    FILE *fptr;
    char *line = NULL;
    size_t len = 0;
    size_t read;

    struct Round round[2500];
    struct Round round_element;
    struct Round reset_round;
    int round_counter = 0;

    fptr = fopen("./input.txt", "r");
    if (fptr == NULL)
        exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, fptr)) != -1)
    {
        round_element.enemy = line[0];
        round_element.me = line[2];
        switch (round_element.enemy)
        {
        case 'A':
            switch (round_element.me)
            {
            case 'X':
                round_element.points += 4;
                break;
            case 'Y':
                round_element.points += 8;
                break;
            case 'Z':
                round_element.points += 3;
                break;
            }
            break;

        case 'B':
            switch (round_element.me)
            {
            case 'X':
                round_element.points += 1;
                break;
            case 'Y':
                round_element.points += 5;
                break;
            case 'Z':
                round_element.points += 9;
                break;
            }
            break;

        case 'C':
            switch (round_element.me)
            {
            case 'X':
                round_element.points += 7;
                break;
            case 'Y':
                round_element.points += 2;
                break;
            case 'Z':
                round_element.points += 6;
                break;
            }
            break;
        }
        round[round_counter] = round_element;
        round_counter++;
        round_element = reset_round;
    }

    int total = 0;
    for (int i = 0; i < 2500; i++)
    {
        total += round[i].points;
    }
    printf("Part 1: %d\n", total);
    fclose(fptr);
    if (line)
        free(line);
}

void part_two()
{
    FILE *fptr;
    char *line = NULL;
    size_t len = 0;
    size_t read;

    struct Round round_two[2500];
    struct Round round_e;
    struct Round reset_round;
    int round_counter = 0;

    fptr = fopen("./input.txt", "r");
    if (fptr == NULL)
        exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, fptr)) != -1)
    {
        round_e.enemy = line[0];
        round_e.me = line[2];
        switch (round_e.me)
        {
        case 'X':
            switch (round_e.enemy)
            {
            case 'A':
                round_e.points += 3;
                break;
            case 'B':
                round_e.points += 1;
                break;
            case 'C':
                round_e.points += 2;
                break;
            }
            break;

        case 'Y':
            switch (round_e.enemy)
            {
            case 'A':
                round_e.points += 4;
                break;
            case 'B':
                round_e.points += 5;
                break;
            case 'C':
                round_e.points += 6;
                break;
            }
            break;

        case 'Z':
            switch (round_e.enemy)
            {
            case 'A':
                round_e.points += 8;
                break;
            case 'B':
                round_e.points += 9;
                break;
            case 'C':
                round_e.points += 7;
                break;
            }
            break;
        }
        round_two[round_counter] = round_e;
        round_counter++;
        round_e = reset_round;
    }

    int point = 0;
    for (int i = 0; i < 2500; i++)
    {
        point += round_two[i].points;
    }
    printf("Part 2: %d\n", point);

    fclose(fptr);
    if (line)
        free(line);
}

int main()
{
    part_one();
    part_two();
    exit(EXIT_SUCCESS);
}