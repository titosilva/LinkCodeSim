#ifndef LINKCODESIM__CAMADA_FISICA__CODIFICACOES
#define LINKCODESIM__CAMADA_FISICA__CODIFICACOES

#include <vector>

using namespace std;

// Definições básicas
enum CODIFICACOES {
    Binaria = 1,
    Bipolar,
    Manchester,
};

class Codificador {
   public:
    static Codificador* Criar(CODIFICACOES codificacao);
    virtual vector<int> Codificar(vector<int> quadro) = 0;
    virtual vector<int> Decodificar(vector<int> quadro) = 0;
};

// Tipos de codificador
class CodificadorBinario : public Codificador {
   public:
    vector<int> Codificar(vector<int> quadro);
    vector<int> Decodificar(vector<int> quadro);
};

class CodificadorBipolar : public Codificador {
   public:
    vector<int> Codificar(vector<int> quadro);
    vector<int> Decodificar(vector<int> quadro);
};

class CodificadorManchester : public Codificador {
   public:
    vector<int> Codificar(vector<int> quadro);
    vector<int> Decodificar(vector<int> quadro);
};

#endif