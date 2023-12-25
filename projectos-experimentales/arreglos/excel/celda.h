
#include <string>

class Celda {
    private:
        std::string valor;

    public:
        Celda();
        void setValor(const std::string& valor);
        std::string getValor() const;
};

