#include "basesfunc.h"
#include "cryption.h"
#include "interactions.h"
#include "masterpass.h"

void main()
{
	int firstinit = 0, nblines = 0, usrchoice = 0;
	FILE *passFILE = NULL;
	FILE *descFILE = NULL;
	FILE *masterFILE = NULL;

	//Check if it's the first launch on the computer
	firstinit = initcheck();

	//Create or Ask for the main password
	if(!firstinit)
	{
		//Getting and asking the main password
		char masterpass[27] = {0};
		getmasterpass(masterpass);	
		askmaster(masterpass);
	}
	else
	{
		createmaster();
		masterFILE = fopen("UserData/masterpass.txt", "r");
		encryption(1, &masterFILE, 3);
	}

	//User Interface and Choices
	do
	{
		nblines = countline();
		usrchoice = choice();

		switch(usrchoice)
		{
			case 1:
				passFILE = fopen("UserData/pass.txt", "r");
				descFILE = fopen("UserData/desc.txt", "r");
				
				decryption(nblines, &passFILE, 1);
				decryption(nblines, &descFILE, 2);
				
				displaydata(nblines, &descFILE, &passFILE);

				passFILE = fopen("UserData/pass.txt", "r");
				descFILE = fopen("UserData/desc.txt", "r");
				
				encryption(nblines, &passFILE, 1);
				encryption(nblines, &descFILE, 2);

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

	}while(usrchoice != 0);
}
