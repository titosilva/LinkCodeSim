#ifndef LINKCODESIM__CAMADA_ENLACE__CONTROLE_DE_ERRO
#define LINKCODESIM__CAMADA_ENLACE__CONTROLE_DE_ERRO

#include <vector>
using namespace std;

// Definições básicas
enum CONTROLES_DE_ERRO {
    BitParidadePar = 1,
    CRC,
    Hamming,
};

class ControladorDeErro {
   public:
    static ControladorDeErro* Criar(CONTROLES_DE_ERRO controleDeErro);
    virtual vector<int> Preparar(vector<int> quadro) = 0;
    virtual vector<int> Recuperar(vector<int> quadro) = 0;
};

// Tipos de controlador de erro
class ControladorDeErroBitParidadePar : public ControladorDeErro {
   public:
    vector<int> Preparar(vector<int> quadro);
    vector<int> Recuperar(vector<int> quadro);
};

class ControladorDeErroCRC : public ControladorDeErro {
   public:
    vector<int> Preparar(vector<int> quadro);
    vector<int> Recuperar(vector<int> quadro);
};

class ControladorDeErroHamming : public ControladorDeErro {
   private:
    int calcularParidadeParaSubgrupo(int subgrupo, vector<int> byte);
    vector<int> detectarGruposComErro(vector<int>* byte);
    bool tentarRecuperarErros(vector<int> *byte, vector<int> gruposComErro);

   public:
    vector<int> Preparar(vector<int> quadro);
    vector<int> Recuperar(vector<int> quadro);
};

#endif