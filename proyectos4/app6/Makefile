CC = g++
CFLAGS = -Wall -std=c++11

all: main

main: main.cpp busqueda_patron_kmp.cpp busqueda_patron_kmp_variante.cpp busqueda_patron_boyermoore.cpp
	$(CC) $(CFLAGS) -o main main.cpp busqueda_patron_kmp.cpp busqueda_patron_kmp_variante.cpp busqueda_patron_boyermoore.cpp

clean:
	rm -f main

.PHONY: all clean
