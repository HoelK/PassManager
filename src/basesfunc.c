#include <stdio.h>
#include <stddef.h>
#include <string.h>

#include "basesfunc.h"

int countline()
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

int initcheck()
{
	FILE *firsttestFILE = fopen("UserData/pass.txt", "r");

	if(firsttestFILE == NULL)
	{
		firsttestFILE = fopen("UserData/pass.txt", "w+");
		FILE *secondtestFILE = fopen("UserData/desc.txt", "w+");
		
		fclose(firsttestFILE);
		fclose(secondtestFILE);

		return 1;
	}
	else
	{
		fclose(firsttestFILE);
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

void emptyarray(char arraytoempty[])
{
	for(int i = strlen(arraytoempty); i > 0; i--)
	{
		arraytoempty[i] = '\0';
	}
}

void renameFILE(int filechoice)
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
