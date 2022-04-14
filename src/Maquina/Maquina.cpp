#include "Maquina.hpp"

void Maquina::IniciarTransmissao() {
    this->aplicacao->LerEntradaETransmitir();
}

void Maquina::ReceberDados(vector<int> quadro) {
    this->camadaFisica->ReceberDados(quadro);
}

void Maquina::Conectar(Maquina* maquina) {
    this->camadaFisica->ConectarMaquina(maquina);
}