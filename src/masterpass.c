#include <stdio.h>
#include <stddef.h>
#include <string.h>

#include "masterpass.h"
#include "cryption.h"

void getmasterpass(char masterpass[])
{
	FILE *decryptmasterFILE = NULL;
	FILE *encryptmasterFILE = NULL;
	FILE *getmasterFILE = NULL;

	decryptmasterFILE = fopen("UserData/masterpass.txt", "r");
	decryption(1, &decryptmasterFILE, 3);

	getmasterFILE = fopen("UserData/masterpass.txt", "r");
	fgets(masterpass, 27, getmasterFILE);
	fclose(getmasterFILE);

	encryptmasterFILE = fopen("UserData/masterpass.txt", "r");
	encryption(1, &encryptmasterFILE, 3);
}

void askmaster(char masterpass[])
{
	//Array that will contain the pass
	char masterinput[27] = {0};

	//Password verification loop
	do 
	{
		printf("Main password : ");
		fgets(masterinput, 27, stdin);
		masterinput[strlen(masterpass) + 1] = '\0';

		if(strcmp(masterinput, masterpass) != 0)
			printf("Error :Wrong password\n");
	}while(strcmp(masterinput, masterpass) != 0);
}

void createmaster()
{
	//Array that will contain the new pass
	char masterpass[27];

	//Ask the password then encrypt it
	printf("Create your main password that will secure your database (25 char max) : ");
	fgets(masterpass, 27, stdin);

	//Print it into the file
	FILE *masterFILE = fopen("UserData/masterpass.txt", "w+");
	fprintf(masterFILE, "%s", masterpass);
	fclose(masterFILE);
}
