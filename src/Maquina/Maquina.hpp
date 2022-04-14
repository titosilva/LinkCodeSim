#ifndef LINKCODESIM__MAQUINA__MAQUINA
#define LINKCODESIM__MAQUINA__MAQUINA

#include <vector>

#include "../Camadas.hpp"

using namespace std;

class Maquina {
   private:
    CamadaEnlace* camadaEnlace;
    CamadaFisica* camadaFisica;
    CamadaAplicacao* camadaAplicacao;
    Aplicacao* aplicacao;

   public:
    Maquina(Aplicacao* aplicacao,
            CamadaAplicacao* camadaAplicacao,
            CamadaEnlace* camadaEnlace,
            CamadaFisica* camadaFisica) : aplicacao(aplicacao),
                                          camadaAplicacao(camadaAplicacao),
                                          camadaEnlace(camadaEnlace),
                                          camadaFisica(camadaFisica) {}
    void IniciarTransmissao();
    void ReceberDados(vector<int> quadro);
    void Conectar(Maquina* maquina);
};

#endif