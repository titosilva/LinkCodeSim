#include "CamadaFisica.hpp"

#include <vector>

#include "../Simulador.hpp"
#include "../Camadas.hpp"

using namespace std;

void CamadaFisica::ReceberDados(vector<int> quadro) {
    auto quadroDecodificado = this->codificador->Decodificar(quadro);

    this->camadaSuperior->ReceberDados(quadro);
}

void CamadaFisica::TransmitirDados(vector<int> quadro) {
    auto quadroCodificado = this->codificador->Codificar(quadro);

    MeioDeComunicacao(quadroCodificado, this->maquinaConectada);
}