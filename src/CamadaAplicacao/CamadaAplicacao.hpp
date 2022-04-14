#ifndef LINKCODESIM__CAMADA_APLICACAO__CAMADA_APLICACAO
#define LINKCODESIM__CAMADA_APLICACAO__CAMADA_APLICACAO

#include <string>
#include <vector>

#include "../Camadas.hpp"

using namespace std;

class CamadaAplicacao {
   private:
    Aplicacao* aplicacao;
    CamadaEnlace* camadaInferior;

   public:
    CamadaAplicacao() : aplicacao(NULL), camadaInferior(NULL){};
    void ReceberDados(vector<int> quadro);
    void TransmitirDados(string mensagem);

    void ConectarAplicacao(Aplicacao* aplicacao) {
        this->aplicacao = aplicacao;
    }

    void ConectarCamadaEnlace(CamadaEnlace* camadaEnlace) {
        this->camadaInferior = camadaEnlace;
    }
};

#endif
