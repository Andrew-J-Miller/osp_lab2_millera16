# osp_lab2_millera16
Repository for lab 2


This repsoitory contains the following C programs:


new_cat.c: new_cat.c is a replacement cat program. If it is given a file input, it will print it to stdout. If it is given no input, it will take input from stdin until the user hits ctrl+D. Then it will print that input to to stdout.



new_echo.c: new_echo.c is a replacement echo program. It takes a potentially limitless amount of strring arguements and prints the to stdout. If no strings are passed in, it outputs a newline.



new_tail.c: new_tail.c is a replacement tail program. It takes an optional file and an optional -n tag followed by a single integer. It will print the last N lines of a file (or stdin if no fil is passed in) where N is 5 if the -n flag is not passed in. The arguement order does not matter.


new_wc.c: new_wc.c is a replacement word count program. It takes an optional file and an optional -l or -c flag. It will specificy the number of words in the file (or stdin if no file is passed in). If the -l flag is passed in, it will also display the number of lines in the order lines words. If the -c flag is passed in it wil display the number of characters in the order words characters.



Compile these programs using > make

