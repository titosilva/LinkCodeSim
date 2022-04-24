#include <iostream>

#include "Simulador.hpp"
#include "UI/UIBasics.hpp"
#include "Camadas.hpp"

using namespace std;

int main() {
    auto codificacao = Binaria;
    auto enquadramento = ContagemDeCaracteres;
    auto controleDeErro = Hamming;

    auto maquinaTransmissora = Maquina::Construir(codificacao, enquadramento, controleDeErro);
    auto maquinaReceptora = Maquina::Construir(codificacao, enquadramento, controleDeErro);

    maquinaTransmissora->Conectar(maquinaReceptora);
    maquinaReceptora->Conectar(maquinaTransmissora);

    maquinaTransmissora->ExecutarAplicacao();

    return 0;
}