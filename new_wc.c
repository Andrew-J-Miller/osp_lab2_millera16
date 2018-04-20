#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//new_wc.c
//This is a function that takes up to 3 arguements
//It can read from a file or standard input based on whether a file is passed in
//if -l is passed in, it will print line count
//if -c is passed in it will characters
//only one flag can be passed in




int main(int argc, char *argv[])
{
	int c = 0;
	int l = 0;
	int file = 0;
	int i = 0;

	int words = 0;
	int lines = 0;
	int chars = 0;

	if (argc > 4)
	{
		printf("Error, too many arguements\n");
		return 0;

	}
	
	for (i = 0; i < argc; i++) //This loop will check for flags and locate the file if it is passed in
	{
		if (strcmp(argv[i], "-l") == 0)
		{
			l = 1;	
		}
		if (strcmp(argv[i], "-c") == 0)
		{
			c = 1;
		}
		if (strcmp(argv[i], "-c") != 0 && strcmp(argv[i], "-l") != 0 && i != 0)
		{
			file = i;
		}
	}

	if (file == 0)//condition for no file, get from stdin
	{
	
	}
	else //condition for file was passed in
	{
	
		FILE *rf;
		char ch;

		rf = fopen(argv[file], "r");
		if (rf == NULL)
		{
			printf("Error. File does not exist");
			return 0;
		}
		
		ch = fgetc(rf);
		while (ch != EOF)
		{
			chars++;
			if (ch == ' ')
			{
				words++;
			}
			if (ch == '\n')
			{
				lines++;
			}
			ch = fgetc(rf);
		}
		if (chars != 0)
		{
			words++;
		}
		if (lines == 0 && words != 0)
		{
			lines++;
		}
		if (c == 1)
		{
			printf("%d %d\n", words, chars);
		}
		else if (l == 1)
		{
			printf("%d %d\n", lines, words);
		}
		else
		{
			printf("%d\n", words);
		}
	
	
	fclose(rf);
	return 0;
	
	}










	return 0;
}
