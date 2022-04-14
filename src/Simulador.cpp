#include "Simulador.hpp"

#include <iostream>
#include <iterator>
#include <limits>
#include <string>
#include <vector>

#include "Camadas.hpp"

using namespace std;

void MeioDeComunicacao(vector<int> quadro, Maquina* maquinaReceptora) {
    vector<int> fluxoBrutoDeBitsPontoA = quadro, fluxoBrutoDeBitsPontoB;

    int i = 0;
    while (fluxoBrutoDeBitsPontoA.size() > fluxoBrutoDeBitsPontoB.size()) {
        fluxoBrutoDeBitsPontoB.push_back(fluxoBrutoDeBitsPontoA[i]);
        i++;
    }

    maquinaReceptora->ReceberDados(fluxoBrutoDeBitsPontoB);
}
