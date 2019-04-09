all: utils.o
	gcc -o main utils.o

utils.o: utils.c
	gcc -c utils.c

test1:
	./main seq0

run:
	./main

clean:
	rm ./*.o
