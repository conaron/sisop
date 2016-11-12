char tela(char *tela) {
    strcpy(tela,
            "\n\n\n"
            "          * ---------------------------------------------------------------------------------------------------- *\n"
            "          |                                                                                                      |\n"
            "          |                                  * B A T A L H A    N A V A L *                                      |\n"
            "          |                                                                                                      |\n"
            "          * ---------------------------------------------------------------------------------------------------- *\n"
            "          |                                                                                                      |\n"
            "          |                                                                                                      |\n"
            "          |                                                                                                      |\n"
            "          |                                                                                                      |\n"
            "          |                                                                                                      |\n"
            "          |                                                                                                      |\n"
            "          |                                                                                                      |\n"
            "          |                                                                                                      |\n"
            "          |                                                                                                      |\n"
            "          |                                                                                                      |\n"
            "          |                                                                                                      |\n"
            "          |                                                                                                      |\n"
            "          |                                                                                                      |\n"
            "          |                                                                                                      |\n"
            "          |                                                                                                      |\n"
            "          |                                                                                                      |\n"
            "          |                                                                                                      |\n"
            "          * ---------------------------------------------------------------------------------------------------- *\n"
            );
}

char mascara(int valor) {
    if (valor == 2) return '-';
    else if (valor == 3) return 'X';
    else if (valor == 1) return '1';
    else return ' ';
}

char teste_linha(int linha, char *retorno, char *conteudo) {
    int i;
    int posicao = LINHA_T + (115 * linha);
    int margem = (105 - strlen(conteudo)) / 2;
    for (i = 0; i < strlen(conteudo); i++)
        retorno[i + posicao + margem] = (conteudo)[i];
}

char tela_jogo(char *retorno, int mapa[2][T][T]) {
    int i, j;
    int posicao = LINHA_T + 471;

    tela(retorno);
    teste_linha(0, retorno, "* J O G A D O R   1 *                           * J O G A D O R   2 *");
    teste_linha(1, retorno, " -----------------------------------------       -----------------------------------------");
    teste_linha(2, retorno, "   0   1   2   3   4   5   6   7   8   9          0   1   2   3   4   5   6   7   8   9  ");
    teste_linha(3, retorno, " -----------------------------------------       -----------------------------------------");
    teste_linha(4, retorno, "0 |   |   |   |   |   |   |   |   |   |   |    0 |   |   |   |   |   |   |   |   |   |   |");
    teste_linha(5, retorno, "1 |   |   |   |   |   |   |   |   |   |   |    1 |   |   |   |   |   |   |   |   |   |   |");
    teste_linha(6, retorno, "2 |   |   |   |   |   |   |   |   |   |   |    2 |   |   |   |   |   |   |   |   |   |   |");
    teste_linha(7, retorno, "3 |   |   |   |   |   |   |   |   |   |   |    3 |   |   |   |   |   |   |   |   |   |   |");
    teste_linha(8, retorno, "4 |   |   |   |   |   |   |   |   |   |   |    4 |   |   |   |   |   |   |   |   |   |   |");
    teste_linha(9, retorno, "5 |   |   |   |   |   |   |   |   |   |   |    5 |   |   |   |   |   |   |   |   |   |   |");
    teste_linha(10, retorno, "6 |   |   |   |   |   |   |   |   |   |   |    6 |   |   |   |   |   |   |   |   |   |   |");
    teste_linha(11, retorno, "7 |   |   |   |   |   |   |   |   |   |   |    7 |   |   |   |   |   |   |   |   |   |   |");
    teste_linha(12, retorno, "8 |   |   |   |   |   |   |   |   |   |   |    8 |   |   |   |   |   |   |   |   |   |   |");
    teste_linha(13, retorno, "9 |   |   |   |   |   |   |   |   |   |   |    9 |   |   |   |   |   |   |   |   |   |   |");
    teste_linha(14, retorno, " -----------------------------------------       -----------------------------------------");

    for (i = 0; i < T; i++) {
        for (j = 0; j < T; j++) {
            retorno[posicao + j] = mascara(mapa[0][i][j]);
            retorno[posicao + j + 47] = mascara(mapa[1][i][j]);
            posicao = posicao + 3;
        }
        posicao = posicao + 85;
    }

    strcat(retorno, "\n");
    strcat(retorno, "          Opcoes:\n");
    strcat(retorno, "             S: Sair do jogo\n");
    strcat(retorno, "             A: Ajuda\n");
    strcat(retorno, "\n");
}

