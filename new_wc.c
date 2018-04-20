#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//new_wc.c
//This is a function that takes up to 3 arguements
//It can read from a file or standard input based on whether a file is passed in
//if -l is passed in, it will print line count
//if -c is passed in it will characters
//only one flag can be passed in


void strAppend(char c, char **string)
{
	size_t len = strlen(*string);
	char *str2 = malloc(len + 1 + 1);
	strcpy(str2, *string);
	str2[len] = c;
	string[len+1] = '\0';
	*string = malloc(len + 1 + 1);
	strcpy(*string, str2);

}



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
			file = i; //This is the position makrer for file in argv
		}
	}

	if (file == 0)//condition for no file, get from stdin
	{
		char *str = "";
		char c2;
		//Loop that gets user input until ctrl d is pressed
		while(c2 != EOF)
		{
			c2 = getchar();
			if (c2 != EOF)
			{
				strAppend(c2, &str);//constantly appends new char to string
			}
		}

		size_t len = strlen(str);
		int j = 0;
		//loops through string to find words/chars/lines
		for (j = 0; j < len; j++)
		{
			chars++;
			if (str[j] == ' ')
			{
				words++;
			}
			if (str[j] == '\n')
			{
				lines++;
				words++;
			}
		
		}
	

		if (chars != 0 ) //if there are characters but no spaces there is still one word
		{
			words++;
		}
		if (lines == 0 && words != 0)//if there are words but no newline there is still one line
		{
			lines++;
		}

		//selects appropriate response based on flag input
		if (l == 1)
		{
			printf("\n%d %d\n", lines, words);
		}
		else if (c == 1)
			printf("\n%d %d\n", words, chars);
		else
			printf("\n%d\n", words);


		fflush(stdout);
		fflush(stdin);
		return 0;
	}
	else //condition for file was passed in
	{
	
		FILE *rf;
		char ch;
		//opens file and makes sure it exists
		rf = fopen(argv[file], "r");
		if (rf == NULL)
		{
			printf("Error. File does not exist");
			return 0;
		}
		//Loops through file tracking words, lines and chars
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
				words++;
			}
			ch = fgetc(rf);
		}
		if (chars != 0)//if there are characters but no space there is still a word
		{
			words++;
		}
		if (lines == 0 && words != 0)//if there are words but no newline there is still a line
		{
			lines++;
		}

		//Selects appropriate response based on flags in argv
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
