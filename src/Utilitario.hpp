#ifndef LINKCODESIM__UTILITARIO
#define LINKCODESIM__UTILITARIO

#include <vector>
#include <iostream>
#include <string>

using namespace std;

// Funções genéricas para facilitar escritas no console
void Imprime(string texto);
void NovaLinha();
// Função utilizada para imprimir um vector<int>
void Imprime(vector<int> dados);
// Calcula o resto da divisão binária entre polinômios representados pelo dividendo e pelo divisor
// Usado pelo CRC
vector<int> ObterRestoDaDivisaoBinaria(vector<int> dividendo, vector<int> divisor);
// Transforma um int para um trem de bits
vector<int> IntParaBits(uint32_t valor);

#endif