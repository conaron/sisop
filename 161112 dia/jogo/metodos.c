void executa_transacao(void *funcao, long arg) {
    pthread_t id;
    void * parametro = (void *) arg;
    int transacao = pthread_create(&id, NULL, funcao, parametro);
    if (transacao) {
        perror("pthread_create");
        exit(-1);
    }
}

void *encerramento(void *jogada) {
    long opcao = (long) jogada;
    char retorno[TT];
    if (opcao == 9999) {
        system("clear");
        tela_0(4, retorno);
        puts(retorno);
        exit(0);
    } else if (opcao == 9998) {
        sleep(1);
        system("clear");
        tela_0(3, retorno);
        puts(retorno);
        __fpurge(stdin);
        getchar();
        return;
    }
}

void menu(char retorno[TT]) {
    int opcao = 0;

    while (1) {
        if (opcao == 1)
            return;

        tela_0(opcao, retorno);
        system("clear");
        printf("%s", retorno);

        if (opcao == 4)
            exit(0);
        else if ((opcao < 1) || (opcao > 3)) scanf("%d", &opcao);
        else {
            __fpurge(stdin);
            getchar();
            opcao = 0;
        }
    }
}

void principal() {
    char grade[TT];
    menu(grade);
}

