#ifndef LINKCODESIM__CAMADA_FISICA__CAMADA_FISICA
#define LINKCODESIM__CAMADA_FISICA__CAMADA_FISICA

#include <vector>
using namespace std;

#include "../Camadas.hpp"

class CamadaFisica {
   private:
    Codificador* codificador;

    CamadaEnlace* camadaSuperior;

   public:
    CamadaFisica(Codificador* codificador) : codificador(codificador), camadaSuperior(NULL){};
    void ReceberDados(vector<int> quadro);
    void TransmitirDados(vector<int> quadro);

    void ConectarCamadaEnlace(CamadaEnlace* camadaEnlace) {
        this->camadaSuperior = camadaEnlace;
    }
};

#endif
