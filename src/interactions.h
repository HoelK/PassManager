#ifndef INTERACTIONS_H
#define INTERACTIONS_H

int choice();
void displaydata(int nblines, FILE **descFILE, FILE **passFILE);
void newpass(FILE **descFILE, FILE **passFILE);
void deletepass(int nblines, FILE **descFILE, FILE **passFILE);
void randompass(FILE **descFILE, FILE **passFILE); //Generate a random secured password

#endif
