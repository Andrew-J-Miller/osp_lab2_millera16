#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//new_tail.c
//This will print the last 5 lines of a file or use standard input if no file is specified
//The number of lines printed can be changed with the -n flag


//This is a function to append a character to a string
//This will be used get the user input string
void strAppend(char c, char **string)
{
	size_t len = strlen(*string);
	char *str2 = malloc(len + 1 + 1);
	strcpy(str2, *string);
	str2[len] = c;
	str2[len+1] = '\0';
	*string = malloc(len + 1 + 1);
	strcpy(*string, str2);
}


int main(int argc, char *argv[])
{
	int i = 0;
	int n = 0;
	FILE *rf;
	int file = 1;


	int lines = 5; //Default line number. Will be adjusted if -n flag is found
	if (argc > 4)//Condition for more than 4 string arguements passed in
	{
		printf("Error. Please enter the appropriate number of arguements.\n");
		return 0;

	}
	for (i = 0; i < argc; i++)
	{
		if (strcmp(argv[i], "-n") == 0)//loops through arguements to see if a -n flag was passed in
		{
			n = 1;
			lines = atoi(argv[i+1]);//Gets new line number
			if ( i == 2 && argc == 4)//These are checks to find thew file in the arguiements when the user pases in the -n flag
				rf = fopen(argv[3], "r");
			else if (i == 1 && argc == 4)
				rf = fopen(argv[3], "r");
			else
				file = 0;


		}
	}
	if  (n == 0 && argc > 2)//will be true when there are an appropirate number of parameters, but the parameters are invalid
	{
		printf("Error. Please input only a file with the optional -n flag followed by a line number.\n");
		return 0;
	}
	if (n == 0 && argc == 2)//condition for no -n flag but file input
	{
		rf = fopen(argv[1], "r");
	}
	if (argc == 1 || file == 0) //condition for no file input, get from stdin
	{
		char ch;
		char *str = "";
		int counter = 0;
	
	

		
		//This is the user input
		//It will loop until ctrl d is pressed
		while (ch != EOF)
		{
			ch = getchar();
			if (ch != EOF )
				strAppend(ch, &str);//appends the character to the string			
		}
		
		size_t len = strlen(str);
		size_t len2 = len;

	
		//This loop cycles through the string
		//and finds the correct position to begin ouput so as to print
		//the las N lines
		while (counter < lines && len != 0)
		{
			if (str[len-1] == '\n')
			{
				counter++;
			}
			len--;
		}
		//Begins printing from the location found prior
		while (len < len2)
		{
			printf("%c", str[len]);
			len++;
		}
		printf("\n");	

		return 0;
	}
	else //condition for file input
	{
		int count = 0;
		char c;
		fflush(stdout);
		if (rf == NULL)//Make sure the file opens
		{
			printf("Error. Please Enter a valid filename.\n");
			return 0;
		}

		fseek(rf, 0, SEEK_END);//Start from the end of the file
		if ( fgetc(rf) == '\n')//finds the position to beginning printing
		{
		count++;
		}
		while (count < lines)
		{
			fseek(rf, -2, SEEK_CUR);
			if (fgetc(rf) == '\n')
			{
				count++;
			}
		
		}
		c = fgetc(rf);
		while(c != EOF)//Prints from the position earlies
		{
			printf("%c", c);
			c = fgetc(rf);
		
		}
	}


	fclose(rf);
	return 0;
}
