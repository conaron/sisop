#include "situacoes.c"

void executa_transacao(void *funcao, long arg) {
    pthread_t id;
    void * parametro = (void *) arg;
    int transacao = pthread_create(&id, NULL, funcao, parametro);
    if (transacao) {
        perror("pthread_create");
        exit(-1);
    }
}

void tracejado() {
    printf("   ");
    for (i = 0; i < T * 4 + 1; i++)
        printf("-");
}

char conversao(int celula) {
    switch (celula) {
        case 0:
            return ' ';
            break;
        case 1:
            return '1';
            break;
    }
}

void *imprime_grade() {
    system("clear");

    for (i = 0; i < 17; i++)
        printf(" ");
    printf("U S U A R I O");
    //    printf("PC");
    printf("\n");
    tracejado();
    printf("     ");
    tracejado();
    printf("\n");
    printf("     A   B   C   D   E   F   G   H   I   J       ");
    printf("     A   B   C   D   E   F   G   H   I   J\n");
    tracejado();
    printf("     ");
    tracejado();
    printf("\n");

    for (i = 0; i < T; i++) {
        if (i < 9)
            printf(" %d | ", i + 1);
        else
            printf("%d | ", i + 1);
        for (j = 0; j < T; j++)
            printf("%c | ", conversao(grade_usr[i][j]));
        if (i < 9)
            printf("     %d | ", i + 1);
        else
            printf("    %d | ", i + 1);
        for (j = 0; j < T; j++) {
            printf("%c | ", conversao(grade_cpu[i][j]));
        }
        printf("\n");
    }

    tracejado();
    printf("     ");
    tracejado();
    printf("\n\n\n");

}
