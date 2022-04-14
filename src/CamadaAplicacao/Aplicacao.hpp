#ifndef LINKCODESIM__CAMADA_APLICACAO__APLICACAO
#define LINKCODESIM__CAMADA_APLICACAO__APLICACAO

#include <string>

#include "../Camadas.hpp"

using namespace std;

class Aplicacao {
   private:
    CamadaAplicacao* camadaInferior;

   public:
    Aplicacao() : camadaInferior(NULL){};
    void LerEntradaETransmitir();
    void ReceberMensagemEMostrar(string mensagem);

    void ConectarCamadaAplicacao(CamadaAplicacao* camadaAplicacao) {
        this->camadaInferior = camadaAplicacao;
    }
};

#endif
