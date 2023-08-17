#ifndef INTERACTIONS_H
#define INTERACTIONS_H

int choice();														//Return the choice of the user
void displaydata(int nblines, FILE **descFILE, FILE **passFILE);	//Display every password and his description
void newpass(FILE **descFILE, FILE **passFILE);						//Create a new password
void deletepass(int nblines, FILE **descFILE, FILE **passFILE);		//Delete a password and his description
void randompass(FILE **descFILE, FILE **passFILE); 					//Generate a random secured password

#endif
