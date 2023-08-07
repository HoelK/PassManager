void encryption(int nblines, FILE **keyFILE, FILE **FileToEncrypt) //Encrypt the file entered in parameter
{
	char key[27] = {0};
	char unencrypted[27] = {0};
	char allchar[80] = "!#$%&()*+-./:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[]^_abcdefghijklmnopqrstuvwxyz{|}~";		
	
	FILE *tempFILE = fopen("UserData/temp.txt", "a");

	srand(time(NULL));
	for (int i = 0; i < nblines; i++)
	{
		//Get the line
		fgets(unencrypted, 27, *FileToEncrypt);

		for(int i = 0; i != strlen(unencrypted) - 1; i++)
		{
			//Generate the key
			key[i] = allchar[(rand() % 79 + 1)];
			
			//Encryption of the line 
			if(key[i] + unencrypted[i] > 219)
				unencrypted[i] = (key[i] + unencrypted[i]) - 186;
			else if(key[i] + unencrypted[i] > 126)
				unencrypted[i] = (key[i] + unencrypted[i]) - 93;			
			else
				unencrypted[i] = key[i] + unencrypted[i];
		}
			//Re-writing the file and writing the key
			fprintf(tempFILE, "%s", unencrypted);
			fprintf(*keyFILE, "%s\n", key);
	}
	fclose(tempFILE);
	fclose(*keyFILE);
	fclose(*FileToEncrypt);
}

void decryption(int nblines, FILE **keyFILE, FILE **FileToDecrypt) //Decrypt the file entered in parameter
{
	char key[27] = {0};
	char encrypted[27] = {0};

	FILE *tempFILE = fopen("UserData/temp.txt", "a");

	for(int i = 0; i < nblines; i++)
	{
		//Get the line and the key
		fgets(encrypted, 27, *FileToDecrypt);
		fgets(key, 27, *keyFILE);

		//Décryption of the key
		for(int i = 0; i < strlen(encrypted) - 1; i++)
		{
			if(encrypted[i] - key[i] < -60)
				encrypted[i] = encrypted[i] - key[i] + 186;
			else if(encrypted[i] - key[i] < 33)
				encrypted[i] = encrypted[i] - key[i] + 93;
			else
				encrypted[i] = encrypted[i] - key[i];
		}
		fprintf(tempFILE, "%s", encrypted);
	}	
	fclose(tempFILE);
	fclose(*keyFILE);
	fclose(*FileToDecrypt);
}
