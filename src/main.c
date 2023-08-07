#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "basesfunc.h"
#include "passmanip.h"
#include "display.h"
#include "cryption.h"

void main()
{
	int firstinit = 0, nblines = 0, usrchoice = 0;
	FILE *passFILE = NULL;
	FILE *descFILE = NULL;
	FILE *masterFILE = NULL;
	FILE *keypassFILE = NULL;
	FILE *keydescFILE = NULL;
	FILE *keymasterFILE = NULL;

	//Check if it's the first launch on the computer
	firstinit = initcheck();

	//If not the first launch : decrypt all files
	if(!firstinit)
	{
		nblines = countline();
	
		descFILE = fopen("UserData/desc.txt", "r");
		passFILE = fopen("UserData/pass.txt", "r");
		masterFILE = fopen("UserData/masterpass.txt", "r");
		keydescFILE = fopen("UserData/keydesc.txt", "r");
		keypassFILE = fopen("UserData/keypass.txt", "r");
		keymasterFILE = fopen("UserData/keymaster.txt", "r");

		decryption(nblines, &keypassFILE, &passFILE);
		renameFILE(1);
		decryption(nblines, &keydescFILE, &descFILE);
		renameFILE(2);
		decryption(nblines, &keymasterFILE, &masterFILE);
		renameFILE(3);

		remove("UserData/keydesc.txt");
		remove("UserData/keypass.txt");
		remove("UserData/keymaster.txt");
	}

	masterpass(firstinit);

	//User Interface
	do
	{
		usrchoice = choice();

		switch(usrchoice)
		{
			case 1:
				displaydata(nblines, &descFILE, &passFILE);
				break;
			case 2:
				newpass(&descFILE, &passFILE);
				break;
			case 3:
				deletepass(nblines, &descFILE, &passFILE);
				break;
			case 4:
				randompass(&descFILE, &passFILE);
				break;
		}
		nblines = countline();

	}while(usrchoice != 0);

	//Encrypt all files before shutdown
	descFILE = fopen("UserData/desc.txt", "r");
	passFILE = fopen("UserData/pass.txt", "r");
	masterFILE = fopen("UserData/masterpass.txt","r");
	keydescFILE = fopen("UserData/keydesc.txt", "a+");
	keypassFILE = fopen("UserData/keypass.txt", "a+");
	keymasterFILE = fopen("UserData/keymaster.txt", "a+");

	encryption(nblines, &keypassFILE, &passFILE);
	renameFILE(1);	
	encryption(nblines, &keydescFILE, &descFILE);
	renameFILE(2);
	encryption(nblines, &keymasterFILE, &masterFILE);
	renameFILE(3);
}
