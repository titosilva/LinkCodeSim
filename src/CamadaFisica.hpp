#ifndef LINKCODESIM_CAMADA_FISICA_HPP
#define LINKCODESIM_CAMADA_FISICA_HPP

#include <vector>

using namespace std;

enum CODIFICACOES {
    Binaria = 1,
    Bipolar = 2,
    Manchester = 3,
    Todos = 4,
};

vector<int> CamadaFisicaTransmissoraCodificacaoBinaria(vector<int> quadro);
vector<int> CamadaFisicaTransmissoraCodificacaoBipolar(vector<int> quadro);
vector<int> CamadaFisicaTransmissoraCodificacaoManchester(vector<int> quadro);

vector<int> CamadaFisicaReceptoraCodificacaoBinaria(vector<int> quadro);
vector<int> CamadaFisicaReceptoraCodificacaoBipolar(vector<int> quadro);
vector<int> CamadaFisicaReceptoraCodificacaoManchester(vector<int> quadro);

//função auxiliar para imprimir
void Imprimir(vector<int>);
#endif