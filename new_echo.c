#include<stdio.h>
//new_echo.c
//This is a program that takes multiple string arguements and prints them in
//stdout
//If there are no string arguements passed in, it simply prints a 
//newline character






int main (int argc, char *argv[])
{
	int i = 0;
	for (i = 0; i < argc; i++)//loops through all arguements passed in
	{
		printf("\n"); //prints a newline every loop
		printf(argv[i]);
	
	}
	
	return 0;
}
