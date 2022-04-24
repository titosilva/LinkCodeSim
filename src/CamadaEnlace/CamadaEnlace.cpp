#include "CamadaEnlace.hpp"

#include <vector>

#include "../Camadas.hpp"
#include "../Utilitario.hpp"

using namespace std;

void CamadaEnlace::ReceberDados(vector<int> quadro) {
    auto quadroRecuperado = this->controladorDeErro->Recuperar(quadro);

    Imprime("Camada de enlace - quadro recebido após ser recuperado pelo controle de erro:");
    Imprime(quadroRecuperado);
    NovaLinha();

    quadroRecuperado = this->enquadrador->Desenquadrar(quadroRecuperado);

    Imprime("Camada de enlace - quadro recebido após ser desenquadrado:");
    Imprime(quadroRecuperado);
    NovaLinha();

    this->camadaSuperior->ReceberDados(quadroRecuperado);
}

void CamadaEnlace::TransmitirDados(vector<int> quadro) {
    auto quadroEnquadrado = this->enquadrador->Enquadrar(quadro);

    Imprime("Camada de enlace - quadro a ser transmitido após ser enquadrado:");
    Imprime(quadroEnquadrado);
    NovaLinha();

    auto quadroPreparado = this->controladorDeErro->Preparar(quadroEnquadrado);

    Imprime("Camada de enlace - quadro a ser transmitido após ser preparado pelo controle de erro:");
    Imprime(quadroPreparado);
    NovaLinha();

    this->camadaInferior->TransmitirDados(quadroPreparado);
}