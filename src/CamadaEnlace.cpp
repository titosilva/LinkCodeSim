#include "CamadaEnlace.hpp"

#include <vector>
#include <iostream>

using namespace std;

vector<int> CamadaEnlaceDadosTransmissoraEnquadramento(vector<int> quadro, ENQUADRAMENTOS enquadramento) {
    vector<int> quadroEnquadrado;

    switch (enquadramento) {
        case ContagemDeCaracteres:
            quadroEnquadrado = CamadaEnlaceDadosTransmissoraEnquadramentoContagemDeCaracteres(quadro);
            break;
        case InsercaoDeBytes:
            quadroEnquadrado = CamadaEnlaceDadosTransmissoraEnquadramentoInsercaoDeBytes(quadro);
            break;
        default:
            throw new invalid_argument("Tipo de enquadramento desconhecido");
    }

    return quadroEnquadrado;
}

vector<int> CamadaEnlaceDadosTransmissoraEnquadramentoContagemDeCaracteres(vector<int> quadro) {
    return quadro;
}

vector<int> CamadaEnlaceDadosTransmissoraEnquadramentoInsercaoDeBytes(vector<int> quadro) {
    return quadro;
}

vector<int> CamadaEnlaceDadosReceptoraEnquadramento(vector<int> quadro, ENQUADRAMENTOS enquadramento) {
    vector<int> quadroDesenquadrado;
    
    switch (enquadramento) {
        case ContagemDeCaracteres:
            quadroDesenquadrado = CamadaEnlaceDadosReceptoraEnquadramentoContagemDeCaracteres(quadro);
            break;
        case InsercaoDeBytes:
            quadroDesenquadrado = CamadaEnlaceDadosReceptoraEnquadramentoInsercaoDeBytes(quadro);
            break;
        default:
            throw new invalid_argument("Tipo de enquadramento desconhecido");
    }

    return quadroDesenquadrado;
}

vector<int> CamadaEnlaceDadosReceptoraEnquadramentoContagemDeCaracteres(vector<int> quadro) {
    return quadro;
}

vector<int> CamadaEnlaceDadosReceptoraEnquadramentoInsercaoDeBytes(vector<int> quadro) {
    return quadro;
}