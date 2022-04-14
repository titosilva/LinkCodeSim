#include "Aplicacao.hpp"

#include <string>
#include <iostream>
#include "../Camadas.hpp"

using namespace std;

void Aplicacao::LerEntradaETransmitir() {
    string mensagem;
    cout << "Digite uma mensagem:" << endl;
    cin >> mensagem;
    cout << endl;

    this->camadaInferior->TransmitirDados(mensagem);
}

void Aplicacao::ReceberMensagemEMostrar(string mensagem) {
    cout << "A mensagem recebida foi:" << endl
         << mensagem << endl;
}
