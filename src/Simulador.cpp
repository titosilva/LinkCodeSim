#include "Simulador.hpp"
#include "CamadaFisica.hpp"

#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <limits>

using namespace std;
int tipoDeCodificacao = 0;

void PerguntarTipoDeCodificacao(void) {
    char c = '\0';

    // Pega o tipo de transmissao desejada pelo usuário
    do{

        cout << "---------------------------------" << endl;
        cout << "Qual o tipo de transmissão deseja? " << endl;
        cout << Binaria << " - Codificação Binária" << endl;
        cout << Bipolar << " - Codificação Bipolar" << endl;
        cout << Manchester << " - Codificação Manchester" << endl;
        cout << "---------------------------------" << endl;

        cin >> c;

        cin.clear();
        cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
    } while (c < '1' || c > '3');

    tipoDeCodificacao = c - '0';
    cout << endl;
}

void AplicacaoTransmissora(void) {
    PerguntarTipoDeCodificacao();

    string mensagem;
    cout << "Digite uma mensagem:" << endl;
    cin >> mensagem;
    cout << endl;

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
    vector<int> fluxoBrutoDeBits;

    switch (tipoDeCodificacao) {
        case Binaria:
            fluxoBrutoDeBits = CamadaFisicaTransmissoraCodificacaoBinaria(quadro);
            cout << "Codificação Binaria: ";
            break;
        case Bipolar:
            fluxoBrutoDeBits = CamadaFisicaTransmissoraCodificacaoBipolar(quadro);
            cout << "Codificação Bipolar: ";
            break;
        case Manchester:
            fluxoBrutoDeBits = CamadaFisicaTransmissoraCodificacaoManchester(quadro);
            break;
        default:
            throw new invalid_argument("Tipo de codificação desconhecido");
            break;
    }

    //Chama a função para imprimir o vetor de bits
    Imprime(quadro);
    cout << endl;

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

// Função utilizada para imprimir os dados no momento em que é chamado
void Imprime(vector<int> fluxoBrutoDeBitsPontoB){
  for(int i = 0; i< fluxoBrutoDeBitsPontoB.size(); i++){
    cout << fluxoBrutoDeBitsPontoB[i];
  }
  cout << endl;
}

void CamadaFisicaReceptora(vector<int> fluxoDeBits) {
    vector<int> quadro;

    switch (tipoDeCodificacao) {
        case Binaria:
            quadro = CamadaFisicaReceptoraCodificacaoBinaria(fluxoDeBits);
            cout << "Decodificação Binaria: ";
            break;
        case Bipolar:
            quadro = CamadaFisicaReceptoraCodificacaoBipolar(fluxoDeBits);
            cout << "Decodificação Bipolar: ";
            break;
        case Manchester:
            quadro = CamadaFisicaReceptoraCodificacaoManchester(fluxoDeBits);
            break;
        default:
            throw new invalid_argument("Tipo de codificação desconhecido");
    }

    Imprime(quadro);
    cout << endl;

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
    cout << "A mensagem recebida foi:" << endl << mensagem << endl;
}