#include "jogo/cabecalho.h"

int main(int argc, char** argv) {
    int i, j;
    int mapa[2][T][T] = {0};
    int barcos[2][T] = {0};

    time_t semente;

    time(&semente);
    srand((int) semente);

    construcao(barcos[0], grade_usr);
    construcao(barcos[1], grade_cpu);

    executa_transacao(tela, 0);
    teste(mapa[0]);

    //    for (i = 0; i < T; i++)
    //        printf("%d", mapa[0][0][i]);

    pthread_exit(NULL);
}

