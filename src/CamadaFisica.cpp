#include "CamadaFisica.hpp"

#include <iterator>
#include <iostream>
#include <vector>

using namespace std;

vector<int> CamadaFisicaTransmissoraCodificacaoBinaria(vector<int> quadro) {
    return quadro;
}

vector<int> CamadaFisicaTransmissoraCodificacaoBipolar(vector<int> quadro) {
    vector<int> result;
    vector<int>::iterator iter = quadro.begin();

    while (iter < quadro.end()) {
        result.insert(result.begin(), *iter > 0? 1 : -1);
        iter++;
    }

    return result;
}

vector<int> CamadaFisicaTransmissoraCodificacaoManchester(vector<int> quadro) {
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

vector<int> CamadaFisicaReceptoraCodificacaoBinaria(vector<int> quadro) {
    return quadro;
}

vector<int> CamadaFisicaReceptoraCodificacaoBipolar(vector<int> quadro) {
    vector<int> result;
    vector<int>::iterator iter = quadro.begin();

    while (iter < quadro.end()) {
        result.insert(result.begin(), *iter > 0? 1 : 0);
        iter++;
    }

    return result;
}

vector<int> CamadaFisicaReceptoraCodificacaoManchester(vector<int> quadro) {
    vector<int> result;

    // Iterar em pares para ver se temos "rising" ou "falling" edges
    for (auto iter = quadro.begin(); iter < quadro.end(); iter+= 2) {
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