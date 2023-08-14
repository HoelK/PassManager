#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "interactions.h"
#include "cryption.h"
#include "basesfunc.h"

int choice() //Ask what the user want to do and return the choice
{
	int usrchoice = 0;

	printf("Display your passwords................1\n");
	printf("Add a password........................2\n");
	printf("Delete a password.....................3\n");
	printf("Generate a random secured password....4\n");
	printf("Quit..................................0\n");

	do
	{
		printf("Choose an action : ");
		scanf("%d", &usrchoice);
		emptybuffer();
	}while(usrchoice < 0 || usrchoice > 4);

	return usrchoice;
}

void displaydata(int nblines, FILE **descFILE, FILE **passFILE) //Show every passwords
{
	char outputdesc[27] = {0};
	char outputpass[27] = {0};

	*descFILE = fopen("UserData/desc.txt", "r");
	*passFILE = fopen("UserData/pass.txt", "r");
	
	printf("Description");
	printf("\t\t\t\tPassword\n\n");

	for (int i = 0; i < nblines; i++)
	{
		fgets(outputdesc, 27, *descFILE);
		outputdesc[strcspn(outputdesc, "\n")] = 0; //The line already has a \n and fgets add an extra one we need to delete
		printf("%-25s    ", outputdesc);

		fgets(outputpass, 27, *passFILE);
		printf("%25s", outputpass);
	}
	fclose(*passFILE);
	fclose(*descFILE);
}

void newpass(FILE **descFILE, FILE **passFILE) //Add a password
{
	char desc[57] = {0}, pass[57] = {0};

	//Adding the descrition in the file
	printf("Enter a description site/email... (25 char max) : ");
	fgets(desc, 27, stdin);

	encryptline(desc);
	*descFILE = fopen("UserData/desc.txt", "a");
	fprintf(*descFILE, "%s\n", desc);
	fclose(*descFILE);

	//Adding the password in the file
	printf("Entrer a password (25 char max): ");
	fgets(pass, 27, stdin);

	encryptline(pass);
	*passFILE = fopen("UserData/pass.txt", "a");
	fprintf(*passFILE, "%s\n", pass);
	fclose(*passFILE);
}

void deletepass(int nblines, FILE **descFILE, FILE **passFILE) //Delete a password
{
	int line = 1, deleteline= 0;
	char descLine[27] = {0}, passLine[27] = {0};
	FILE *tempDesc = NULL;
	FILE *tempPass = NULL;

	printf("Select the number of the line to delete : ");
	scanf("%d", &deleteline);

	*descFILE = fopen("UserData/desc.txt", "r");
	*passFILE = fopen("UserData/pass.txt", "r");
	tempDesc = fopen("UserData/tempdesc.txt", "a");
	tempPass = fopen("UserData/temppass.txt", "a");

	//Get every line of the file one by one and put it on a new file if i isn't the identity of the deleted line
	for(int i = 0; i < nblines; i++)
	{
		fgets(descLine, 27, *descFILE);
		fgets(passLine, 27, *passFILE);

		if(line != deleteline)
		{
			fputs(descLine, tempDesc);
			fputs(passLine, tempPass);
		}
		line++;
	}

	//Close then rename the new files and delete the old one
	fclose(*descFILE);
	fclose(*passFILE);
	fclose(tempDesc);
	fclose(tempPass);
	remove("UserData/desc.txt");
	remove("UserData/pass.txt");
	rename("UserData/tempdesc.txt", "UserData/desc.txt");
	rename("UserData/temppass.txt", "UserData/pass.txt");
}

void randompass(FILE **descFILE, FILE **passFILE) //Generate a random secured password
{
	srand(time(NULL));	//Set the seed and rand() to generate a random password
	char desc[57] = {0}, pass[57] = {0};
	char passcharlist[84] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789%*/-+=;!?_(){}[]<>#~&@";

	printf("Enter a description site/email... (25 char max) : ");
	fgets(desc, 27, stdin);

	encryptline(desc);
	//Add the descrition in the file
	*descFILE = fopen("UserData/desc.txt", "a");
	fprintf(*descFILE, "%s\n", desc);
	fclose(*descFILE);

	//Put a random char from the passcharlist into each pass case
	for(int i = 0; i != 25; i++)
	{
		pass[i] = passcharlist[(rand() % 83 - 0 + 1) + 0];
	}

	pass[25] = '\n';

	encryptline(pass);
	//Add the pass in the file
	*passFILE = fopen("UserData/pass.txt", "a");
	fprintf(*passFILE, "%s\n", pass);
	fclose(*passFILE);
}
