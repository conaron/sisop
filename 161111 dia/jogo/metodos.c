void executa_transacao(void *funcao, long arg) {
    pthread_t id;
    void * parametro = (void *) arg;
    int transacao = pthread_create(&id, NULL, funcao, parametro);
    if (transacao) {
        perror("pthread_create");
        exit(-1);
    }
}

void tela() {
    abertura(25);
}