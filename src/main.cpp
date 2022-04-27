#include <iostream>

#include "Simulador.hpp"
#include "UI/UIBasics.hpp"

using namespace std;

int main() {
    auto codificacao = PerguntarCodificao();
    auto enquadramento = PerguntarEnquadramento();
    auto controleDeErro = PerguntarControleDeErro();

    auto maquinaTransmissora = Maquina::Construir(codificacao, enquadramento, controleDeErro);
    auto maquinaReceptora = Maquina::Construir(codificacao, enquadramento, controleDeErro);

    maquinaTransmissora->Conectar(maquinaReceptora);
    maquinaReceptora->Conectar(maquinaTransmissora);

    maquinaTransmissora->ExecutarAplicacao();

    return 0;
}