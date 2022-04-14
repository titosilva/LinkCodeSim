#ifndef LINKCODESIM__CAMADA_FISICA__CAMADA_FISICA
#define LINKCODESIM__CAMADA_FISICA__CAMADA_FISICA

#include <vector>
using namespace std;

#include "../Camadas.hpp"

class CamadaFisica {
   private:
    Codificador* codificador;

    CamadaEnlace* camadaSuperior;

    Maquina* maquinaConectada;

   public:
    CamadaFisica(Codificador* codificador) : codificador(codificador), camadaSuperior(NULL), maquinaConectada(NULL){};
    void ReceberDados(vector<int> quadro);
    void TransmitirDados(vector<int> quadro);

    void ConectarCamadaEnlace(CamadaEnlace* camadaEnlace) {
        this->camadaSuperior = camadaEnlace;
    }

    void ConectarMaquina(Maquina* maquina) {
        this->maquinaConectada = maquina;
    }
};

#endif
