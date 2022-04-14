#include "CamadaEnlace.hpp"

#include <vector>

#include "../Camadas.hpp"

using namespace std;

void CamadaEnlace::ReceberDados(vector<int> quadro) {
    auto quadroRecuperado = this->enquadrador->Desenquadrar(quadro);

    this->camadaSuperior->ReceberDados(quadroRecuperado);
}

void CamadaEnlace::TransmitirDados(vector<int> quadro) {
    auto quadroEnquadrado = this->enquadrador->Enquadrar(quadro);

    this->camadaInferior->TransmitirDados(quadroEnquadrado);
}