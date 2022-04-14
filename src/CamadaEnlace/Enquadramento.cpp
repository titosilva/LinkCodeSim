#include "Enquadramento.hpp"

#include <vector>
using namespace std;

// Instanciação
Enquadrador* Enquadrador::Criar(ENQUADRAMENTOS enquadramento) {
    switch (enquadramento) {
        case ContagemDeCaracteres:
            return new EnquadradorContagemDeCaracteres();
        case InsercaoDeBytes:
            return new EnquadradorInsercaoDeBytes();
        default:
            throw new exception();
    }
}

// Contagem de caracteres
vector<int> EnquadradorContagemDeCaracteres::Enquadrar(vector<int> quadro) {
    return quadro;
}

vector<int> EnquadradorContagemDeCaracteres::Desenquadrar(vector<int> quadro) {
    return quadro;
}

// Inserção de bytes
vector<int> EnquadradorInsercaoDeBytes::Enquadrar(vector<int> quadro) {
    return quadro;
}

vector<int> EnquadradorInsercaoDeBytes::Desenquadrar(vector<int> quadro) {
    return quadro;
}
