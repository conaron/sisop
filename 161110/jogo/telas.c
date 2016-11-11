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

char *linha(char *borda, char *padrao) {
    int i;
    char linha[150] = "";
    for (i = 0; i < 10; i++) strcat(linha, " ");
    strcat(linha, borda);
    strcat(linha, " ");
    for (i = 0; i < 100; i++) strcat(linha, padrao);
    strcat(linha, " ");
    strcat(linha, borda);
    strcat(linha, "\n");
    return (linha);
}

char *centralizar(char *campo) {
    int i;
    int margem = (100 - strlen(campo)) / 2;
    char linha[150] = "";
    for (i = 0; i < 10; i++) strcat(linha, " ");
    strcat(linha, "| ");
    for (i = 0; i < margem; i++) strcat(linha, " ");
    strcat(linha, campo);
    for (i = 0; i < 100 - strlen(campo) - margem; i++) strcat(linha, " ");
    strcat(linha, " |\n");
    return (linha);
}

char *gaiola(char entrada[3000]) {
    char grade[5000] = "\n\n\n";
    strcat(grade, linha("*", "-"));
    strcat(grade, linha("|", " "));
    strcat(grade, centralizar("* B A T A L H A   N A V A L *"));
    strcat(grade, linha("|", " "));
    strcat(grade, linha("*", "-"));
    strcat(grade, linha("|", " "));
    strcat(grade, entrada);
    strcat(grade, linha("|", " "));
    strcat(grade, linha("*", "-"));
    strcat(grade, "\n\n");
    return (grade);
}

void jogo() {
    int i, j;
    int x, y;
    int jogada = 999;
    char *grade;
    char rede[5000] = "";
    char linha[200];

    strcat(rede, centralizar("            * J O G A D O R   1 *                           * J O G A D O R   2 *          "));
    strcat(rede, centralizar("  -----------------------------------------       -----------------------------------------"));
    strcat(rede, centralizar("    0   1   2   3   4   5   6   7   8   9           0   1   2   3   4   5   6   7   8   9  "));
    strcat(rede, centralizar("  -----------------------------------------       -----------------------------------------"));

    for (i = 0; i < 10; i++) {
        strcpy(linha, "");
        sprintf(linha, "%s%d |", linha, i);
        for (j = 0; j < T; j++) sprintf(linha, "%s %c |", linha, conversao(grade_usr[i][j]));
        strcat(linha, "    ");
        sprintf(linha, "%s%d |", linha, i);
        for (j = 0; j < T; j++) sprintf(linha, "%s %c |", linha, conversao(grade_cpu[i][j]));
        strcat(rede, centralizar(linha));
    }

    strcat(rede, centralizar("  -----------------------------------------       -----------------------------------------"));
    grade = gaiola(rede);

    sprintf(grade, "%sJogador %d (%d pontos) - Informe a coordenada de ataque: ", grade, jogador + 1, pontos[jogador]);
    system("clear");
    printf("%s", grade);
    scanf("%d", &jogada);

    if ((jogada < 0) || jogada > 99) {
        printf("%s", "Jogada Invalida\n");
        __fpurge(stdin);
        getchar();
    } else {
        x = jogada / 10;
        y = jogada - x * 10;
        if ((jogador == 0)&&(grade_cpu[x][y] < 2)) {
            if (grade_cpu[x][y] == 1)
                pontos[jogador]++;
            grade_cpu[x][y] = grade_cpu[x][y] + 2;
        } else if ((jogador == 1)&&(grade_usr[x][y] < 2)) {
            if (grade_usr[x][y] == 1)
                pontos[jogador]++;
            grade_usr[x][y] = grade_usr[x][y] + 2;
        }
        if (pontos[jogador] == 30) {
            printf("Parabens jogador %d\n\n", jogador + 1);
            exit(0);
        }

    }
    if (jogador == 0)
        jogador++;
    else
        jogador--;
    jogo();
}

