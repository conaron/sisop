#include <stdio.h>

#include "cabecalho.h"

int preenchimento(int player, int blocos, int campo[10], int posicao, int grade[T][T]) { // preenchimento automatico do barco
    int ocupado = 0;

    if (player == 0)
        srand(((int) &campo * -1));
    else
        srand(((int) &grade * -1));

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
        campo[posicao] = 1;
    }
    return ocupado;
}

void automatico(int player, int campo[10], int grade[T][T]) {
    int blocos = 5, ocupado = 0;

    for (i = 0; i < 10; i++) {
        if (i > 5)
            blocos = 2;
        else if (i > 2)
            blocos = 3;
        else if (i > 0)
            blocos = 4;

        if (campo[i] == 0)
            ocupado = preenchimento(player, blocos, campo, i, grade);
        if (ocupado == 1) {
            automatico(player, campo, grade);
            return;
        }
    }
}

void definicao(int usr, int cpu) {
    int campo_u[10] = {0}, campo_c[10] = {0};

    srand(((int) &usr * -1));

    if (usr == 0)
        usr = (rand() % 5) + 1;
    cpu = (rand() % 5) + 1;

    if (usr == cpu) {
        definicao(usr, cpu);
        return;
    }

    automatico(0, campo_u, grade_usr);
    automatico(1, campo_c, grade_cpu);
}
