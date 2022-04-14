#ifndef LINKCODESIM__CAMADA_ENLACE__CAMADA_ENLACE
#define LINKCODESIM__CAMADA_ENLACE__CAMADA_ENLACE

#include <vector>

#include "../Camadas.hpp"

using namespace std;

class CamadaEnlace {
   private:
    Enquadrador* enquadrador;

    CamadaFisica* camadaInferior;
    CamadaAplicacao* camadaSuperior;

   public:
    CamadaEnlace(Enquadrador* enquadrador) : enquadrador(enquadrador), camadaInferior(NULL), camadaSuperior(NULL){};
    void ReceberDados(vector<int> quadro);
    void TransmitirDados(vector<int> quadro);

    void ConectarCamadaFisica(CamadaFisica* camadaFisica) {
        this->camadaInferior = camadaFisica;
    }

    void ConectarCamadaAplicacao(CamadaAplicacao* camadaAplicacao) {
        this->camadaSuperior = camadaAplicacao;
    }
};

#endif
