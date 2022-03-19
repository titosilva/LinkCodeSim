#include "Simulador.hpp"
#include "CamadaFisica.hpp"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void AplicacaoTransmissora(void) {
    string mensagem;
    cout << "Digite uma mensagem:" << endl;
    cin >> mensagem;

    CamadaDeAplicacaoTransmissora(mensagem);
}

void CamadaDeAplicacaoTransmissora(string mensagem) {
    vector<int> quadro;

    CamadaFisicaTransmissora(quadro);
}

void CamadaFisicaTransmissora(vector<int> quadro) {
    CODIFICACOES tipoDeCodificacao = Binaria;
    vector<int> fluxoBrutoDeBits;

    switch (tipoDeCodificacao) {
        case Binaria:
            fluxoBrutoDeBits = CamadaFisicaTransmissoraCodificacaoBinaria(quadro);
            break;
        case Bipolar:
            fluxoBrutoDeBits = CamadaFisicaTransmissoraCodificacaoBipolar(quadro);
            break;
        case Manchester:
            fluxoBrutoDeBits = CamadaFisicaTransmissoraCodificacaoManchester(quadro);
            break;
        default:
            throw new invalid_argument("Tipo de codificação desconhecido");
            break;
    }

    MeioDeComunicacao(fluxoBrutoDeBits);
}

void MeioDeComunicacao(vector<int> quadro) {
    vector<int> fluxoBrutoDeBitsPontoA = quadro, fluxoBrutoDeBitsPontoB;

    int i = 0;
    while (fluxoBrutoDeBitsPontoA.size() > fluxoBrutoDeBitsPontoB.size()) {
        fluxoBrutoDeBitsPontoB.push_back(fluxoBrutoDeBitsPontoA[i]);
        i++;
    }

    CamadaFisicaReceptora(fluxoBrutoDeBitsPontoB);
}

void CamadaFisicaReceptora(vector<int> quadro) {
    CODIFICACOES tipoDeCodificacao = Binaria;
    vector<int> fluxoBrutoDeBits;

    switch (tipoDeCodificacao) {
        case Binaria:
            fluxoBrutoDeBits = CamadaFisicaReceptoraCodificacaoBinaria(quadro);
            break;
        case Bipolar:
            fluxoBrutoDeBits = CamadaFisicaReceptoraCodificacaoBipolar(quadro);
            break;
        case Manchester:
            fluxoBrutoDeBits = CamadaFisicaReceptoraCodificacaoManchester(quadro);
            break;
        default:
            throw new invalid_argument("Tipo de codificação desconhecido");
            break;
    }

    CamadaDeAplicacaoReceptora(fluxoBrutoDeBits);
}

void CamadaDeAplicacaoReceptora(vector<int> quadro) {
    string mensagem = "";
    AplicacaoReceptora(mensagem);
}

void AplicacaoReceptora(string mensagem) {
    cout << "A mensagem recebida foi:" << mensagem << endl;
}