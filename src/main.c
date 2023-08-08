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

	//Check if it's the first launch on the computer
	firstinit = initcheck();

	//If not first init, decrypt masterpass file to read it
	if(!firstinit)
	{
		nblines = countline();
	
		masterFILE = fopen("UserData/masterpass.txt", "r");

		decryption(nblines, &masterFILE);
		renameFILE(3);
	}

	masterpass(firstinit);

	//If not the first launch : decrypt all files
	if(!firstinit)
	{
		descFILE = fopen("UserData/desc.txt", "r");
		passFILE = fopen("UserData/pass.txt", "r");

		decryption(nblines, &passFILE);
		renameFILE(1);
		decryption(nblines, &descFILE);
		renameFILE(2);
	}

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

	encryption(nblines, &passFILE);
	renameFILE(1);	
	encryption(nblines, &descFILE);
	renameFILE(2);
	encryption(nblines, &masterFILE);
	renameFILE(3);
}
