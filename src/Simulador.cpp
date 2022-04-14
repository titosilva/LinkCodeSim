#include "Simulador.hpp"

#include <iostream>
#include <iterator>
#include <limits>
#include <string>
#include <vector>

#include "Camadas.hpp"

using namespace std;

Maquina* ConstruirMaquina(CODIFICACOES codificacao, ENQUADRAMENTOS enquadramento) {
    auto aplicacao = new Aplicacao();

    auto camadaAplicacao = new CamadaAplicacao();

    auto enquadrador = Enquadrador::Criar(enquadramento);
    auto camadaEnlace = new CamadaEnlace(enquadrador);

    auto codificador = Codificador::Criar(codificacao);
    auto camadaFisica = new CamadaFisica(codificador);

    aplicacao->ConectarCamadaAplicacao(camadaAplicacao);

    camadaAplicacao->ConectarAplicacao(aplicacao);
    camadaAplicacao->ConectarCamadaEnlace(camadaEnlace);

    camadaEnlace->ConectarCamadaAplicacao(camadaAplicacao);
    camadaEnlace->ConectarCamadaFisica(camadaFisica);

    camadaFisica->ConectarCamadaEnlace(camadaEnlace);

    return new Maquina(aplicacao, camadaAplicacao, camadaEnlace, camadaFisica);
}

void MeioDeComunicacao(vector<int> quadro, Maquina* maquinaReceptora) {
    vector<int> fluxoBrutoDeBitsPontoA = quadro, fluxoBrutoDeBitsPontoB;

    int i = 0;
    while (fluxoBrutoDeBitsPontoA.size() > fluxoBrutoDeBitsPontoB.size()) {
        fluxoBrutoDeBitsPontoB.push_back(fluxoBrutoDeBitsPontoA[i]);
        i++;
    }

    maquinaReceptora->ReceberDados(fluxoBrutoDeBitsPontoB);
}
