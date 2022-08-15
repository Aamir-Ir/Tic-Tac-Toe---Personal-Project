TIC: main.o
	gcc -Wall -std=c99 main.o -o TIC

main.o: main.c header.h
	gcc -Wall -std=c99 -c main.c

clean:
	rm *.o TIC
