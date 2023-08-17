#ifndef CRYPTION_H
#define CRYPTION_H

#include <stdio.h>

void encryption(int nblines,FILE **FileToEncrypt, int renamechoice);	//Encrypt a file
void decryption(int nblines,FILE **FileToDecrypt, int renamechoice);	//Decrypt a file
void encryptline(char cryptedline[]);									//Encrypt a line and put it in an array

#endif
