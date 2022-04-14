#include <iostream>

#include "Simulador.hpp"
#include "UI/UIBasics.hpp"

using namespace std;

int main() {
    auto codificacao = PerguntarCodificao();
    auto enquadramento = PerguntarEnquadramento();

    auto maquinaTransmissora = ConstruirMaquina(codificacao, enquadramento);
    auto maquinaReceptora = ConstruirMaquina(codificacao, enquadramento);

    maquinaTransmissora->IniciarTransmissao();

    return 0;
}