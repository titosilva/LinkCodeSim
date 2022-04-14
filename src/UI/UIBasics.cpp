#include "UIBasics.hpp"

#include <iostream>
#include <limits>

#include "../CamadaEnlace/Enquadramento.hpp"
#include "../CamadaFisica/Codificacoes.hpp"

using namespace std;

ENQUADRAMENTOS PerguntarEnquadramento() {
    char c = '\0';

    // Pega o tipo de transmissao desejada pelo usuário
    do {
        cout << "---------------------------------" << endl;
        cout << "Qual o tipo de enquadramento desejado? " << endl;
        cout << ContagemDeCaracteres << " - Contagem de caracteres" << endl;
        cout << InsercaoDeBytes << " - Inserção de bytes" << endl;
        cout << "---------------------------------" << endl;

        cin >> c;

        cin.clear();
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
    } while (c < '1' || c > '2');

    cout << endl;

    auto escolha = c - '0';
    return escolha == ContagemDeCaracteres ? ContagemDeCaracteres : InsercaoDeBytes;
}

CODIFICACOES PerguntarCodificao() {
    char c = '\0';

    // Pega o tipo de codificação desejada pelo usuário
    do {
        cout << "---------------------------------" << endl;
        cout << "Qual o tipo de codificação deseja? " << endl;
        cout << Binaria << " - Codificacao Binaria" << endl;
        cout << Bipolar << " - Codificacao Bipolar" << endl;
        cout << Manchester << " - Codificacao Manchester" << endl;
        cout << "---------------------------------" << endl;

        cin >> c;

        cin.clear();
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
    } while (c < '1' || c > '3');

    cout << endl;

    auto escolha = c - '0';
    return escolha == Binaria ? Binaria : escolha == Bipolar ? Bipolar
                                                             : Manchester;
}
