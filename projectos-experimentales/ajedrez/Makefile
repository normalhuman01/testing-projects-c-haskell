all: build
build:
	g++ -c PartidaAjedrez.cpp
	g++ -c Pieza.cpp
	g++ PartidaAjedrez.o Pieza.o main.cpp -o main
	main.exe

clean:
	-rm -rf *.o
	-rm -rf *.exe