#include "ControleDeErro.hpp"

ControladorDeErro* ControladorDeErro::Criar(CONTROLES_DE_ERRO controleDeErro) {
    switch (controleDeErro) {
        case BitParidadePar:
            return new ControladorDeErroBitParidadePar();
        case CRC:
            return new ControladorDeErroCRC();
        default:
            throw new exception();
    }
}

// Bit paridade par
vector<int> ControladorDeErroBitParidadePar::Preparar(vector<int> quadro) {
    return quadro;
}

vector<int> ControladorDeErroBitParidadePar::Recuperar(vector<int> quadro) {
    return quadro;
}

// CRC
vector<int> ControladorDeErroCRC::Preparar(vector<int> quadro) {
    return quadro;
}

vector<int> ControladorDeErroCRC::Recuperar(vector<int> quadro) {
    return quadro;
}
