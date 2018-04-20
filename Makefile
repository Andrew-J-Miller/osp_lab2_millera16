all: new_cat new_echo new_tail new_wc

new_cat: new_cat.c
	gcc -o new_cat new_cat.c

new_echo: new_echo.c
	gcc -o new_echo new_echo.c

new_tail: new_tail.c
	gcc -o new_tail new_tail.c

new_wc: new_wc.c
	gcc -o new_wc new_wc.c

clean:
	rm -f new_wc new_tail new_echo new_cat
