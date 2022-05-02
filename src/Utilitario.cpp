#include "Utilitario.hpp"

#include <algorithm>
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

vector<int> ObterRestoDaDivisaoBinaria(vector<int> dividendo, vector<int> divisor) {
    vector<int> resultado(dividendo);

    while (true) {
        auto proximo1 = find(resultado.begin(), resultado.end(), 1);

        // No caso da divisão binária entre polinômios, dividimos até que o GRAU do polinômio resto
        // for menor que o grau do polinômio divisor
        if (proximo1 > resultado.end() - divisor.size()) {
            // Retornamos o resto da divisão, que são os últimos bits menores que o divisor
            return Copia(vector<int>(resultado.end() - divisor.size() + 1, resultado.end()));
        }

        // Se o dividendo não for zero, fazemos mais um passo da divisão começando do proximo 0
        for (int idx = 0; idx < divisor.size(); idx++) {
            // Realiza a operação de XOR entre um bit no divisor e um bit no dividendo
            // Salva o resultado no dividendo
            auto pos = proximo1 + idx;

            if (pos > resultado.end()) {
                break;
            }

            auto bitDividendo = *(pos);
            auto bitDivisor = divisor[idx];
            *(pos) = (bitDividendo == bitDivisor) ? 0 : 1;
        }
    }
}

vector<int> IntParaBits(uint32_t valor) {
    vector<int> resultado;

    for (int i = 33; i--; i >= 0) {
        resultado.push_back(((0b1 << i) & valor) != 0 ? 1 : 0);
    }

    return resultado;
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

char BitsParaChar(vector<int> bits) {
    vector<int>::iterator iter = bits.begin();
    string mensagem = "";

    auto currentBit = 7;
    char currentChar = 0;
    while (iter != bits.end()) {
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

    return mensagem[0];
}

vector<int> CharParaBits(char c) {
    vector<int> resultado;
    resultado.push_back((c >> 7) & 0x1);
    resultado.push_back((c >> 6) & 0x1);
    resultado.push_back((c >> 5) & 0x1);
    resultado.push_back((c >> 4) & 0x1);
    resultado.push_back((c >> 3) & 0x1);
    resultado.push_back((c >> 2) & 0x1);
    resultado.push_back((c >> 1) & 0x1);
    resultado.push_back((c >> 0) & 0x1);
    return resultado;
}