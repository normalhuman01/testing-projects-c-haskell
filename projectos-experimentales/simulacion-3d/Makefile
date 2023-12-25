all: build

build:
	@echo "Compilando..."
	g++ -c .\src\clases.cpp -o .\bin\clases.o
	g++ -c .\src\funciones.cpp -o .\bin\funciones.o
	g++ -Wall -I./include -L./lib .\bin\clases.o .\bin\funciones.o .\src\main.cpp -o .\bin\main -lraylib -lopengl32 -lgdi32 -lwinmm

	@echo "Ejecutando..."
	.\bin\main.exe

clean:
	@echo "Limpiando..."
	rm .\bin\clases.o
	rm .\bin\funciones.o
	rm .\bin\main.exe