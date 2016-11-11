#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <time.h>

int main(int argc, char** argv) {
    int i, y, d, seed;
    char tela[50];
    char linha[6];

    strcpy(tela, "***************");
    strcpy(linha, "-----");

    puts(tela);
    for (i = 0; i < 5; i++)
        tela[i + 6] = linha[i];
    puts(tela);
    exit(0);
}

