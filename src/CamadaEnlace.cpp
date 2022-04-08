#include "CamadaEnlace.hpp"

#include <vector>
#include <iostream>

using namespace std;

vector<int> CamadaEnlaceDadosTransmissoraEnquadramento(vector<int> quadro, ENQUADRAMENTOS enquadramento) {
    vector<int> quadroEnquadrado;
    enquadramento = ContagemDeCaracteres;       //muda de acordo com os testes


    switch (enquadramento) {
        case ContagemDeCaracteres:
            cout << "Contagem de Caracteres Transmissora: ";
            quadroEnquadrado = CamadaEnlaceDadosTransmissoraEnquadramentoContagemDeCaracteres(quadro);
            break;
        case InsercaoDeBytes:
            quadroEnquadrado = CamadaEnlaceDadosTransmissoraEnquadramentoInsercaoDeBytes(quadro);
            break;
        default:
            throw new invalid_argument("Tipo de enquadramento desconhecido");
    }
    
    //Imprime o quadro
    for(int i = 0; i< quadroEnquadrado.size(); i++){
        cout << quadroEnquadrado[i];
    }
    cout << endl;
    cout << endl;

    return quadroEnquadrado;
}

vector<int> CamadaEnlaceDadosTransmissoraEnquadramentoContagemDeCaracteres(vector<int> quadro) {
    vector<int> newquadro;
    vector<int> quadro_nbytes;  //refere aos bytes de nbytes

  //Conta quantos bytes tem o quadro
  int nbytes = (quadro.size())/8;

  //pega a quantidade de nbytes transforma em binário de 8 bits
  //ex -> nbytes == 3 -> quadro_nbytes = 00000011;
    quadro_nbytes.push_back((nbytes >> 7) & 0x1);
    quadro_nbytes.push_back((nbytes >> 6) & 0x1);
    quadro_nbytes.push_back((nbytes >> 5) & 0x1);
    quadro_nbytes.push_back((nbytes >> 4) & 0x1);
    quadro_nbytes.push_back((nbytes >> 3) & 0x1);
    quadro_nbytes.push_back((nbytes >> 2) & 0x1);
    quadro_nbytes.push_back((nbytes >> 1) & 0x1);
    quadro_nbytes.push_back((nbytes >> 0) & 0x1);

  //newquadro recebe o vetor de quadro_nbytes
  for(int i = 0; i<8; i++){
    newquadro.push_back(quadro_nbytes[i]);
  }
  
  //o novo quadro terá, (quantidade de bytes, inicio do quadro, fim do quadro)
  newquadro.insert(newquadro.end(), quadro.begin(), quadro.end());
  return newquadro;
}

vector<int> CamadaEnlaceDadosTransmissoraEnquadramentoInsercaoDeBytes(vector<int> quadro) {
    return quadro;
}

/////////////////////   Camadas Receptoras    ////////////////////////////////

vector<int> CamadaEnlaceDadosReceptoraEnquadramento(vector<int> quadro, ENQUADRAMENTOS enquadramento) {
    vector<int> quadroDesenquadrado;
    enquadramento = ContagemDeCaracteres;       //muda de acordo com os testes

    switch (enquadramento) {
        case ContagemDeCaracteres:
             cout << "Contagem de Caracteres Receptora: ";
            quadroDesenquadrado = CamadaEnlaceDadosReceptoraEnquadramentoContagemDeCaracteres(quadro);
            break;
        case InsercaoDeBytes:
            quadroDesenquadrado = CamadaEnlaceDadosReceptoraEnquadramentoInsercaoDeBytes(quadro);
            break;
        default:
            throw new invalid_argument("Tipo de enquadramento desconhecido");
    }
    //Imprime o quadro Desenquadrado
    for(int i = 0; i< quadroDesenquadrado.size(); i++){
        cout << quadroDesenquadrado[i];
    }
    cout << endl;
    cout << endl;
    return quadroDesenquadrado;
}

vector<int> CamadaEnlaceDadosReceptoraEnquadramentoContagemDeCaracteres(vector<int> quadro) {
    vector<int> quadrofinal;
    vector<int> quadrof;
    //Esta etapa precisa remover os 8 primeiros bits referentes ao tamanho de bytes da mensagem
    
    for(int i=(quadro.size()-1); i>7; i--){
        quadrof.push_back(quadro[i]);
    }
    //só pra inverter o vetor
    for(int i=(quadrof.size()-1); i>=0; i--){
        quadrofinal.push_back(quadrof[i]);
    }

    return quadrofinal;
    
}

vector<int> CamadaEnlaceDadosReceptoraEnquadramentoInsercaoDeBytes(vector<int> quadro) {
    return quadro;
}