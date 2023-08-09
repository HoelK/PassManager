int initcheck() //Try if the files exists, If not, that mean its the first time launching the program
{
	FILE *testpFILE = fopen("UserData/pass.txt", "r");

	if(testpFILE == NULL)
	{
		testpFILE = fopen("UserData/pass.txt", "w+");
		FILE *testdFILE = fopen("UserData/desc.txt", "w+");
		
		fclose(testpFILE);
		fclose(testdFILE);

		return 1;
	}
	else
	{
		fclose(testpFILE);
		return 0;
	}
}

void emptybuffer()
{
	int c = 0;

	while(c != '\n' && c != EOF)
	{
		c = getchar();
	}
}

int countline() //Return the numbers of line in a file
{
	int c = 0, lines = 0;
	FILE *descFILE = fopen("UserData/desc.txt", "r");
	
	while(!feof(descFILE))
	{
		c = fgetc(descFILE);
		if(c == '\n')
			lines++;
	}

	fclose(descFILE);
	return lines;
}

void renameFILE(int filechoice) //Rename a specific file depending of the choice
{
	switch(filechoice)
	{
		case 1:
			remove("UserData/pass.txt");
			rename("UserData/temp.txt", "UserData/pass.txt");
			break;

		case 2:
			remove("UserData/desc.txt");
			rename("UserData/temp.txt", "UserData/desc.txt");
			break;

		case 3: 	
			remove("UserData/masterpass.txt");
			rename("UserData/temp.txt", "UserData/masterpass.txt");
			break;
	}
}
