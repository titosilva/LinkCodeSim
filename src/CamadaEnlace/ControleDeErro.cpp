#include "ControleDeErro.hpp"
#include <stdlib.h>
#include <iostream>

ControladorDeErro* ControladorDeErro::Criar(CONTROLES_DE_ERRO controleDeErro) {
    switch (controleDeErro) {
        case BitParidadePar:
            return new ControladorDeErroBitParidadePar();
        case CRC:
            return new ControladorDeErroCRC();
        case Hamming:
            return new ControladorDeErroHamming();
        default:
            throw new exception();
    }
}

// Bit paridade par
vector<int> ControladorDeErroBitParidadePar::Preparar(vector<int> quadro) {
    vector<int> quadro_final = quadro;
    //precisa acrescentar 0 ou 1 para a quantidade de 1's seja par
    int cont = 0;                         //contador de quantos 1's tem
    
    //conta o número de 1's
    for(int i= 0; i < quadro.size(); i++){
      if (quadro[i] == 1) {
          cont++;
        }
    }
    cont %= 2;
    //se tiver quantidade par de 1's, acrescenta o valor 0
    if(cont == 0){
        quadro_final.push_back(0);
    }
    //se tiver quantidade ímpar de 1's acrescenta o valor 1
    else{
        quadro_final.push_back(1);
    }
    return quadro_final;
}

vector<int> ControladorDeErroBitParidadePar::Recuperar(vector<int> quadro) {
    //bit de paridade
    int ultimoBit = quadro.back();
    //retira o último bit
    quadro.pop_back();
    vector<int> quadro_semUltimoBit = quadro;
    int paridade = 0;                             //0 == par, 1 == impar

    //conta o número de 1's do quadro sem o bit de paridade par
    for(int i= quadro_semUltimoBit.size()-1; i>=0; i--){
        if (quadro_semUltimoBit[i] == 1) {
            paridade++;
        }
    }
    paridade %= 2;

    //Par e último bit zero                   //Ímpar e último bit 1 
    if( ((paridade==0) && ultimoBit == 0) || ((paridade == 1) && ultimoBit == 1) ){      
        return quadro_semUltimoBit;
    }
    
    //Tem que dá erro
    cout << "Erro encontrado ao se checar o Bit de Paridade Par!\nPrograma encerrado.\n";
    exit(0);
}

// CRC
vector<int> ControladorDeErroCRC::Preparar(vector<int> quadro) {
    return quadro;
}

vector<int> ControladorDeErroCRC::Recuperar(vector<int> quadro) {
    return quadro;
}

// Hamming
vector<int> ControladorDeErroHamming::Preparar(vector<int> quadro) {
    return quadro;
}

vector<int> ControladorDeErroHamming::Recuperar(vector<int> quadro) {
    return quadro;
}
