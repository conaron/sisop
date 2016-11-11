#include "metodos.c"

int main(int argc, char** argv) {

    for (i = 0; i < T; i++)
        for (j = 0; j < T; j++)
            grade_usr[i][j] = grade_cpu[i][j] = 0;

    definicao();
    executa_transacao(imprime_grade, 0);
    pthread_exit(NULL);
}

