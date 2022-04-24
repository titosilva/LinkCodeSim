#include "ControleDeErro.hpp"

#include "../Utilitario.hpp"

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
    auto bytes = DivideVetor(8, quadro);

    for (auto byteRef = bytes.begin(); byteRef < bytes.end(); byteRef++) {
        auto byte = *byteRef;

        // Criar espaços para bits de paridade
        byte.insert(byte.begin(), 0);
        byte.insert(byte.begin() + 1, 0);
        byte.insert(byte.begin() + 3, 0);
        byte.insert(byte.begin() + 7, 0);

        // Calcular bits de paridade
        auto paridadeGrupo1 = this->calcularParidadeParaSubgrupo(0b0001, byte);
        byte[0] = paridadeGrupo1;

        auto paridadeGrupo2 = this->calcularParidadeParaSubgrupo(0b0010, byte);
        byte[1] = paridadeGrupo2;
        
        auto paridadeGrupo4 = this->calcularParidadeParaSubgrupo(0b0100, byte);
        byte[3] = paridadeGrupo4;

        auto paridadeGrupo8 = this->calcularParidadeParaSubgrupo(0b1000, byte);
        byte[7] = paridadeGrupo8;

        *byteRef = byte;
    }

    return Colapsar(bytes);
}

vector<int> ControladorDeErroHamming::Recuperar(vector<int> quadro) {
    auto bytes = DivideVetor(12, quadro);

    for (auto byteRef = bytes.begin(); byteRef < bytes.end(); byteRef++) {
        auto byte = *byteRef;
        auto gruposComErro = this->detectarGruposComErro(&byte);

        // Salvar byte sem os bits de paridade, ainda que haja erros
        *byteRef = byte;
        if (gruposComErro.size() > 0) {
            auto errosRecuperados = this->tentarRecuperarErros(&byte, gruposComErro);

            if (!errosRecuperados) {
                Imprime("Erro inrrecuperável");
                exit(0);
            }
        }

        // Remover bits de paridade
        byte.erase(byte.begin() + 7);
        byte.erase(byte.begin() + 3);
        byte.erase(byte.begin() + 1);
        byte.erase(byte.begin());

        // Salvar byte recuperado
        *byteRef = byte;
    }

    return Colapsar(bytes);
}

vector<int> ControladorDeErroHamming::detectarGruposComErro(vector<int>* byteRef) {
    auto byte = *byteRef;

    auto paridadeRecebidaGrupo1 = byte[0];
    auto paridadeRecebidaGrupo2 = byte[1];
    auto paridadeRecebidaGrupo4 = byte[3];
    auto paridadeRecebidaGrupo8 = byte[7];

    auto paridadeCalculadaGrupo1 = this->calcularParidadeParaSubgrupo(0b0001, byte);
    auto paridadeCalculadaGrupo2 = this->calcularParidadeParaSubgrupo(0b0010, byte);
    auto paridadeCalculadaGrupo4 = this->calcularParidadeParaSubgrupo(0b0100, byte);
    auto paridadeCalculadaGrupo8 = this->calcularParidadeParaSubgrupo(0b1000, byte);

    vector<int> gruposComErro;
    if (paridadeCalculadaGrupo1 != paridadeRecebidaGrupo1) {
        gruposComErro.push_back(1);
    }

    if (paridadeCalculadaGrupo2 != paridadeRecebidaGrupo2) {
        gruposComErro.push_back(2);
    }

    if (paridadeCalculadaGrupo4 != paridadeRecebidaGrupo4) {
        gruposComErro.push_back(4);
    }

    if (paridadeCalculadaGrupo8 != paridadeRecebidaGrupo8) {
        gruposComErro.push_back(8);
    }

    return gruposComErro;
}

bool ControladorDeErroHamming::tentarRecuperarErros(vector<int> *byteRef, vector<int> gruposComErro) {
    // Calcula o bit com erro
    auto localDeErro = 0;
    for (auto grupoRef = gruposComErro.begin(); grupoRef <  gruposComErro.end(); grupoRef++) {
        localDeErro |= *grupoRef;
    }

    cout << "Erro encontrado no bit " << localDeErro << endl;

    auto byte = *byteRef;
    byte[localDeErro] = byte[localDeErro] > 0? 0 : 1;
    *byteRef = byte;

    return true;
}

int ControladorDeErroHamming::calcularParidadeParaSubgrupo(int subgrupo, vector<int> byte) {
    int contagem = 0;

    for (int i = 0; i < 8; i++) {
        // O bit observado faz parte do subgrupo?
        bool contidoNoGrupo = ((i & subgrupo) != 0);
        // Além disso, o bit observado não é um bit de paridade?
        bool bitDeParidade = (i == subgrupo);

        if (contidoNoGrupo && !bitDeParidade) {
            // Se sim, adicionar na contagem
            contagem += byte[i] > 0? 1 : 0;
        }
    }

    return contagem % 2;
}