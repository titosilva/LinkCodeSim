#include "CamadaFisica.hpp"

#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

vector<int> CamadaFisicaTransmissoraCodificacaoBinaria(vector<int> quadro) {
    // a função CamadaDeAplicacaoTransmissora já transforma em Binário
    return quadro;
}

vector<int> CamadaFisicaTransmissoraCodificacaoBipolar(vector<int> quadro) {
    vector<int> result;

    // vê se o ultimo 1 armazenado foi positivo ou negativo, -1 == negativo, 1 == positivo
    int lastSignalOf1 = -1; // Para iniciar com nível alto no sinal

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

vector<int> CamadaFisicaTransmissoraCodificacaoManchester(vector<int> quadro) {
    return quadro;
}

vector<int> CamadaFisicaReceptoraCodificacaoBinaria(vector<int> quadro) {
    // a função CamadaDeAplicacaoReceptora transforma para string
    return quadro;
}

vector<int> CamadaFisicaReceptoraCodificacaoBipolar(vector<int> quadro) {
    vector<int> result;

    // Itera as amostras do sinal
    for (auto iter = quadro.begin(); iter < quadro.end(); iter++) {
        auto signalValue = *iter;

        // O que for 0 representa um bit 0. O restante representa bit 1
        result.push_back(signalValue == 0? 0 : 1);
    }

    return result;
}

vector<int> CamadaFisicaReceptoraCodificacaoManchester(vector<int> quadro) {
    return quadro;
}