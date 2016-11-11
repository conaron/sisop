#include "cabecalho.h"

void situacao_1(int grade[T][T]) {
    for (i = 0; i < 5; i++)
        grade[2][i + 1] = 1;
    for (i = 0; i < 4; i++)
        grade[4][i] =
            grade[i + 5][7] = 1;
    for (i = 0; i < 3; i++)
        grade[0][i] =
            grade[6][i + 1] =
            grade[i + 2][9] = 1;
    for (i = 0; i < 2; i++)
        grade[i + 8 ][0] =
            grade[i + 8][4] =
            grade[i][7] =
            grade[i + 8][9] = 1;
}

void situacao_2(int grade[T][T]) {
    for (i = 0; i < 5; i++)
        grade[i + 3][9] = 1;
    for (i = 0; i < 4; i++)
        grade[0][i + 4] =
            grade[i + 5][4] = 1;
    for (i = 0; i < 3; i++)
        grade[i + 2][1] =
            grade[i + 6][1] =
            grade[i + 3][6] = 1;
    for (i = 0; i < 2; i++)
        grade[i][2] =
            grade[i + 8][8] =
            grade[1][i + 8] =
            grade[2][i + 4] = 1;
}

void situacao_3(int grade[T][T]) {
    for (i = 0; i < 5; i++)
        grade[7][i + 4] = 1;
    for (i = 0; i < 4; i++)
        grade[i + 5][0] =
            grade[i][2] = 1;
    for (i = 0; i < 3; i++)
        grade[5][i + 5] =
            grade[9][i + 6] =
            grade[i + 6][2] = 1;
    for (i = 0; i < 2; i++)
        grade[1][i + 4] =
            grade[2][i + 6] =
            grade[i][0] =
            grade[i + 1][9] = 1;
}

void situacao_4(int grade[T][T]) {
    for (i = 0; i < 5; i++)
        grade[i + 5][2] = 1;
    for (i = 0; i < 4; i++)
        grade[2][i + 5] =
            grade[i + 6][0] = 1;
    for (i = 0; i < 3; i++)
        grade[0][i + 6] =
            grade[i][1] =
            grade[i + 7][8] = 1;
    for (i = 0; i < 2; i++)
        grade[6][i + 4] =
            grade[8][i + 5] =
            grade[i + 3][4] =
            grade[i + 5][7] = 1;
}

void situacao_5(int grade[T][T]) {
    for (i = 0; i < 5; i++)
        grade[i + 1][6] = 1;
    for (i = 0; i < 4; i++)
        grade[i + 5][2] =
            grade[i][9] = 1;
    for (i = 0; i < 3; i++)
        grade[i + 1][1] =
            grade[i + 1][3] =
            grade[i + 7][9] = 1;
    for (i = 0; i < 2; i++)
        grade[0][i + 4] =
            grade[5][i + 8] =
            grade[9][i + 3] =
            grade[9][i + 6] = 1;
}

void definicao() {
    srand(time(NULL));
    if (grade_usr_s == 0)
        grade_usr_s = (rand() % 6) + 1;
    grade_cpu_s = (rand() % 6) + 1;

    if ((grade_usr_s == grade_cpu_s))
        definicao();

    if (grade_usr_s == 1)
        situacao_1(grade_usr);
    else if (grade_usr_s == 2)
        situacao_2(grade_usr);
    else if (grade_usr_s == 3)
        situacao_3(grade_usr);
    else if (grade_usr_s == 4)
        situacao_4(grade_usr);
    else if (grade_usr_s == 5)
        situacao_5(grade_usr);

    if (grade_cpu_s == 1)
        situacao_1(grade_cpu);
    else if (grade_cpu_s == 2)
        situacao_2(grade_cpu);
    else if (grade_cpu_s == 3)
        situacao_3(grade_cpu);
    else if (grade_cpu_s == 4)
        situacao_4(grade_cpu);
    else if (grade_cpu_s == 5)
        situacao_5(grade_cpu);

}
