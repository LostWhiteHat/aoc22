#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Rucksack
{
    unsigned char first_compartement[30];
    unsigned char second_compartment[30];
};

enum Lowercase
{
    a = 1,
    b = 2,
    c = 3,
    d = 4,
    e = 5,
    f = 6,
    g = 7,
    h = 8,
    i = 9,
    j = 10,
    k = 11,
    l = 12,
    m = 13,
    n = 14,
    o = 15,
    p = 16,
    q = 17,
    r = 18,
    s = 19,
    t = 20,
    u = 21,
    v = 22,
    w = 23,
    x = 24,
    y = 25,
    z = 26
};

enum Uppercase
{
    A = 27,
    B,
    C,
    D,
    E,
    F,
    G,
    H,
    I,
    J,
    K,
    L,
    M,
    N,
    O,
    P,
    Q,
    R,
    S,
    T,
    U,
    V,
    W,
    X,
    Y,
    Z,
};

int main()
{
    FILE *fptr;
    char *line = NULL;
    size_t len = 0;
    size_t read;

    int line_counter = 0;
    int half_line = 0;
    int char_counter = 0;

    int total = 0;

    struct Rucksack rucksack;
    struct Rucksack reset_rucksack;

    enum Lowercase lowercase;
    enum Uppercase uppercase;
    fptr = fopen("./input.txt", "r");
    if (fptr == NULL)
        exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, fptr)) != -1)
    {
        for (int i = 0; i < 60; i++)
        {
            if (line[i] == 0)
                break;
            line_counter++;
        }
        half_line = (line_counter - 2) / 2;
        for (int j = 0; j < line_counter - 2; j++)
        {
            if (j < half_line)
            {
                rucksack.first_compartement[j] = line[j];
            }
            else
            {
                if (j == half_line)
                {
                    rucksack.first_compartement[j] = 0;
                }
                rucksack.second_compartment[char_counter] = line[j];
                char_counter++;
            }
        }
        rucksack.second_compartment[char_counter] = 0;

        char_counter = 0;
        line_counter = 0;
        char compared_char;
        int done = 0;
        for (int x = 0; x < half_line; x++)
        {
            if (done)
                break;
            compared_char = rucksack.first_compartement[x];
            for (int y = 0; y < half_line; y++)
            {
                if (compared_char == rucksack.second_compartment[y])
                {
                    if (isupper(compared_char))
                    {
                        switch (compared_char)
                        {
                        case 'A':
                            uppercase = A;
                            break;
                        case 'B':
                            uppercase = B;
                            break;
                        case 'C':
                            uppercase = C;
                            break;
                        case 'D':
                            uppercase = D;
                            break;
                        case 'E':
                            uppercase = E;
                            break;
                        case 'F':
                            uppercase = F;
                            break;
                        case 'G':
                            uppercase = G;
                            break;
                        case 'H':
                            uppercase = H;
                            break;
                        case 'I':
                            uppercase = I;
                            break;
                        case 'J':
                            uppercase = J;
                            break;
                        case 'K':
                            uppercase = K;
                            break;
                        case 'L':
                            uppercase = L;
                            break;
                        case 'M':
                            uppercase = M;
                            break;
                        case 'N':
                            uppercase = N;
                            break;
                        case 'O':
                            uppercase = O;
                            break;
                        case 'P':
                            uppercase = P;
                            break;
                        case 'Q':
                            uppercase = Q;
                            break;
                        case 'R':
                            uppercase = R;
                            break;
                        case 'S':
                            uppercase = S;
                            break;
                        case 'T':
                            uppercase = T;
                            break;
                        case 'U':
                            uppercase = U;
                            break;
                        case 'V':
                            uppercase = V;
                            break;
                        case 'W':
                            uppercase = W;
                            break;
                        case 'X':
                            uppercase = X;
                            break;
                        case 'Y':
                            uppercase = Y;
                            break;
                        case 'Z':
                            uppercase = Z;
                            break;
                        }
                        done = 1;
                        total += uppercase;
                    }
                    else
                    {
                        switch (compared_char)
                        {
                        case 'a':
                            lowercase = a;
                            break;
                        case 'b':
                            lowercase = b;
                            break;
                        case 'c':
                            lowercase = c;
                            break;
                        case 'd':
                            lowercase = d;
                            break;
                        case 'e':
                            lowercase = e;
                            break;
                        case 'f':
                            lowercase = f;
                            break;
                        case 'g':
                            lowercase = g;
                            break;
                        case 'h':
                            lowercase = h;
                            break;
                        case 'i':
                            lowercase = i;
                            break;
                        case 'j':
                            lowercase = j;
                            break;
                        case 'k':
                            lowercase = k;
                            break;
                        case 'l':
                            lowercase = l;
                            break;
                        case 'm':
                            lowercase = m;
                            break;
                        case 'n':
                            lowercase = n;
                            break;
                        case 'o':
                            lowercase = o;
                            break;
                        case 'p':
                            lowercase = p;
                            break;
                        case 'q':
                            lowercase = q;
                            break;
                        case 'r':
                            lowercase = r;
                            break;
                        case 's':
                            lowercase = s;
                            break;
                        case 't':
                            lowercase = t;
                            break;
                        case 'u':
                            lowercase = u;
                            break;
                        case 'v':
                            lowercase = v;
                            break;
                        case 'w':
                            lowercase = w;
                            break;
                        case 'x':
                            lowercase = x;
                            break;
                        case 'y':
                            lowercase = y;
                            break;
                        case 'z':
                            lowercase = z;
                            break;
                        }
                        done = 1;
                        total += lowercase;
                    }
                    if (done)
                        break;
                }
            }
        }
        rucksack = reset_rucksack;
        half_line = 0;
    }
    printf("%d\n", total);

    exit(EXIT_SUCCESS);
}