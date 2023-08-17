#ifndef BASESFUNC_H
#define BASESFUNC_H

int countline();						//Count how many lines there is in a file
int initcheck();						//Check if the user is launching the program for the 1st time, return a bool
void emptybuffer();						//Empty the buffer
void emptyarray(char arraytoempty[]);	//Empty an array (used in the cryption file)
void renameFILE(int filechoice);		//Rename a file depending of what file you want to rename

#endif
