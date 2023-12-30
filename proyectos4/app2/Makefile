# Compilador C++
CXX = g++
# Opciones de compilación
CXXFLAGS = -std=c++11 -Wall

# Objetivos
TARGET = main
OBJECTS = main.o ListaCola.o Cliente.o

# Regla principal
all: $(TARGET)

# Regla para el programa principal
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regla para los objetos
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Limpieza de archivos generados
clean:
	rm -f $(TARGET) $(OBJECTS)