char tela_0(int opcao, char *retorno) {
    tela(retorno);
    switch (opcao) {
        case 2:
            teste_linha(0, retorno, "* Idealizadores *");
            teste_linha(3, retorno, "Curso: Sistemas para Internet           ");
            teste_linha(4, retorno, "Semestre: 4                             ");
            teste_linha(5, retorno, "Prof.: Thais Viegas                     ");
            teste_linha(8, retorno, "Matricula     Nome                      ");
            teste_linha(9, retorno, "006697-4      Airton da Rocha Bernardoni");
            teste_linha(10, retorno, "007715-1      Gabriel Carneiro Minatto  ");
            teste_linha(14, retorno, "* Pressione Enter para retornar *");
            break;
        case 3:
            teste_linha(0, retorno, "* Ajuda *");
            teste_linha(1, retorno, "Como jogar:                                                                                 ");
            teste_linha(2, retorno, "     Na sua vez de jogar, informe as coordenadas conforme o bloco que deseja atacar no campo");
            teste_linha(3, retorno, "        adversario, Sempre linha e coluna. Ex: 21 (veja o quadro abaixo)                    ");
            teste_linha(5, retorno, "Vitoria:                                                                   -----------------");
            teste_linha(6, retorno, "     O jogo e composto por 10 barcos.                                        0   1   2   3  ");
            teste_linha(7, retorno, "        1 Barco de 5 blocos;                                               -----------------");
            teste_linha(8, retorno, "        2 Barcos de 4 blocos;                                            0 |   |   |   |   |");
            teste_linha(9, retorno, "        3 Barcos de 3 blocos;                                            1 |   |   |   |   |");
            teste_linha(10, retorno, "        4 Barcos de 2 blocos;                                            2 |   | X |   |   |");
            teste_linha(11, retorno, "     Vence quem atingir primeiro todos os barcos                         3 |   |   |   |   |");
            teste_linha(12, retorno, "        do adversario (30 pontos) primeiro!                                -----------------");
            teste_linha(14, retorno, "* Pressione Enter para retornar *");
            break;
        case 4:
            teste_linha(0, retorno, "* Adeus! *");
            teste_linha(7, retorno, "Muito obrigado por jogar nosso jogo!");
            break;
        default:
            teste_linha(0, retorno, "* Menu de Opcoes *");
            teste_linha(6, retorno, "1 - Jogo           ");
            teste_linha(7, retorno, "2 - Desenvolvedores");
            teste_linha(8, retorno, "3 - Ajuda          ");
            teste_linha(9, retorno, "4 - Sair           ");
            strcat(retorno, "\nInforme a opcao desejada: ");
            break;
    }
}

