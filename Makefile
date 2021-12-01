all: main.o my_mat.o
	gcc -o connections main.o my_mat.o

main.o: main.c my_mat.h
	gcc -c main.c

my_mat.o: my_mat.c my_mat.h
	gcc -c my_mat.c
clean: 	
	rm main.o my_mat.o
