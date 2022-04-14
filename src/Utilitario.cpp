#include "Utilitario.hpp"

#include <vector>
#include <iostream>
#include <string>

using namespace std;

void Imprime(string texto) {
    cout << texto << endl;
}

void NovaLinha() {
    cout << endl;
}

// Função utilizada para imprimir os vector<int> no momento em que é chamado
void Imprime(vector<int> fluxoBrutoDeBitsPontoB) {
    for (int i = 0; i < fluxoBrutoDeBitsPontoB.size(); i++) {
        cout << fluxoBrutoDeBitsPontoB[i];
    }
    cout << endl;
}
