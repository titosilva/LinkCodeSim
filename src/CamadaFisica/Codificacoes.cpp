#include "Codificacoes.hpp"

#include <vector>

using namespace std;

// Instanciação
Codificador* Codificador::Criar(CODIFICACOES codificacao) {
    switch (codificacao) {
        case Binaria:
            return new CodificadorBinario();
        case Bipolar:
            return new CodificadorBipolar();
        case Manchester:
            return new CodificadorManchester();
        default:
            throw new exception();
    }
}

// Codificador binário
vector<int> CodificadorBinario::Codificar(vector<int> quadro) {
    return quadro;
}

vector<int> CodificadorBinario::Decodificar(vector<int> quadro) {
    return quadro;
}

// Codificador bipolar
vector<int> CodificadorBipolar::Codificar(vector<int> quadro) {
    vector<int> result;

    // vê se o ultimo 1 armazenado foi positivo ou negativo, -1 == negativo, 1 == positivo
    int lastSignalOf1 = -1;  // Para iniciar com nível alto no sinal

    // Itera os bits e transforma em amostras do sinal
    for (auto iter = quadro.begin(); iter < quadro.end(); iter++) {
        auto bit = *iter;

        if (bit == 0) {
            result.push_back(0);
        } else {
            // Se o bit for 1, inverter a saída que foi dada no bit 1 anterior para a nova saída
            result.push_back(-1 * lastSignalOf1);
            // Salvar o que foi escrito dessa vez
            lastSignalOf1 *= -1;
        }
    }

    return result;
}

vector<int> CodificadorBipolar::Decodificar(vector<int> quadro) {
    vector<int> result;

    // Itera as amostras do sinal
    for (auto iter = quadro.begin(); iter < quadro.end(); iter++) {
        auto signalValue = *iter;

        // O que for 0 representa um bit 0. O restante representa bit 1
        result.push_back(signalValue == 0 ? 0 : 1);
    }

    return result;
}

// Codificador Manchester
vector<int> CodificadorManchester::Codificar(vector<int> quadro) {
    vector<int> result;

    for (auto iter = quadro.begin(); iter < quadro.end(); iter++) {
        auto bit = *iter;

        if (bit == 0) {
            // 0 é representado por um "rising" edge
            result.insert(result.begin(), 1);
            result.insert(result.begin(), 0);
        } else {
            result.insert(result.begin(), 0);
            result.insert(result.begin(), 1);
        }
    }

    return result;
}

vector<int> CodificadorManchester::Decodificar(vector<int> quadro) {
    vector<int> result;

    // Iterar em pares para ver se temos "rising" ou "falling" edges
    for (auto iter = quadro.begin(); iter < quadro.end(); iter += 2) {
        auto bitStart = *iter;

        if (bitStart == 0) {
            // 0 é representado por um "rising" edge
            result.insert(result.begin(), 0);
        } else {
            result.insert(result.begin(), 1);
        }
    }

    return result;
}