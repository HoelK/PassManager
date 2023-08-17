#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "cryption.h"
#include "basesfunc.h"

void encryption(int nblines, FILE **FileToEncrypt, int renamechoice)
{
	int cryptcount = 0, keycount = 0;
	char key[27] = {0}, linetocrypt[27] = {0}, cryptedline[57] = {0};

	FILE *tempFILE = fopen("UserData/temp.txt", "a");
	srand(time(NULL));

	for (int i = 0; i < nblines; i++)
	{
		//Get the line
		fgets(linetocrypt, 27, *FileToEncrypt);

		//Encryption algorythm
		for(int i = 0; i != strlen(linetocrypt) - 1; i++)
		{
			//Generate the key
			key[i] = (rand() % (126 - 33 + 1)) + 33;

			//Encryption of the line 
			if(key[i] + linetocrypt[i] > 220)
				linetocrypt[i] = (key[i] + linetocrypt[i]) - 188;
			else if(key[i] + linetocrypt[i] > 126)
				linetocrypt[i] = (key[i] + linetocrypt[i]) - 94;			
			else
				linetocrypt[i] = key[i] + linetocrypt[i];
		}

		//Creating the array that contain the line and the key
		for(int i = 0; i < (strlen(linetocrypt)*2) - 2; i++)
		{
			if(i % 2 == 0)
			{
				cryptedline[i] = linetocrypt[cryptcount];
				cryptcount++;
			}
			else
			{
				cryptedline[i] = key[keycount];
				keycount++;
			}
		}
		//Writing the crypted line in the file
		fprintf(tempFILE, "%s\n", cryptedline);

		//Resetting the counts and the arrays for next line
		cryptcount = 0;
		keycount = 0;
		emptyarray(key);
		emptyarray(linetocrypt);
		emptyarray(cryptedline);
	}
	//Close and rename the files
	fclose(tempFILE);
	fclose(*FileToEncrypt);
	renameFILE(renamechoice);
}

void decryption(int nblines, FILE **FileToDecrypt, int renamechoice)
{
	int decryptcount = 0, keycount = 0;
	char key[27] = {0}, decryptedline[27] = {0}, linetodecrypt[57] = {0};

	FILE *tempFILE = fopen("UserData/temp.txt", "a");

	for(int i = 0; i < nblines; i++)
	{
		//Get the line
		fgets(linetodecrypt, 57, *FileToDecrypt);

		//Put the key and the line in the correct array
		for(int i = 0; i < strlen(linetodecrypt) - 1; i++)
		{
			if(i % 2 == 0)
			{
				decryptedline[decryptcount] = linetodecrypt[i];
				decryptcount++;
			}
			else
			{
				key[keycount] = linetodecrypt[i];
				keycount++;
			}
		}

		//Decryption of the line
		for(int i = 0; i < strlen(decryptedline); i++)
		{
			if(decryptedline[i] - key[i] < -61)
				decryptedline[i] = decryptedline[i] - key[i] + 188;
			else if(decryptedline[i] - key[i] < 33)
				decryptedline[i] = decryptedline[i] - key[i] + 94;
			else
				decryptedline[i] = decryptedline[i] - key[i];
		}

		//Writing the line in the file
		fprintf(tempFILE, "%s\n", decryptedline);

		//Reseting the counts and empty the arrays for the next line
		decryptcount = 0;
		keycount = 0;
		emptyarray(key);
		emptyarray(decryptedline);
		emptyarray(linetodecrypt);
	}	
	//Close and rename the files
	fclose(tempFILE);
	fclose(*FileToDecrypt);
	renameFILE(renamechoice);
}

void encryptline(char cryptedline[])
{
	int cryptcount = 0, keycount = 0;
	char key[30] = {0}, linetocrypt[30] = {0};
	srand(time(NULL));
	
	for(int i = 0; i != 26; i++)
	{
		linetocrypt[i] = cryptedline[i];
	}

	//Encryption algorythm
	for(int i = 0; i != strlen(linetocrypt) - 1; i++)
	{
		key[i] = (rand() % (126 - 33 + 1)) + 33;

		//Encryption of the line 
		if(key[i] + linetocrypt[i] > 220)
			linetocrypt[i] = (key[i] + linetocrypt[i]) - 188;
		else if(key[i] + linetocrypt[i] > 126)
			linetocrypt[i] = (key[i] + linetocrypt[i]) - 94;			
		else
			linetocrypt[i] = key[i] + linetocrypt[i];
	}

	for(int i = 0; i < (strlen(linetocrypt)*2) - 2; i++)
	{
		if(i % 2 == 0)
		{
			cryptedline[i] = linetocrypt[cryptcount];
			cryptcount++;
		}
		else
		{
			cryptedline[i] = key[keycount];
			keycount++;
		}
	}
}

