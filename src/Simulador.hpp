#ifndef LINKCODESIM_SIMULADOR_HPP
#define LINKCODESIM_SIMULADOR_HPP

#include <string>
#include <vector>

#include "Camadas.hpp"

using namespace std;

Maquina* ConstruirMaquina(CODIFICACOES codificacao, ENQUADRAMENTOS enquadramento);

void MeioDeComunicacao(vector<int> quadro);

#endif