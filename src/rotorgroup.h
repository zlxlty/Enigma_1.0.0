/*
* =================================================
*       Filename:  rotorgroup.h
*        Version:  1.0.0
*        Created:  12/15/18 09:48:25
*       Compiler:  gcc
*         Coding:  UTF-8
*         Author:  Tianyi Lu
* =================================================
*/
#ifndef _ROTORGROUP_H_
#define _ROTORGROUP_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"
#include "rotors.h"
#include "settings.h"

typedef struct _rotorgroup {
    Rotorhead *pAlphts[4];
    Rotorhead *pCiphts[4];
} Rotorgroup;

Rotorgroup *InitRotorGroup();
Rotorgroup *SetEnigmaRotors(const char pos[3], const char key[4]);
char RightEncrypt(Rotorgroup *pRg, int index, char lttr);
char LeftEncrypt(Rotorgroup *pRg, int index, char lttr);
char Reflector(char lttr);
char PlugboardEncryption(char plugboard[13], char lttr);
char RotorsEncryption(Rotorgroup *pRg, char lttr);

#endif