#include<stdio.h>
//new_echo.c
//This is a program that takes multiple string arguements and prints them in
//stdout
//If there are no string arguements passed in, it simply prints a 
//newline character






int main (int argc, char *argv[])
{
	int i = 1;
	if (argc == 1)//condition for now string arguements
	{
		printf("\n");//only prints a newline character
		return 0;
	}
	for (i = 1; i < argc; i++)//loops through all arguements passed in
	{
		printf(argv[i]); //prints current string arguement
		printf(" "); //prints a space between every word
	
	}
	printf("\n"); //prints newline after the echo is done	
	return 0;
}
