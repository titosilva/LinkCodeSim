#include "Maquina.hpp"

void Maquina::ExecutarAplicacao() {
    this->aplicacao->LerEntradaETransmitir();
}

void Maquina::ReceberDados(vector<int> quadro) {
    this->camadaFisica->ReceberDados(quadro);
}

void Maquina::Conectar(Maquina* maquina) {
    this->camadaFisica->ConectarMaquina(maquina);
}

Maquina* Maquina::Construir(CODIFICACOES codificacao, ENQUADRAMENTOS enquadramento, CONTROLES_DE_ERRO controleDeErro) {
    auto aplicacao = new Aplicacao();

    auto camadaAplicacao = new CamadaAplicacao();

    auto enquadrador = Enquadrador::Criar(enquadramento);
    auto controladorDeErro = ControladorDeErro::Criar(controleDeErro);
    auto camadaEnlace = new CamadaEnlace(enquadrador, controladorDeErro);

    auto codificador = Codificador::Criar(codificacao);
    auto camadaFisica = new CamadaFisica(codificador);

    return new Maquina(aplicacao, camadaAplicacao, camadaEnlace, camadaFisica);
}


Maquina::Maquina(Aplicacao* aplicacao,
                 CamadaAplicacao* camadaAplicacao,
                 CamadaEnlace* camadaEnlace,
                 CamadaFisica* camadaFisica) {
    this->aplicacao = aplicacao;
    this->camadaAplicacao = camadaAplicacao;
    this->camadaEnlace = camadaEnlace;
    this->camadaFisica = camadaFisica;

    this->aplicacao->ConectarCamadaAplicacao(camadaAplicacao);

    this->camadaAplicacao->ConectarAplicacao(aplicacao);
    this->camadaAplicacao->ConectarCamadaEnlace(camadaEnlace);

    this->camadaEnlace->ConectarCamadaAplicacao(camadaAplicacao);
    this->camadaEnlace->ConectarCamadaFisica(camadaFisica);

    this->camadaFisica->ConectarCamadaEnlace(camadaEnlace);
}