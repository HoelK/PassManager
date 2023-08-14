#include <stdio.h>
#include <stddef.h>
#include <string.h>

#include "masterpass.h"
#include "cryption.h"

void getmasterpass(char masterpass[]) //Get the masterpass into and array
{
	FILE *decryptmasterFILE = NULL;
	FILE *encryptmasterFILE = NULL;
	FILE *getmasterFILE = NULL;

	decryptmasterFILE = fopen("UserData/masterpass.txt", "r");
	decryption(1, &decryptmasterFILE, 3);

	getmasterFILE = fopen("UserData/masterpass.txt", "r");
	fgets(masterpass, 27, getmasterFILE);

	encryptmasterFILE = fopen("UserData/masterpass.txt", "r");
	encryption(1, &encryptmasterFILE, 3);
}

void askmaster(char masterpass[]) //Ask the masterpass to the user
{
	//Array that will contain respectively the pass and the user input
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

void createmaster() //Ask the user to create the masterpass
{
	//Array that will contain the new pass
	char masterpass[27];

	//Ask the password
	printf("Create your main password that will secure your database (25 char max) : ");
	fgets(masterpass, 27, stdin);

	//Print it into the file
	FILE *masterFILE = fopen("UserData/masterpass.txt", "w+");
	fprintf(masterFILE, "%s", masterpass);
	fclose(masterFILE);
}
