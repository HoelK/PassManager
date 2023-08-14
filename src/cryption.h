#ifndef CRYPTION_H
#define CRYPTION_H

#include <stdio.h>

void encryption(int nblines,FILE **FileToEncrypt, int renamechoice);
void decryption(int nblines,FILE **FileToDecrypt, int renamechoice);

#endif
