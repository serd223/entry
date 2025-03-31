CC = clang

example: example.c entry.h
	$(CC) example.c -o example
