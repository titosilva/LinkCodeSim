#include "Utilitario.hpp"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void Imprime(string texto) {
    cout << texto << endl;
}

void Imprime(int numero) {
    cout << numero << endl;
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

vector<vector<int>> DivideVetor(int tamanhoDaParte, vector<int> original) {
    vector<vector<int>> resultado;
    vector<int> subvetorDoResultado;

    for (auto i = 0; i < original.size(); i++) {
        if (subvetorDoResultado.size() == tamanhoDaParte) {
            resultado.push_back(Copia(subvetorDoResultado));
            subvetorDoResultado.clear();
        }

        subvetorDoResultado.push_back(original[i]);
    }

    // Copia os últimos elementos, mesmo que não sejam uma parte inteira
    resultado.push_back(Copia(subvetorDoResultado));

    return resultado;
}

vector<int> Colapsar(vector<vector<int>> subvetores) {
    vector<int> resultado;

    for (auto subvetorRef = subvetores.begin(); subvetorRef < subvetores.end(); subvetorRef++) {
        auto subvetor = *subvetorRef;
        for (auto itemRef = subvetor.begin(); itemRef < subvetor.end(); itemRef++) {
            resultado.push_back(*itemRef);
        }
    }

    return resultado;
}

vector<int> Copia(vector<int> original) {
    return *(new vector<int>(original));
}