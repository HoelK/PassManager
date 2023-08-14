<<<<<<< HEAD
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "cryption.h"
#include "basesfunc.h"

void encryption(int nblines, FILE **FileToEncrypt, int renamechoice) //Encrypt the file entered in parameter
{
	int cryptcount = 0, keycount = 0;
	char key[30] = {0}, linetocrypt[30] = {0}, cryptedline[60] = {0};
	char allchar[80] = "!#$%&()*+-./:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[]^_abcdefghijklmnopqrstuvwxyz{|}~";		

=======
void encryption(int nblines, FILE **FileToEncrypt) //Encrypt the file entered in parameter
{
	int cryptcount = 0, keycount = 0;
	char key[30] = {0};
	char linetocrypt[30] = {0};
	char cryptedline[60] = {0};
	char allchar[80] = "!#$%&()*+-./:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[]^_abcdefghijklmnopqrstuvwxyz{|}~";		
	
>>>>>>> 3ec982f086271eab10f8fcafa41f0d995ea1e188
	FILE *tempFILE = fopen("UserData/temp.txt", "a");
	srand(time(NULL));

	for (int i = 0; i < nblines; i++)
	{
		//Get the line
		fgets(linetocrypt, 30, *FileToEncrypt);

<<<<<<< HEAD
		//Encryption algorythm
=======
>>>>>>> 3ec982f086271eab10f8fcafa41f0d995ea1e188
		for(int i = 0; i != strlen(linetocrypt) - 1; i++)
		{
			//Generate the key
			key[i] = allchar[(rand() % 79 + 1)];

			//Encryption of the line 
			if(key[i] + linetocrypt[i] > 219)
				linetocrypt[i] = (key[i] + linetocrypt[i]) - 186;
			else if(key[i] + linetocrypt[i] > 126)
				linetocrypt[i] = (key[i] + linetocrypt[i]) - 93;			
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
<<<<<<< HEAD

		//Writing the crypted line in the file
		fprintf(tempFILE, "%s\n", cryptedline);

		//Resetting the counts and the arrays for next line
		cryptcount = 0;
		keycount = 0;
		emptyarray(key);
		emptyarray(linetocrypt);
		emptyarray(cryptedline);
=======
		//Resetting the counts for next line
		cryptcount = 0;
		keycount = 0;

		//Re-writing the file
		fprintf(tempFILE, "%s\n", cryptedline);
>>>>>>> 3ec982f086271eab10f8fcafa41f0d995ea1e188
	}
	//Close and rename the files
	fclose(tempFILE);
	fclose(*FileToEncrypt);
	renameFILE(renamechoice);
}

<<<<<<< HEAD
void decryption(int nblines, FILE **FileToDecrypt, int renamechoice) //Decrypt the file entered in parameter
{
	int decryptcount = 0, keycount = 0;
	char key[30] = {0}, decryptedline[30] = {0}, linetodecrypt[60] = {0};
=======
void decryption(int nblines, FILE **FileToDecrypt) //Decrypt the file entered in parameter
{
	int decryptcount = 0, keycount = 0;
	char key[30] = {0};
	char decryptedline[30] = {0};
	char linetodecrypt[60] = {0};
>>>>>>> 3ec982f086271eab10f8fcafa41f0d995ea1e188

	FILE *tempFILE = fopen("UserData/temp.txt", "a");

	for(int i = 0; i < nblines; i++)
	{
<<<<<<< HEAD
		//Get the line
		fgets(linetodecrypt, 60, *FileToDecrypt);

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
			if(decryptedline[i] - key[i] < -60)
				decryptedline[i] = decryptedline[i] - key[i] + 186;
			else if(decryptedline[i] - key[i] < 33)
				decryptedline[i] = decryptedline[i] - key[i] + 93;
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
=======
		//Get the line and the key
		fgets(linetodecrypt, 60, *FileToDecrypt);

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
			if(decryptedline[i] - key[i] < -60)
				decryptedline[i] = decryptedline[i] - key[i] + 186;
			else if(decryptedline[i] - key[i] < 33)
				decryptedline[i] = decryptedline[i] - key[i] + 93;
			else
				decryptedline[i] = decryptedline[i] - key[i];
		}
		//Resetting the counts for the next line
		decryptcount = 0;
		keycount = 0;

		//Re-wrinting the file
		fprintf(tempFILE, "%s\n", decryptedline);
>>>>>>> 3ec982f086271eab10f8fcafa41f0d995ea1e188
	}	
	//Close and rename the files
	fclose(tempFILE);
	fclose(*FileToDecrypt);
	renameFILE(renamechoice);
}
