#include "CamadaFisica.hpp"

#include <iterator>
#include <iostream>
#include <vector>

using namespace std;

vector<int> CamadaFisicaTransmissoraCodificacaoBinaria(vector<int> quadro) {
    //a função CamadaDeAplicacaoTransmissora já transforma em Binário
    return quadro;
}

vector<int> CamadaFisicaTransmissoraCodificacaoBipolar(vector<int> quadro) {
    vector<int> result;
    vector<int>::iterator iter = quadro.begin();
/*
    while (iter < quadro.end()) {
        result.insert(result.begin(), *iter > 0? 1 : -1);
        iter++;
    }

    return result;
    */
    // vê se o ultimo 1 armazenado foi positivo ou negativo, 0 == negativo, 1 == positivo
    int anterior = 0;
    while (iter < quadro.end()) {
        if(*iter == 0){
            result.push_back(0);
        }
        else if(*iter == 1 && anterior == 0){
            result.push_back(1);
            anterior = 1;  
        }
        else{
            result.push_back(-1);
            anterior = 0;
        }
        iter++;
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
    vector<int>::iterator iter = quadro.begin();

    /*
    while (iter < quadro.end()) {
        result.insert(result.begin(), *iter > 0? 1 : 0);
        iter++;
    }

    return result;
    */

   //O que for 0 permanece 0, o restante vira 1
   while (iter < quadro.end()) {
        if(*iter == 0){
            result.push_back(0);
        }
        else{
            result.push_back(1);
        }
        iter++;
    }
    return result;
}

vector<int> CamadaFisicaReceptoraCodificacaoManchester(vector<int> quadro) {
    return quadro;
}