char conversao(int celula) { // troca o valor do bloco para impressão (cria máscara)
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

char *linha(char *borda, char *padrao) { // preenche uma linha com um padrão (tipo repeticao)
    int i, margem = 10;
    char linha[150] = "";
    for (i = 0; i < margem; i++) strcat(linha, " ");
    strcat(linha, borda);
    strcat(linha, " ");
    for (i = 0; i < 100; i++) strcat(linha, padrao);
    strcat(linha, " ");
    strcat(linha, borda);
    strcat(linha, "\n");
    return (linha);
}

char *centralizar(char *campo) { // centraliza a linha dentro da grade
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

void acao() {
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
        if (pontos[jogador] == 3) {
            printf("Parabens jogador %d\n\n", jogador + 1);
            exit(0);
        }

    }
    if (jogador == 0)
        jogador++;
    else
        jogador--;
    acao();
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
    strcat(rede, centralizar("007715-1      Gabriel Carneiro Minatto  "));
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

void abertura(int borda) {
    int i;
    int opcao = 999;
    char margem[borda + 5];
    char linha_s[150];
    char rede[5000];
    char *grade;

    for (i == 0; i < borda; i++)
        margem[i] = ' ';

    if (borda > 0) {
        strcpy(rede, "\n\n\n");

        strcat(rede, linha("*", "-"));

        strcpy(linha_s, "   (_    _)                     0_,-.__                             ");
        strcat(linha_s, margem);
        strcat(rede, centralizar(linha_s));
        strcpy(linha_s, "      (_  )_                     |_.-._/                            ");
        strcat(linha_s, margem);
        strcat(rede, centralizar(linha_s));
        strcpy(linha_s, "       (    )                    |_--..\\                           ");
        strcat(linha_s, margem);
        strcat(rede, centralizar(linha_s));
        strcpy(linha_s, "        (__)                     |__--_/                            ");
        strcat(linha_s, margem);
        strcat(rede, centralizar(linha_s));
        strcpy(linha_s, "     |''   ``\\                   |                                 ");
        strcat(linha_s, margem);
        strcat(rede, centralizar(linha_s));
        strcpy(linha_s, "     |        \\                  |      /b.                        ");
        strcat(linha_s, margem);
        strcat(rede, centralizar(linha_s));
        strcpy(linha_s, "     |         \\  ,,,---===?A`\\  |  ,==y'                         ");
        strcat(linha_s, margem);
        strcat(rede, centralizar(linha_s));
        strcpy(linha_s, "   ___,,,,,---==''\\        |M] \\ | ;|\\ |>                        ");
        strcat(linha_s, margem);
        strcat(rede, centralizar(linha_s));
        strcpy(linha_s, "           _   _   \\   ___,|H,,---==''''bno,                       ");
        strcat(linha_s, margem);
        strcat(rede, centralizar(linha_s));
        strcpy(linha_s, "    o  O  (_) (_)   \\ /          _     AWAW/                       ");
        strcat(linha_s, margem);
        strcat(rede, centralizar(linha_s));
        strcpy(linha_s, "                     /         _(+)_  dMM/                          ");
        strcat(linha_s, margem);
        strcat(rede, centralizar(linha_s));
        strcpy(linha_s, "      \\@_,,,,,,---=='   \\      \\\\|//  MW/                       ");
        strcat(linha_s, margem);
        strcat(rede, centralizar(linha_s));
        strcpy(linha_s, "--'''''                         ===  d/                             ");
        strcat(linha_s, margem);
        strcat(rede, centralizar(linha_s));
        strcpy(linha_s, "                                    //                              ");
        strcat(linha_s, margem);
        strcat(rede, centralizar(linha_s));
        strcpy(linha_s, "                                    ,'__________________________    ");
        strcat(linha_s, margem);
        strcat(rede, centralizar(linha_s));
        strcpy(linha_s, "   \\    \\    \\     \\               ,/~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        strcat(linha_s, margem);
        strcat(rede, centralizar(linha_s));
        strcpy(linha_s, "                         _____    ,'  ~~~   .-''-.~~~~~~  .-''-.    ");
        strcat(linha_s, margem);
        strcat(rede, centralizar(linha_s));
        strcpy(linha_s, "      .-''-.           ///==---   /`-._ ..-'      -.__..-'          ");
        strcat(linha_s, margem);
        strcat(rede, centralizar(linha_s));
        strcpy(linha_s, "            `-.__..-' =====\\\\\\\\\\\\ V/  .---\\.                 ");
        strcat(linha_s, margem);
        strcat(rede, centralizar(linha_s));
        strcpy(linha_s, "                      ~~~~~~~~~~~~, _',--/_.\\  .-''-.              ");
        strcat(linha_s, margem);
        strcat(rede, centralizar(linha_s));
        strcpy(linha_s, "                            .-''-.___` --  \\|         -.__..-      ");
        strcat(linha_s, margem);
        strcat(rede, centralizar(linha_s));

        strcat(rede, linha("*", "-"));

        system("clear");
        printf("%s", rede);
        usleep(10000);
        abertura(borda - 1);
    }

    for (i = 0; i < 5; i++) {


        usleep(10000);
        strcpy(rede, "\n\n\n");
        strcat(rede, linha("*", "-"));
        strcat(rede, centralizar(""));
        strcat(rede, centralizar(""));
        strcat(rede, centralizar(""));
        strcat(rede, centralizar(""));
        strcat(rede, centralizar(""));
        strcat(rede, centralizar("****#****"));
        strcat(rede, centralizar("***#@##*#@#****"));
        strcat(rede, centralizar("*@**@@@*##**#*#**#*"));
        strcat(rede, centralizar("**@@*#**#@*#@****#***"));
        strcat(rede, centralizar("****@*@***#****@**@@*"));
        strcat(rede, centralizar("*******@***@@***#****#*"));
        strcat(rede, centralizar("*#***#*##@****##@@@**"));
        strcat(rede, centralizar("**#@###****@*********"));
        strcat(rede, centralizar("*****@**@*@*****@**"));
        strcat(rede, centralizar("************@**"));
        strcat(rede, centralizar("****#****"));
        strcat(rede, centralizar(""));
        strcat(rede, centralizar(""));
        strcat(rede, centralizar(""));
        strcat(rede, centralizar(""));
        strcat(rede, centralizar(""));
        strcat(rede, linha("*", "-"));
        system("clear");
        printf("%s", rede);

        usleep(10000);
        strcpy(rede, "\n\n\n");
        strcat(rede, linha("*", "-"));
        strcat(rede, centralizar("****   **#**@ #**#*#   ****"));
        strcat(rede, centralizar("***  **  **##** *@@*@*  **  ***"));
        strcat(rede, centralizar("**  *  @@   *@*#* ***@*   *#  *  **"));
        strcat(rede, centralizar("*** #  *  *#  *@#** ***@*  **  @  * *@*"));
        strcat(rede, centralizar("** *  * ** *@  ****@ @****  ** #* *  * **"));
        strcat(rede, centralizar("** * @* * ** *@  #### *#**  ** ** * @* * **"));
        strcat(rede, centralizar("*# * # ** * #* *  **** ****  @ ** * ** * * #*"));
        strcat(rede, centralizar("** * *# * @ * #  @  @*@ *#*  *  @ # # * @* * **"));
        strcat(rede, centralizar("*# * * * * # * @* * **# *#* * ** * * * * * # **"));
        strcat(rede, centralizar("** # * * @ * * # * # ** @* * * * * * # @ @ * **"));
        strcat(rede, centralizar("*# * * * * * * * * # * * * * * * @ @ * * * * * **"));
        strcat(rede, centralizar("*# * @ * @ * @ * * * ** *@ * * # * * * * * @ @*"));
        strcat(rede, centralizar("*# # @ * * # * *@ * *** @#@ @ ** * @ @ * * # **"));
        strcat(rede, centralizar("*# * ** * * * @  @  **@ ***  *  @ * * * @* * #*"));
        strcat(rede, centralizar("** * * ** * #@ *  #*** **##  * #* * #@ * * @*"));
        strcat(rede, centralizar("*# * *@ * @@ *#  **** @***  ** ** * #* * #*"));
        strcat(rede, centralizar("*# *  * *@ **  @**@* *@#**  ** ** *  * @*"));
        strcat(rede, centralizar("*#* @  *  @@  **##* ****@  **  #  * @**"));
        strcat(rede, centralizar("**  @  #*   @*@#* @*@*#   @#  *  **"));
        strcat(rede, centralizar("*#*  @*  @#*@*# **#*@#  **  ***"));
        strcat(rede, centralizar("****   *##**# #***@*   @***"));
        strcat(rede, linha("*", "-"));
        system("clear");
        printf("%s", rede);

        usleep(10000);
        strcpy(rede, "\n\n\n");
        strcat(rede, linha("*", "-"));
        strcat(rede, centralizar("* -- - -- -- --  --   ------ ------   --  -- -- -- - -- *"));
        strcat(rede, centralizar("** - -  - -- -- --  --  ------ ------  --  -- -- -- -  - - **"));
        strcat(rede, centralizar("*  - - -- - -- -  -  --   ----- -----   --  -  - -- - -- - -  *"));
        strcat(rede, centralizar("** - - - -- - -- -  -  --  ----- -----  --  -  - -- - -- - - - **"));
        strcat(rede, centralizar("* - - - -  - - -  - -- --  ----- -----  -- -- -  - - -  - - - - *"));
        strcat(rede, centralizar("* - - - -  - - - -- - -- --  ---- ----  -- -- - -- - - -  - - - - *"));
        strcat(rede, centralizar("* -- - - - - - - - -- - -- -  ---- ----  - -- - -- - - - - - - - -- *"));
        strcat(rede, centralizar("* - - - - - - - -- - - - -  -  --- ---  -  - - - - -- - - - - - - - *"));
        strcat(rede, centralizar("* - - - - - - - - - - - - -- - --- --- - -- - - - - - - - - - - - - *"));
        strcat(rede, centralizar("* - - - - - - - - - - - - - - - -- -- - - - - - - - - - - - - - - - *"));
        strcat(rede, centralizar("* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *"));
        strcat(rede, centralizar("* - - - - - - - - - - - - - - - -- -- - - - - - - - - - - - - - - - *"));
        strcat(rede, centralizar("* - - - - - - - - - - - - -- - --- --- - -- - - - - - - - - - - - - *"));
        strcat(rede, centralizar("* - - - - - - - -- - - - -  -  --- ---  -  - - - - -- - - - - - - - *"));
        strcat(rede, centralizar("* -- - - - - - - - -- - -- -  ---- ----  - -- - -- - - - - - - - -- *"));
        strcat(rede, centralizar("* - - - -  - - - -- - -- --  ---- ----  -- -- - -- - - -  - - - - *"));
        strcat(rede, centralizar("* - - - -  - - -  - -- --  ----- -----  -- -- -  - - -  - - - - *"));
        strcat(rede, centralizar("** - - - -- - -- -  -  --  ----- -----  --  -  - -- - -- - - - **"));
        strcat(rede, centralizar("*  - - -- - -- -  -  --   ----- -----   --  -  - -- - -- - -  *"));
        strcat(rede, centralizar("** - -  - -- -- --  --  ------ ------  --  -- -- -- -  - - **"));
        strcat(rede, centralizar("* -- - -- -- --  --   ------ ------   --  -- -- -- - -- *"));
        strcat(rede, linha("*", "-"));
        system("clear");
        printf("%s", rede);
    }

    while (opcao > 4) {
        strcpy(rede, centralizar("* Menu de Opcoes *"));
        strcat(rede, linha("|", " "));
        strcat(rede, linha("|", " "));
        strcat(rede, linha("|", " "));
        strcat(rede, linha("|", " "));
        strcat(rede, linha("|", " "));
        strcat(rede, centralizar("1 - Jogo"));
        strcat(rede, centralizar("2 - Desenvolvedores"));
        strcat(rede, centralizar("3 - Ajuda"));
        strcat(rede, centralizar("4 - Sair"));
        strcat(rede, linha("|", " "));
        strcat(rede, linha("|", " "));
        strcat(rede, linha("|", " "));
        strcat(rede, linha("|", " "));
        strcat(rede, linha("|", " "));
        grade = gaiola(rede);

        sprintf(grade, "%sInforme a opcao desejada: ", grade);

        system("clear");
        printf("%s", grade);
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                acao();
                break;
            case 2:
                staff();
                break;
            case 3:
                ajuda();
                break;
            case 4:
                exit(0);
                break;
        }
    }
}

