#include "passmanip.c"

void masterpass(int firstinit);
void newpass(FILE **descFILE, FILE **passFILE);
void deletepass(int nblines, FILE **descFILE, FILE **passFILE);
void randompass(FILE **descFILE, FILE **passFILE); //Generate a random secured password
