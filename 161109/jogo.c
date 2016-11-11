#include "jogo/metodos.c"

int main(int argc, char** argv) {
    int tempo = 1000000;
    //    __fpurge(stdin);
    for (i = 0; i < T; i++)
        for (j = 0; j < T; j++)
            grade_usr[i][j] = grade_cpu[i][j] = 0;

    definicao(0, 0);

//    while (1 == 1) {
        executa_transacao(tela, 0);
//    }

    pthread_exit(NULL);
}

