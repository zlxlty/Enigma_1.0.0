/*
* =================================================
*       Filename:  input.c
*        Version:  1.0.0
*        Created:  12/15/18 09:48:25
*       Compiler:  gcc
*         Coding:  UTF-8
*         Author:  Tianyi Lu
* =================================================
*/
#include "input.h"

char *RotorPosInput(int filein)
{
    char c;
    int i = 1;
    char *tmpch = (char *)malloc(sizeof(char)*5);
    tmpch[0] = 'A';

    if (filein == 0)
        printf("Enter a three-digit Key: ");

    while (((c = getchar()) != EOF) && (i <= 3))
    {
        if (c == ' ' || c == '\t' || c == '\n')
            continue;

        tmpch[i++] = toupper(c);
    }

    tmpch[i] = '\0';

    return tmpch;
}

char *PlugboardInput(int filein)
{
    char c;
    int i = 0;
    char *tmpch = (char *)malloc(sizeof(char)*13);

    if (filein == 0)
        printf("Enter a 12-digit Plugboard: ");

    while (((c = getchar()) != EOF) && (i <= 11))
    {
        if (c == ' ' || c == '\t' || c == '\n')
            continue;

        tmpch[i++] = toupper(c);
    }

    tmpch[i] = '\0';

    return tmpch;
}

char *RotorOrderInput(int filein)
{
    char c;
    int i = 0;
    char *tmppos = (char *)malloc(sizeof(char)*4);

    if (filein == 0)
        printf("Enter rotors' position: ");

    while (((c = getchar()) != EOF) && (i <= 2))
    {
        if (c == ' ' || c == '\t' || c == '\n' || c < '1' || c > '3')
            continue;

        tmppos[i++] = c;
    }

    return tmppos;
}

Key *KeyInput(int filein)
{
    Key *pkey = (Key *)malloc(sizeof(Key));

    pkey->order = RotorOrderInput(filein);
    pkey->pos = RotorPosInput(filein);
    pkey->plugboard = PlugboardInput(filein);

    return pkey;
}

char TextInput()
{
    char c;
    while (((c = getchar()) == EOF) || c == ' ' || c == '\t' || c == '\n' || isalpha(c) == 0)
        if (c == '-')
            return c;

    return toupper(c);
}

void KeyRotation(char *key)
{
    if (key[1] != 'Z')
        key[1]++;
    else if (key[2] != 'Z')
    {
        key[1] = 'A';
        key[2]++;
    }
    else if (key[3] != 'Z')
    {
        key[2] = 'A';
        key[3]++;
    }
    else
        key[1] = key[2] = key[3] = 'A';
}


#if _INPUT_DEBUG_

int main(int argc, char const *argv[]) {

    int i;
    char *temp;
    // char ch = TextInput();
    // printf("%c\n", ch);
    // temp = KeyInput(0);
    // printf("%s\n", temp);
    temp = RotorOrderInput(0);
    printf("%s\n", temp);

    // for (i = 0; i < 1000; i++)
    // {
    //     KeyRotation(temp);
    //     printf("%s\n", temp);
    // }

    temp = PlugboardInput(0);
    printf("%s\n", temp);
    return 0;
}

#endif