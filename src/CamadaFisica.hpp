#ifndef LINKCODESIM_CAMADA_FISICA_HPP
#define LINKCODESIM_CAMADA_FISICA_HPP

#include <vector>

using namespace std;

enum CODIFICACOES {
    Binaria = 0,
    Bipolar,
    Manchester,
};

vector<int> CamadaFisicaTransmissoraCodificacaoBinaria(vector<int> quadro);
vector<int> CamadaFisicaTransmissoraCodificacaoBipolar(vector<int> quadro);
vector<int> CamadaFisicaTransmissoraCodificacaoManchester(vector<int> quadro);

vector<int> CamadaFisicaReceptoraCodificacaoBinaria(vector<int> quadro);
vector<int> CamadaFisicaReceptoraCodificacaoBipolar(vector<int> quadro);
vector<int> CamadaFisicaReceptoraCodificacaoManchester(vector<int> quadro);

#endif