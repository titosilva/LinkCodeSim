#ifndef LINKCODESIM_CAMADA_ENLACE_HPP
#define LINKCODESIM_CAMADA_ENLACE_HPP

#include <vector>

using namespace std;

void CamadaEnlaceDadosTransmissora(vector<int> quadro);
void CamadaEnlaceDadosTransmissoraEnquadramento(vector<int> quadro);
void CamadaEnlaceDadosTransmissoraEnquadramentoContagemDeCaracteres(vector<int> quadro);
void CamadaEnlaceDadosTransmissoraEnquadramentoInsercaoDeBytes(vector<int> quadro);

void CamadaEnlaceDadosReceptora(vector<int> quadro);
void CamadaEnlaceDadosReceptoraEnquadramento(vector<int> quadro);
void CamadaEnlaceDadosReceptoraEnquadramentoContagemDeCaracteres(vector<int> quadro);
void CamadaEnlaceDadosReceptoraEnquadramentoInsercaoDeBytes(vector<int> quadro);

#endif