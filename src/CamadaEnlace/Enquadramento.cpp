#include "Enquadramento.hpp"
#include "../Utilitario.hpp"

#include <vector>
#include <algorithm>
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
    vector<int> resultado(quadro);
    auto bytes = DivideVetor(8, resultado);
    
    for (auto byteRef = bytes.begin(); byteRef < bytes.end(); byteRef++) {
        auto byte = *byteRef;
        if (byte == CharParaBits(FLAG)) {
            auto ESCbits = CharParaBits(ESC);
            bytes.insert(byteRef, ESCbits);
            byteRef++;
        }
    }
    
    bytes.insert(bytes.begin(), CharParaBits(FLAG));
    bytes.push_back(CharParaBits(FLAG));

    return Colapsar(bytes);
}

vector<int> EnquadradorInsercaoDeBytes::Desenquadrar(vector<int> quadro) {
    vector<int> resultado(quadro);
    auto bytes = DivideVetor(8, resultado);

    // Encontrar as flags de início e fim
    auto flagDeInicio = bytes.begin();
    for (flagDeInicio = bytes.begin(); flagDeInicio < bytes.end(); flagDeInicio++) {
        // Verificar condições
        // É flag?
        bool flag = (*flagDeInicio == CharParaBits(FLAG));
        // É o primeiro byte?
        bool primeiroByte = (flagDeInicio == bytes.begin());
        // Se não é o primeiro byte, é antecedido por um ESC? Se for, não considerar como flag de inicio
        bool anteriorEsc = primeiroByte? false : (*(flagDeInicio - 1) == CharParaBits(ESC));

        if (flag && (primeiroByte || !anteriorEsc)) {
            // Se atender às condições necessárias, a FLAG foi encontrada
            break;
        }
    }

    if (flagDeInicio == bytes.end()) {
        Imprime("Não foi encontrada a flag de início!");
        exit(0);
    }

    auto flagDeFim = bytes.end();
    for (flagDeFim = bytes.end(); flagDeFim > bytes.begin(); flagDeFim--) {
        // Verificar condições
        // É flag?
        bool flag = (*flagDeFim == CharParaBits(FLAG));
        // Se não é o primeiro byte, é antecedido por um ESC? Se for, não considerar como flag de inicio
        bool anteriorEsc = (*(flagDeInicio - 1) == CharParaBits(ESC));

        if (flag && !anteriorEsc) {
            // Se atender às condições necessárias, a FLAG foi encontrada
            break;
        }
    }

    if (flagDeFim == bytes.begin()) {
        Imprime("Não foi encontrada a flag de fim!");
        exit(0);
    }

    if (flagDeInicio == flagDeFim) {
        Imprime("As flags de início e fim não podem ser diferenciadas!");
        exit(0);
    }

    // Remover bytes fora das flags
    bytes = vector<vector<int>>(flagDeInicio, flagDeFim + 1);
    
    // Remover caracteres de ESC
    for (auto byteRef = bytes.begin(); byteRef < bytes.end() - 1; byteRef++) {
        auto byte = *byteRef;
        if (byte == CharParaBits(ESC) && *(byteRef + 1) == CharParaBits(FLAG)) {
            bytes.erase(byteRef);
        }
    }

    // Remover flags de início e fim
    bytes.erase(bytes.begin());
    bytes.erase(bytes.end());

    return Colapsar(bytes);
}
