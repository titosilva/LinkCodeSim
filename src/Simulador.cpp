#include "Simulador.hpp"
#include "CamadaFisica.hpp"

#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

void AplicacaoTransmissora(void) {
    string mensagem;
    cout << "Digite uma mensagem:" << endl;
    cin >> mensagem;

    // Chama a próxima camada
    CamadaDeAplicacaoTransmissora(mensagem);
}

void CamadaDeAplicacaoTransmissora(string mensagem) {
    // Transformar em bits
    vector<int> quadro;
    for (int i = 0; i < mensagem.length(); i++) {
        auto c = mensagem[i];
        quadro.push_back((c >> 0) & 0x1);
        quadro.push_back((c >> 1) & 0x1);
        quadro.push_back((c >> 2) & 0x1);
        quadro.push_back((c >> 3) & 0x1);
        quadro.push_back((c >> 4) & 0x1);
        quadro.push_back((c >> 5) & 0x1);
        quadro.push_back((c >> 6) & 0x1);
        quadro.push_back((c >> 7) & 0x1);
    }

    // Chama a próxima camada
    CamadaFisicaTransmissora(quadro);
}

void CamadaFisicaTransmissora(vector<int> quadro) {
    CODIFICACOES tipoDeCodificacao = Bipolar;
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

    // Chama a próxima camada
    MeioDeComunicacao(fluxoBrutoDeBits);
}

void MeioDeComunicacao(vector<int> quadro) {
    vector<int> fluxoBrutoDeBitsPontoA = quadro, fluxoBrutoDeBitsPontoB;

    int i = 0;
    while (fluxoBrutoDeBitsPontoA.size() > fluxoBrutoDeBitsPontoB.size()) {
        fluxoBrutoDeBitsPontoB.push_back(fluxoBrutoDeBitsPontoA[i]);
        i++;
    }

    // Chama a próxima camada
    CamadaFisicaReceptora(fluxoBrutoDeBitsPontoB);
}

void CamadaFisicaReceptora(vector<int> fluxoDeBits) {
    CODIFICACOES tipoDeCodificacao = Bipolar;
    vector<int> quadro;

    switch (tipoDeCodificacao) {
        case Binaria:
            quadro = CamadaFisicaReceptoraCodificacaoBinaria(fluxoDeBits);
            break;
        case Bipolar:
            quadro = CamadaFisicaReceptoraCodificacaoBipolar(fluxoDeBits);
            break;
        case Manchester:
            quadro = CamadaFisicaReceptoraCodificacaoManchester(fluxoDeBits);
            break;
        default:
            throw new invalid_argument("Tipo de codificação desconhecido");
    }

    // Chama a próxima camada
    CamadaDeAplicacaoReceptora(quadro);
}

void CamadaDeAplicacaoReceptora(vector<int> quadro) {
    vector<int>::iterator iter = quadro.begin();
    string mensagem = "";

    auto currentBit = 0;
    char currentChar = 0;
    while (iter != quadro.end()) {
        auto bit = *iter;
        currentChar |= (bit << currentBit);

        if (currentBit == 7) {
            mensagem.push_back(currentChar);
            currentBit = 0;
            currentChar = 0;
        } else {
            currentBit++;
        }

        iter++;
    }

    // Chama a próxima camada
    AplicacaoReceptora(mensagem);
}

void AplicacaoReceptora(string mensagem) {
    cout << "A mensagem recebida foi:" << endl << mensagem << endl;
}