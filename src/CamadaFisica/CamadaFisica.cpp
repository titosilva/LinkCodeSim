#include "CamadaFisica.hpp"

#include <vector>

#include "../Simulador.hpp"
#include "../Camadas.hpp"
#include "../Utilitario.hpp"

using namespace std;

void CamadaFisica::ReceberDados(vector<int> quadro) {
    auto quadroDecodificado = this->codificador->Decodificar(quadro);

    Imprime("Camada física - quadro recebido e decodificado:");
    Imprime(quadroDecodificado);
    NovaLinha();

    this->camadaSuperior->ReceberDados(quadroDecodificado);
}

void CamadaFisica::TransmitirDados(vector<int> quadro) {
    auto quadroCodificado = this->codificador->Codificar(quadro);

    Imprime("Camada física - quadro a ser transmitido após ser codificado:");
    Imprime(quadroCodificado);
    NovaLinha();

    MeioDeComunicacao(quadroCodificado, this->maquinaConectada);
}