#include<stdio.h>
#include<stdlib.h>

//new_tail.c
//This will print the last 5 lines of a file or use standard input if no file is specified
//The number of lines printed can be changed with the -n flag






int main(int argc, char *argv[])
{
	int i = 0;
	bool n = 0;

	char path[100];

	int lines = 5; //Default line number. Will be adjusted if -n flag is found
	if (argc > 4)//Condition for more than 3 string arguements passed in
	{
		printf("Error, too many arguements passed in\n");
		return 0;

	}
	for (i = 0; i < argc; i++)
	{
		if (argv[i] == "-n")//loops through arguements to see if a -n flag was passed in
			n = 1;
	}
	if  (n == 1)//will be true when the -n flag is found, searches for the line number 
	{
		lines = atoi(argv[i+1]); //Gets new line number
	}
	


	return 0;
}
