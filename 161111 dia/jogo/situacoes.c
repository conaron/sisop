int preenchimento(int blocos, int barco[10], int posicao, int grade[T][T]) { // preenchimento automatico do barco
    int i;
    int ocupado = 0;

    int d = rand() % 2;
    int x = rand() % (10 - blocos);
    int y = rand() % (10 - blocos);

    for (i = 0; i < blocos; i++) {
        if (d == 0) {
            if (grade[x][y + i] == 1)
                ocupado = 1;
        } else {
            if (grade[x + i][y] == 1)
                ocupado = 1;
        }
    }
    if (ocupado == 0) {
        for (i = 0; i < blocos; i++) {
            if (d == 0)
                grade[x][y + i] = 1;
            else
                grade[x + i][y] = 1;
        }
        barco[posicao] = 1;
    }
    return ocupado;
}

void construcao(int barco[10], int grade[T][T]) { // distribuicao dos barcos na grade
    int i;
    int blocos = 5, ocupado = 0;

    for (i = 0; i < 10; i++) {
        if (i > 5)
            blocos = 2; // seta 4 barcos com 2 blocos
        else if (i > 2)
            blocos = 3; // seta 3 barcos com 3 blocos
        else if (i > 0)
            blocos = 4; // seta 2 barcos com 4 blocos

        if (barco[i] == 0) // testa se a vaga esta aberta
            ocupado = preenchimento(blocos, barco, i, grade);
        if (ocupado == 1) {
            construcao(barco, grade);
            return;
        }
    }
}

void teste(int grade[T][T]) {
    int i;
    for (i = 0; i < T; i++) grade[0][i] = 1;
}
