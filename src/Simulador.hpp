#ifndef LINKCODESIM_SIMULADOR_HPP
#define LINKCODESIM_SIMULADOR_HPP

#include <string>
#include <vector>

using namespace std;

void AplicacaoTransmissora(void);
void CamadaDeAplicacaoTransmissora(string mensagem);
void CamadaFisicaTransmissora(vector<int> quadro);
void CamadaEnlaceDadosTransmissora(vector<int> quadro);

void MeioDeComunicacao(vector<int> quadro);

void CamadaEnlaceDadosReceptora(vector<int> quadro);
void CamadaFisicaReceptora(vector<int> quadro);
void CamadaDeAplicacaoReceptora(vector<int> quadro);
void AplicacaoReceptora(string mensagem);

#endif