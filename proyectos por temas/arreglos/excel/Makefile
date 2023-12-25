all: build
build:
	g++ -c Celda.cpp
	g++ -c HojaCalculo.cpp
	g++ Celda.o HojaCalculo.o main.cpp -o main
	main.exe

clean:
	-rm -rf *.o
	-rm -rf *.exe