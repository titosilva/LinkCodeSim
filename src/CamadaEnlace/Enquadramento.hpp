#ifndef LINKCODESIM__CAMADA_ENLACE__ENQUADRAMENTO
#define LINKCODESIM__CAMADA_ENLACE__ENQUADRAMENTO

#include <vector>
using namespace std;

// Definições básicas
enum ENQUADRAMENTOS {
    ContagemDeCaracteres = 1,
    InsercaoDeBytes,
};

class Enquadrador {
   public:
    static Enquadrador* Criar(ENQUADRAMENTOS enquadramento);
    virtual vector<int> Enquadrar(vector<int> quadro) = 0;
    virtual vector<int> Desenquadrar(vector<int> quadro) = 0;
};

// Tipos de enquadrador
class EnquadradorContagemDeCaracteres : public Enquadrador {
   public:
    vector<int> Enquadrar(vector<int> quadro);
    vector<int> Desenquadrar(vector<int> quadro);
};

class EnquadradorInsercaoDeBytes : public Enquadrador {
   public:
    const static char ESC = 0x1B;
    // Propositalmente, uma letra comum, com o objetivo de facilitar testes
    const static char FLAG = 'a'; 
    vector<int> Enquadrar(vector<int> quadro);
    vector<int> Desenquadrar(vector<int> quadro);
};

#endif
