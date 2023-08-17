#include "basesfunc.h"
#include "cryption.h"
#include "interactions.h"
#include "masterpass.h"

void main()
{
	char masterpass[27] = {0}; 						//Array that will get the masterpass
	int firstinit = 0, nblines = 0, usrchoice = 0;	//firstinit is the result of initcheck
	FILE *passFILE = NULL;
	FILE *descFILE = NULL;
	FILE *masterFILE = NULL;

	firstinit = initcheck(); 	//Get the result of initcheck into a int

	if(!firstinit)				//Create or Ask the masterpass depending of firstinit
	{
		getmasterpass(masterpass);
		askmaster(masterpass);
	}
	else
	{
		createmaster();
		masterFILE = fopen("UserData/masterpass.txt", "r");
		encryption(1, &masterFILE, 3);
	}

	do								//User Interface and Choices
	{
		nblines = countline();		//Get the numbers of line to get any change after an action
		usrchoice = choice();		//Get the choice of the user

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
