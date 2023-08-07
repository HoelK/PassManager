int choice() //Ask what the user want to do and return the choice
{
	int usrchoice = 0;

	printf("Display your passwords................1\n");
	printf("Add a password........................2\n");
	printf("Delete a password.....................3\n");
	printf("Generate a random secured password....4\n");
	printf("Quit............................... ..0\n");

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
