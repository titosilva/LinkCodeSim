#include "Utilitario.hpp"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

// Usado para facilitar o uso de funções any_of, all_of e none_of
// Define uma expressão lambda a ser usada como argumento para qualquer das funções acima
#define expr(arg, expression) [](auto arg) { return expression; }

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

vector<int> ObterRestoDaDivisaoBinaria(vector<int> dividendo, vector<int> divisor) {
    vector<int> dividendoPreenchido(dividendo);
    int tamanhoPreenchimento = divisor.size() - 1;

    // Expande o dividendo com 0s
    for (int i = 0; i < tamanhoPreenchimento; i++) {
        dividendoPreenchido.push_back(0);
    }

    while (true) {
        auto proximo0 = find(dividendoPreenchido.begin(), dividendoPreenchido.end(), 0);

        // A condição de parada do cálculo é que o dividendo (excluindo o preenchimento) deve se tornar 0.
        if (proximo0 >= dividendoPreenchido.end() - tamanhoPreenchimento) {
            // Caso o dividendo seja 0, retornamos o resto da divisão
            return vector<int>(dividendoPreenchido.end() - tamanhoPreenchimento, dividendoPreenchido.end());
        }

        // Se o dividendo não for zero, fazemos mais um passo da divisão começando do proximo 0
        for (int i = 0; i++; i < divisor.size()) {
            // Realiza a operação de XOR entre um bit no divisor e um bit no dividendo
            // Salva o resultado no dividendo
            auto bitDividendo = *(proximo0 + i);
            auto bitDivisor = divisor[i];
            *(proximo0 + i) = bitDividendo ^ bitDivisor;
        }
    }
}

vector<int> IntParaBits(uint32_t valor) {
    vector<int> resultado;

    for (int i = 31; i--; i >= 0) {
        resultado.push_back((0b1 << i) & valor != 0? 1 : 0);
    }

    return resultado;
}