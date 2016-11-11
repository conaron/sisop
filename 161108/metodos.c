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

//void *le_dados() {
//    char valor[10];
//    scanf("%s", &valor);
//
//    //    if ((valor == 1) || (valor == 2))
//    //        direcao = valor;
//    //    else if (valor == 0)
//    //        exit(EXIT_FAILURE);
//}

char conversao(int celula) {
    switch (celula) {
        case 0:
            return ' ';
            break;
        case 1:
            return '1';
            break;
        case 2:
            return '-';
            break;
        case 3:
            return 'X';
            break;
    }
}

void *imprime_grade() {
    system("clear");
    char grade[1500] = "";
    char espaco[5] = "";

    sprintf(grade, "%s                 U S U A R I O                                         P C\n", grade);
    sprintf(grade, "%s   -----------------------------------------        -----------------------------------------\n", grade);
    sprintf(grade, "%s     A   B   C   D   E   F   G   H   I   J            A   B   C   D   E   F   G   H   I   J\n", grade);
    sprintf(grade, "%s   -----------------------------------------        -----------------------------------------\n", grade);

    for (i = 0; i < T; i++) {
        sprintf(espaco, "%d", i + 1);
        if (i < 9)
            sprintf(espaco, " %d", i + 1);
        sprintf(grade, "%s%s | ", grade, espaco);

        for (j = 0; j < T; j++)
            sprintf(grade, "%s%c | ", grade, conversao(grade_usr[i][j]));

        sprintf(grade, "%s    %s | ", grade, espaco);

        for (j = 0; j < T; j++)
            sprintf(grade, "%s%c | ", grade, conversao(grade_cpu[i][j]));
        sprintf(grade, "%s\n", grade);
    }

    sprintf(grade, "%s   -----------------------------------------        -----------------------------------------\n", grade);
    sprintf(grade, "%s\n\n", grade);
    sprintf(grade, "%sBATALHA NAVAL\n", grade);
    sprintf(grade, "%s\n", grade);

    if (jogada == 0)
        sprintf(grade, "%sJogador 1 - Informe a coordenada de ataque: \n", grade);
    sprintf(grade, "%s\n", grade);
    sprintf(grade, "%s\n\n\n", grade);
    printf("%s", grade);
}
