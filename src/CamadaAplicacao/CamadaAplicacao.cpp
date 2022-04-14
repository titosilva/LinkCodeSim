#include "CamadaAplicacao.hpp"

#include <vector>
#include <string>

#include "../Camadas.hpp"

using namespace std;

void CamadaAplicacao::TransmitirDados(string mensagem) {
    // Transformar em bits
    vector<int> quadro;

    for (int i = 0; i < mensagem.length(); i++) {
        auto c = mensagem[i];
        quadro.push_back((c >> 7) & 0x1);
        quadro.push_back((c >> 6) & 0x1);
        quadro.push_back((c >> 5) & 0x1);
        quadro.push_back((c >> 4) & 0x1);
        quadro.push_back((c >> 3) & 0x1);
        quadro.push_back((c >> 2) & 0x1);
        quadro.push_back((c >> 1) & 0x1);
        quadro.push_back((c >> 0) & 0x1);
    }

    this->camadaInferior->TransmitirDados(quadro);
}

void CamadaAplicacao::ReceberDados(vector<int> quadro) {
    vector<int>::iterator iter = quadro.begin();
    string mensagem = "";

    auto currentBit = 7;
    char currentChar = 0;
    while (iter != quadro.end()) {
        auto bit = *iter;
        currentChar |= (bit << currentBit);

        if (currentBit == 0) {
            mensagem.push_back(currentChar);
            currentBit = 7;
            currentChar = 0;
        } else {
            currentBit--;
        }

        iter++;
    }

    this->aplicacao->ReceberMensagemEMostrar(mensagem);
}