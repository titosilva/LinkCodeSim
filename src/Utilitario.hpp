#ifndef LINKCODESIM__UTILITARIO
#define LINKCODESIM__UTILITARIO

#include <vector>
#include <iostream>
#include <string>

using namespace std;

// Usado para facilitar o uso de funções any_of, all_of e none_of
// Define uma expressão lambda a ser usada como argumento para qualquer das funções acima
#define expr(arg, expression) [](auto arg) { return ( expression ) ; }

// Funções genéricas para facilitar escritas no console
void Imprime(string texto);
void Imprime(int numero);
void NovaLinha();

// Funções para auxiliar manipulações de vetores
// Divide um vetor em partes de tamanhos iguais
vector<vector<int>> DivideVetor(int tamanhoDaParte, vector<int> original);
// Une subvetores em um vetor só (contrário de DivideVetor)
vector<int> Colapsar(vector<vector<int>> subvetores);
// Copia um vetor
vector<int> Copia(vector<int> original);
// Função utilizada para imprimir um vector<int>
void Imprime(vector<int> dados);
// Calcula o resto da divisão binária entre polinômios representados pelo dividendo e pelo divisor
// Usado pelo CRC
vector<int> ObterRestoDaDivisaoBinaria(vector<int> dividendo, vector<int> divisor);
// Transforma um int para um trem de bits
vector<int> IntParaBits(uint32_t valor);
// Transforma um trem de bits para char
char BitsParaChar(vector<int> bits);
// Transforma um char para um trem de bits
vector<int> CharParaBits(char c);

#endif