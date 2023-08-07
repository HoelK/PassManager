void masterpass(int firstinit) //Ask the password for acces the database
{	
	char masterpass[27] = {0}, masterinput[27] = {0};
	FILE *masterFILE = NULL;

	if(firstinit)
	{
		printf("Create your main password that will secure your database (25 char max) : ");
		fgets(masterpass, 27, stdin);

		masterFILE = fopen("UserData/masterpass.txt", "a+");
		fprintf(masterFILE, "%s", masterpass);
	}
	else
	{
		masterFILE = fopen("UserData/masterpass.txt", "r");
		fgets(masterpass, 27, masterFILE);

		//Password verification loop
		while(strcmp(masterinput, masterpass) != 0) 
		{
			printf("Main password : ");
			fgets(masterinput, 27, stdin);
			masterinput[strlen(masterpass) + 1] = '\0';

			if(strcmp(masterinput, masterpass) != 0)
				printf("Error :Wrong password\n");
		}
	}
	fclose(masterFILE);
}

void newpass(FILE **descFILE, FILE **passFILE) //Add a password
{
	char input[27] = {0};

	//Adding the descrition in the file
	printf("Enter a description site/email... (25 char max) : ");
	fgets(input, 27, stdin);

	*descFILE = fopen("UserData/desc.txt", "a");
	fprintf(*descFILE, "%s", input);
	fclose(*descFILE);

	//Adding the password in the file
	printf("Entrer a password (25 char max): ");
	fgets(input, 27, stdin);

	*passFILE = fopen("UserData/pass.txt", "a");
	fprintf(*passFILE, "%s", input);
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
	char input[27] = {0};
	char passcharlist[84] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789%*/-+=;!?_(){}[]<>#~&@";

	printf("Enter a description site/email... (25 char max) : ");
	fgets(input, 27, stdin);

	//Add the descrition in the file
	*descFILE = fopen("UserData/desc.txt", "a");
	fprintf(*descFILE, "%s", input);
	fclose(*descFILE);

	//Put a random char from the passcharlist into each input case
	for(int i = 0; i != 25; i++)
	{
		input[i] = passcharlist[(rand() % 83 - 0 + 1) + 0];
	}

	input[25] = '\n';

	//Add the pass in the file
	*passFILE = fopen("UserData/pass.txt", "a");
	fprintf(*passFILE, "%s", input);
	fclose(*passFILE);
}
