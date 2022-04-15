#include "Enquadramento.hpp"

#include <vector>
using namespace std;

// Instanciação
Enquadrador* Enquadrador::Criar(ENQUADRAMENTOS enquadramento) {
    switch (enquadramento) {
        case ContagemDeCaracteres:
            return new EnquadradorContagemDeCaracteres();
        case InsercaoDeBytes:
            return new EnquadradorInsercaoDeBytes();
        default:
            throw new exception();
    }
}

// Contagem de caracteres
vector<int> EnquadradorContagemDeCaracteres::Enquadrar(vector<int> quadro) {
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

vector<int> EnquadradorContagemDeCaracteres::Desenquadrar(vector<int> quadro) {
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

// Inserção de bytes
vector<int> EnquadradorInsercaoDeBytes::Enquadrar(vector<int> quadro) {
    return quadro;
}

vector<int> EnquadradorInsercaoDeBytes::Desenquadrar(vector<int> quadro) {
    return quadro;
}