void ajuda() {
    char *grade;
    char rede[5000] = "";

    strcat(rede, centralizar("* A J U D A *"));
    strcat(rede, centralizar("Como jogar:                                                                                 "));
    strcat(rede, centralizar("     Na sua vez de jogar, informe as coordenadas conforme o bloco que deseja atacar no campo"));
    strcat(rede, centralizar("        adversario, Sempre linha e coluna. Ex: 21 (veja o quadro abaixo)                    "));
    strcat(rede, linha("|", " "));
    strcat(rede, centralizar("Vitoria:                                                                   -----------------"));
    strcat(rede, centralizar("     O jogo e composto por 10 barcos.                                        0   1   2   3  "));
    strcat(rede, centralizar("        1 Barco de 5 blocos;                                               -----------------"));
    strcat(rede, centralizar("        2 Barcos de 4 blocos;                                            0 |   |   |   |   |"));
    strcat(rede, centralizar("        3 Barcos de 3 blocos;                                            1 |   |   |   |   |"));
    strcat(rede, centralizar("        4 Barcos de 2 blocos;                                            2 |   | X |   |   |"));
    strcat(rede, centralizar("     Vence quem atingir primeiro todos os barcos                         3 |   |   |   |   |"));
    strcat(rede, centralizar("        do adversario (30 pontos) primeiro!                                -----------------"));
    strcat(rede, linha("|", " "));
    strcat(rede, centralizar("* Pressione Enter para retornar *"));
    grade = gaiola(rede);

    system("clear");
    printf("%s", grade);
    __fpurge(stdin);
    getchar();
}

void abertura(int borda) {
    char margem[20] = "";
    if (borda < 16) {

        char grade[4000] = "";
        strcpy(grade, "\n\n\n");
        strcpy(linha, "");

        strcat(grade, linha("*", "-"));
        strcat(grade, centralizar("   (_    _)                     0_,-.__                             "));
        strcat(grade, centralizar("      (_  )_                     |_.-._/                            "));
        strcat(grade, centralizar("       (    )                    |_--..\\                           "));
        strcat(grade, centralizar("        (__)                     |__--_/                            "));
        strcat(grade, centralizar("     |''   ``\\                   |                                 "));
        strcat(grade, centralizar("     |        \\                  |      /b.                        "));
        strcat(grade, centralizar("     |         \\  ,,,---===?A`\\  |  ,==y'                         "));
        strcat(grade, centralizar("   ___,,,,,---==''\\        |M] \\ | ;|\\ |>                        "));
        strcat(grade, centralizar("           _   _   \\   ___,|H,,---==''''bno,                       "));
        strcat(grade, centralizar("    o  O  (_) (_)   \\ /          _     AWAW/                       "));
        strcat(grade, centralizar("                     /         _(+)_  dMM/                          "));
        strcat(grade, centralizar("      \\@_,,,,,,---=='   \\      \\\\|//  MW/                       "));
        strcat(grade, centralizar("--'''''                         ===  d/                             "));
        strcat(grade, centralizar("                                    //                              "));
        strcat(grade, centralizar("                                    ,'__________________________    "));
        strcat(grade, centralizar("   \\    \\    \\     \\               ,/~~~~~~~~~~~~~~~~~~~~~~~~~~~"));
        strcat(grade, centralizar("                         _____    ,'  ~~~   .-''-.~~~~~~  .-''-.    "));
        strcat(grade, centralizar("      .-''-.           ///==---   /`-._ ..-'      -.__..-'          "));
        strcat(grade, centralizar("            `-.__..-' =====\\\\\\\\\\\\ V/  .---\\.                 "));
        strcat(grade, centralizar("                      ~~~~~~~~~~~~, _',--/_.\\  .-''-.              "));
        strcat(grade, centralizar("                            .-''-.___` --  \\|         -.__..-      "));
        strcat(grade, linha("*", "-"));

        system("clear");
        printf("%s", grade);
        //        usleep("50000");
        abertura(borda - 1);
    }
    //    __fpurge(stdin);
    //    getchar();
}

void staff() {
    char *grade;
    char rede[5000] = "";

    strcat(rede, centralizar("* I D E A L I Z A D O R E S *"));
    strcat(rede, linha("|", " "));
    strcat(rede, linha("|", " "));
    strcat(rede, centralizar("Curso: Sistemas para Internet           "));
    strcat(rede, centralizar("Semestre: 4                             "));
    strcat(rede, centralizar("Prof.: Thais Viegas                     "));
    strcat(rede, linha("|", " "));
    strcat(rede, linha("|", " "));
    strcat(rede, centralizar("Matricula     Nome                      "));
    strcat(rede, centralizar("006697-4      Airton da Rocha Bernardoni"));
    strcat(rede, centralizar("000000-0      Gabriel Carneiro Minatto  "));
    strcat(rede, linha("|", " "));
    strcat(rede, linha("|", " "));
    strcat(rede, linha("|", " "));
    strcat(rede, centralizar("* Pressione Enter para retornar *"));
    grade = gaiola(rede);

    system("clear");
    printf("%s", grade);
    __fpurge(stdin);
    getchar();
}