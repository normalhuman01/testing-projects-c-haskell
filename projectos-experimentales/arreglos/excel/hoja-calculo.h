

#include <vector>
#include <string> // Agrega esta línea para incluir <string>

class Celda; // Forward declaration

class HojaCalculo {
    private:
        std::vector<std::vector<Celda>> filas;

    public:
        HojaCalculo();
        void agregarFila();
        void agregarColumna();
        std::string verValor(int fila, int columna) const;
        void asignarValor(int fila, int columna, const std::string& valor);
        void mostrarHoja() const;
        void asignarValorSuma(int fila, int columna, int fila1, int col1, int fila2, int col2);
        void asignarValorResta(int fila, int columna, int fila1, int col1, int fila2, int col2);
        // Otros métodos según sea necesario
};

