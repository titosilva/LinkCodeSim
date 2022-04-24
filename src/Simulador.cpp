#include "Simulador.hpp"

#include <iostream>
#include <iterator>
#include <limits>
#include <string>
#include <vector>
#include <random>

#include "Camadas.hpp"

using namespace std;

void MeioDeComunicacao(vector<int> fluxoBrutoDeBits, Maquina* maquinaReceptora) {
    int erro, porcentagemDeErros;
    vector<int> fluxoBrutoDeBitsPontoA = fluxoBrutoDeBits, fluxoBrutoDeBitsPontoB;

    porcentagemDeErros = 1;

    int i = 0;
    while (fluxoBrutoDeBitsPontoA.size() > fluxoBrutoDeBitsPontoB.size()) {
        if ((rand()%100) < porcentagemDeErros) {
            // Dividindo por 12 pois cada byte possui, agora, os 4 bits de controle de erro adicionados
            cout << "Introduzindo erro no bit " << i << " (byte " << i / 12 << ")" << endl;
            // Se estiver na "faixa" de erros, introduz erro
            fluxoBrutoDeBitsPontoB.push_back(fluxoBrutoDeBitsPontoA[i] == 0? fluxoBrutoDeBitsPontoA[i] + 1 : fluxoBrutoDeBitsPontoA[i] - 1);
        } else {
            fluxoBrutoDeBitsPontoB.push_back(fluxoBrutoDeBitsPontoA[i]);
        }
        i++;
    }

    maquinaReceptora->ReceberDados(fluxoBrutoDeBitsPontoB);
}
