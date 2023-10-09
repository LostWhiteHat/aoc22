#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

struct Elf
{
    long cal[20];
    long total;
};

int main()
{
    FILE *fptr;
    char *line = NULL;
    size_t len = 0;
    size_t read;

    int counter = 0;
    int elfCounter = 0;
    struct Elf elf[250];

    fptr = fopen("./input.txt", "r");
    if (fptr == NULL)
        exit(EXIT_FAILURE);

    struct Elf elfElement;
    struct Elf resetElf;
    while ((read = getline(&line, &len, fptr)) != -1)
    {
        long i;
        sscanf(line, "%d", &i);
        if (read == 2)
        {
            for (int j = 0; j < 20; j++)
            {
                elfElement.total += elfElement.cal[j];
            }
            elf[elfCounter] = elfElement;
            // printf("%d\n", elf[elfCounter].total);
            elfCounter++;
            elfElement = resetElf;
            counter = 0;
        }
        else
        {
            elfElement.cal[counter] = i;
            counter++;
        }
    }

    long top[3] = {0, 0, 0};

    for (int i = 0; i < 250; i++)
    {

        if (elf[i].total == 0)
            break;
        if (elf[i].total > top[0])
        {
            if (top[1] > top[2])
                top[2] = top[1];
            if (top[0] > top[1])
                top[1] = top[0];
            top[0] = elf[i].total;
        }
        else if (elf[i].total > top[1])
        {
            if (top[1] > top[2])
                top[2] = top[1];
            top[1] = elf[i].total;
        }
        else if (elf[i].total > top[2])
        {
            top[2] = elf[i].total;
        }
    }

    printf("part 1: %d\n", top[0]);
    printf("part 2: %d\n", top[0] + top[1] + top[2]);

    fclose(fptr);
    if (line)
        free(line);
    exit(EXIT_SUCCESS);
}