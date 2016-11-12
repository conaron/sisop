#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include<ctype.h>

#define T         10 // dimensão (lado) do tabuleiro
#define TT      2700 // quantidade de caracteres da tela
#define LINHA_T  703 // Linha do cabeçalho

int grade_usr[T][T] = {0};
int grade_cpu[T][T] = {0};
int grade_s[2][T][T];
int pontos[2] = {0};
int jogador = 0;

#include "situacoes.c"
int preenchimento(int blocos, int barco[10], int posicao, int grade[T][T]);
void construcao(int barco[10], int grade[T][T]);

#include "telas.c"
char tela(char tela[2700]);
char conversao(int celula);
char *linha(char *borda, char *padrao);
char *centralizar(char *campo);
char *gaiola(char entrada[3000]);
void acao();
void ajuda();
void staff();
void abertura(int borda);

#include "metodos.c"
void executa_transacao(void *funcao, long arg);
void principal();
