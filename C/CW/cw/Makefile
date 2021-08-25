all: cwOut

cwOut: main.o text_and_sentences.o anagrammsFunc.o sortingFunc.o vowelFunc.o changingWords.o
	gcc main.o text_and_sentences.o anagrammsFunc.o sortingFunc.o vowelFunc.o changingWords.o -o cwOut

main.o: main.c
	gcc -c main.c

text_and_sentences.o: text_and_sentences.c
	gcc -c text_and_sentences.c

anagrammsFunc.o: anagrammsFunc.c
	gcc -c anagrammsFunc.c

sortingFunc.o: sortingFunc.c
	gcc -c sortingFunc.c

vowelFunc.o: vowelFunc.c
	gcc -c vowelFunc.c

changingWords.o: changingWords.c
	gcc -c changingWords.c

clean:
	rm -rf *.o cwOut
