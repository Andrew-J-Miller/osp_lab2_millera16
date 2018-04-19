#include<stdio.h>
#include<stdlib.h>
//new_cat.c
//This is a simple cat replacement program that will print the ocntents of a
//text file or input string to stdout



int main(int argc, char  *argv[])
{
	FILE *rfile;
	char c;
	char *line = NULL;
	size_t n = 0;

	if (argc == 1)//condition for no filename passed in
	{//Uses Getline to get stdin input b/c it can be called with no buffer
		ssize_t result = getline(&line, &n, stdin);
		printf(line);//prints output to console
	}
	else if (argc == 2)//condition for one filename passed in
	{
		rfile = fopen(argv[1], "r"); //opens file specified by string
		if (rfile == NULL)//file does not exist, fail gracefully
		{
			printf("Error, specified file does not exist\n");
			return 0;
		}
		else //file does exist, print it to stdout
		{
			c = fgetc(rfile);//Prints text file char by char
			while (c != EOF)
			{
			printf("%c", c);
			c = fgetc(rfile);
			}
		
		}
		fclose(rfile);//closes file
	}
	else //condition for more than one file. Will print failure message
	{
		printf("Error. Only one filename is accepted\n");
	}
	return 0;
}
