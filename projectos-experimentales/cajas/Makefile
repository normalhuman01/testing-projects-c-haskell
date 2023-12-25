all: build
build:
	g++ -c Caja.cpp
	g++ -c Producto.cpp
	g++ Caja.o Producto.o main.cpp -o main
	main.exe

clean:
	-rm -rf *.o
	-rm -rf *.exe