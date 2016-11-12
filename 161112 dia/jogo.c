#include "jogo/cabecalho.h"

int main(int argc, char** argv) {
    int i, j;
    int mapa[2][T][T] = {0};
    int barcos[2][T] = {0};
    int pontuacao[2] = {0};
    int rodada = 0;
    int jogada;

    char entrada[10];
    char grade[TT];

    time_t semente;

    time(&semente);
    srand((int) semente);

    //    construcao(barcos[0], grade_usr);
    //    construcao(barcos[1], grade_cpu);

    construcao(barcos[0], mapa[0]);
    construcao(barcos[1], mapa[1]);

    //    menu(grade);

    while (1) {
        tela_jogo(grade, mapa);
        sprintf(grade, "%s          Jogador %d (%d pontos) - Informe a coordenada de ataque ou a opcao: ", grade, rodada + 1, pontuacao[rodada]);

        system("clear");
        printf("%s", grade);
        scanf("%s", entrada);

        if ('S' == toupper(entrada[0]))
            jogada = 9999;
        else if ('A' == toupper(entrada[0]))
            jogada = 9998;
        else jogada = atoi(entrada);

        executa_transacao(encerramento, (long) jogada);

        //        if ((jogada < 0) || jogada > 99) {
        //            printf("%s", "Jogada Invalida\n");
        //            __fpurge(stdin);
        //            getchar();
        //        }
        //
    }

    ////        jogo(rodada, pontuacao, grade, mapa);
    //
    //    //    executa_transacao(abertura, 0);
    //    //    teste(mapa[0]);
    //
    //    //    for (i = 0; i < T; i++)
    //    //        printf("%d", mapa[0][0][i]);

    pthread_exit(NULL);
}

