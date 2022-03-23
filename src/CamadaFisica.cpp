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
    return quadro;
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
    return quadro;
}