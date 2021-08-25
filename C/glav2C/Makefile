all: prog

prog: main.o func.o
	gcc main.o func.o -o prog

main.o: main.c
	gcc -c main.c

func.o: func.c
	gcc -c func.c

clean:
	rm -rf *.o prog
