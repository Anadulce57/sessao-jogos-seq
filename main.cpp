#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include <cstdlib>

std::random_device rd;
std::mt19937 gen(rd());

void jogoAdivinhaNum() {
    std::uniform_int_distribution<> dis(1, 100);

    char jogarNovamente;

    do {
        int numsecret = dis(gen);
        int palpite = 0;
        int tentativas = 0;

        std::cout << "Bem-vindo ao jogo da adivinhacao!" << std::endl;
        std::cout << "Tente acertar o numero que estou pensando de 1 a 100" << std::endl;

        do {
            std::cout << "Digite o palpite:";
            std :: cin >> palpite;
            tentativas++;

            if (palpite > numsecret) {
                std::cout << "Numero alto!" << std::endl;
            }
            else if (palpite < numsecret) {
                std::cout << "Numero baixo!" << std::endl;
            }

        }while (palpite != numsecret);
        std::cout << "Parabens! Tentativas: " << tentativas << std::endl;

        std::cout << "Jogar novamente? (s/n)?" << std::endl;
        std::cin >> jogarNovamente;

    }while (jogarNovamente == 's' || jogarNovamente == 'S');
}

void jogoForca() {
    char jogarNovamenteF;

    do {

        std::vector<std::string> bancoPalavras = {
            "BANANA", "ESCORPIAO", "ORQUESTRA", "XILOFONE", "QUARTZO"
        };

        //Selecionando minha palavra
        std::uniform_int_distribution<> dis(0, bancoPalavras.size() -1);
        std::string palavraSecreta =  bancoPalavras[dis(gen)];

        //Espaços da palavra
        std::string palavraFeita(palavraSecreta.length(), '_');

        //Declarações
        int tentativas = 6;
        char letra;

        std::cout << "JOGO DA FORCA" << std::endl;

        while (tentativas > 0 && palavraFeita != palavraSecreta ) {
            std::cout << "\nPalavra:" << palavraFeita;
            std::cout << "\nChances:" << tentativas;
            std::cout << "\nDigite uma letra: ";
            std::cin >> letra;
            letra = toupper(letra);

            bool acerto = false;

            for (int i = 0; i < palavraSecreta.length(); i++) {
                if (palavraSecreta[i] == letra) {
                    palavraFeita[i] = letra;
                    acerto = true;
                }
            }
            if (!acerto) {
                tentativas--;
                std::cout << "Vishh, no tengo essa letra" <<std::endl;
            }
        }
        if (tentativas == 0 && palavraFeita != palavraSecreta) {
            std::cout << "Ihhh perdeu!" <<std::endl;
        }
        else if (tentativas >= 1 && palavraFeita == palavraSecreta) {
            std::cout << "Voce ganhou!" << std::endl;
        }

        std:: cout << "Jogar novamente? (s/n)" << std::endl;
        std:: cin >> jogarNovamenteF;

    }while (jogarNovamenteF == 's' || jogarNovamenteF == 'S');
}

void jogoPpt() {
    std::uniform_int_distribution<> dis(1, 3);

    char jogarNovamenteT;

    do {
        //Declarando
        int escolhaPC = dis(gen);
        int escolhaVc;

        std:: cout << "Pedra, papel e tesoura" << std::endl;
        std:: cout << "Escolha:\n 1-pedra\n 2-papel\n 3-tesoura" << std::endl;
        std:: cout << "Aqui abaixo:" << std::endl;
        std:: cin >> escolhaVc;

        std::this_thread::sleep_for(std::chrono::milliseconds(800));

        //Fazendo switch pra ficar bonitinho
        std:: cout << "O computador escolheu: ";
        switch (escolhaPC) {
            case 1:
                std:: cout << "Pedra" << std::endl;
                break;
            case 2:
                std:: cout << "Papel" << std::endl;
                break;
            case 3:
                std:: cout << "Tesoura" << std::endl;
                break;
        }

        if (escolhaVc == escolhaPC) {
            std:: cout << "Empate" << std::endl;
        }

        else if ((escolhaVc == 1 && escolhaPC == 3) ||
            (escolhaVc == 2 && escolhaPC == 1) ||
            (escolhaVc == 3 && escolhaPC == 2)) {
            std :: cout << "Parabens voce ganhou!" << std::endl;
            }
        else {
            std:: cout << "Oh bicho burro, uma máquina ganhou de voce!" << std::endl;
        }

        std:: cout << "Jogar novamente? (s/n)" << std::endl;
        std:: cin >> jogarNovamenteT;

    }while (jogarNovamenteT == 's' || jogarNovamenteT == 'S');
}

int main() {
    system("cls");
    int escolha;

    do {
        std:: cout << "Bem-vindo a uma sequencia de jogos, escolha qual ira jogar:\n";
        std::cout << "1 - Jogo da Adivinhacao\n";
        std::cout << "2 - Jogo da Forca\n";
        std::cout << "3 - Pedra, Papel e Tesoura\n";
        std::cout << "4 - Sair\n";
        std:: cin >> escolha;

        switch (escolha) {
            case 1:
                jogoAdivinhaNum();
                break;
            case 2:
                jogoForca();
                break;
            case 3:
                jogoPpt();
                break;
            case 4:
                std:: cout << "Saindo..." << std::endl;
            default:
                std:: cout << "Erro!" << std::endl;
        }

    }while (escolha != 0);

    return 0;
}