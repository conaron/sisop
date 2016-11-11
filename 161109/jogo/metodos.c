#include "telas.c"

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

void tela() {
    abertura();
    sleep(1);
    ajuda();
    sleep(1);
    staff();
    sleep(1);
    jogo();
}