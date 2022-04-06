#ifndef LINKCODESIM_CAMADA_ENLACE_HPP
#define LINKCODESIM_CAMADA_ENLACE_HPP

#include <vector>

using namespace std;

enum ENQUADRAMENTOS {
    ContagemDeCaracteres = 1,
    InsercaoDeBytes,
};

vector<int> CamadaEnlaceDadosTransmissoraEnquadramento(vector<int> quadro, ENQUADRAMENTOS enquadramento);
vector<int> CamadaEnlaceDadosTransmissoraEnquadramentoContagemDeCaracteres(vector<int> quadro);
vector<int> CamadaEnlaceDadosTransmissoraEnquadramentoInsercaoDeBytes(vector<int> quadro);

vector<int> CamadaEnlaceDadosReceptoraEnquadramento(vector<int> quadro, ENQUADRAMENTOS enquadramento);
vector<int> CamadaEnlaceDadosReceptoraEnquadramentoContagemDeCaracteres(vector<int> quadro);
vector<int> CamadaEnlaceDadosReceptoraEnquadramentoInsercaoDeBytes(vector<int> quadro);

#endif