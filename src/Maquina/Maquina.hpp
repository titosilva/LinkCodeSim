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

    // Construtor privado para forçar o uso do "Construir"
    Maquina(Aplicacao* aplicacao,
            CamadaAplicacao* camadaAplicacao,
            CamadaEnlace* camadaEnlace,
            CamadaFisica* camadaFisica);

   public:
    static Maquina* Construir(CODIFICACOES codificacao, ENQUADRAMENTOS enquadramento);
    void ExecutarAplicacao();
    void ReceberDados(vector<int> quadro);
    void Conectar(Maquina* maquina);
};

#endif