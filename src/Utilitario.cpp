#include "Utilitario.hpp"

#include <vector>
#include <iostream>

using namespace std;

// Função utilizada para imprimir os vector<int> no momento em que é chamado
void Imprime(vector<int> fluxoBrutoDeBitsPontoB) {
    for (int i = 0; i < fluxoBrutoDeBitsPontoB.size(); i++) {
        cout << fluxoBrutoDeBitsPontoB[i];
    }
    cout << endl;
}
