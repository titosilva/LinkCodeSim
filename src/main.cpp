#include <iostream>

#include "Simulador.hpp"
#include "UI/UIBasics.hpp"

using namespace std;

int main() {
    auto codificacao = PerguntarCodificao();
    auto enquadramento = PerguntarEnquadramento();

    auto maquinaTransmissora = Maquina::Construir(codificacao, enquadramento);
    auto maquinaReceptora = Maquina::Construir(codificacao, enquadramento);

    maquinaTransmissora->Conectar(maquinaReceptora);
    maquinaReceptora->Conectar(maquinaTransmissora);

    maquinaTransmissora->IniciarTransmissao();

    return 0;
}