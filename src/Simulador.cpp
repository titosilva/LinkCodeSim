#include "Simulador.hpp"
#include "CamadaFisica.hpp"

#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;
int tipo_DeCodificacao = 0;

void AplicacaoTransmissora(void) {
    string mensagem;
    cout << "Digite uma mensagem:" << endl;
    cin >> mensagem;

   //pega o tipo de transmissao desejada pelo usuário
    while(tipo_DeCodificacao < 1 || tipo_DeCodificacao > 3){
        cout << "---------------------------------" << endl;
        cout << "Qual o tipo de transmissão deseja? " << endl;
        cout << "1 - Codificação Binária" << endl;
        cout << "2 - Codificação Bipolar" << endl;
        cout << "3 - Codificação Manchester" << endl;
        cout << "---------------------------------" << endl;
        cin >> tipo_DeCodificacao;
    }
    // Chama a próxima camada
    CamadaDeAplicacaoTransmissora(mensagem);
}

void CamadaDeAplicacaoTransmissora(string mensagem) {
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

    // Chama a próxima camada
    CamadaFisicaTransmissora(quadro);
}

void CamadaFisicaTransmissora(vector<int> quadro) {
    CODIFICACOES tipoDeCodificacao;
    vector<int> fluxoBrutoDeBits;

    switch (tipo_DeCodificacao) {
        case Binaria:
            fluxoBrutoDeBits = CamadaFisicaTransmissoraCodificacaoBinaria(quadro);
            cout << "Codificação Binaria: ";
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

    //Chama a função para imprimir o vetor de bits
    Imprimir(fluxoBrutoDeBitsPontoB);

    // Chama a próxima camada
    CamadaFisicaReceptora(fluxoBrutoDeBitsPontoB);
}

// Função utilizada para imprimir os dados no momento em que é chamado
void Imprimir(vector<int> fluxoBrutoDeBitsPontoB){
  for(int i = 0; i< fluxoBrutoDeBitsPontoB.size(); i++){
    cout << fluxoBrutoDeBitsPontoB[i];
  }
  cout << endl;
}

void CamadaFisicaReceptora(vector<int> fluxoDeBits) {
    CODIFICACOES tipoDeCodificacao;
    vector<int> quadro;

    switch (tipo_DeCodificacao) {
        case Binaria:
            quadro = CamadaFisicaReceptoraCodificacaoBinaria(fluxoDeBits);
            cout << "Decodificação Binaria: ";
            Imprimir(quadro);
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

    // Chama a próxima camada
    AplicacaoReceptora(mensagem);
}

void AplicacaoReceptora(string mensagem) {
    cout << "A mensagem recebida foi:" << mensagem << endl;
}