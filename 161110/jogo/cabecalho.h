#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

#define T 10

int grade_usr[T][T];
int grade_cpu[T][T];
int pontos[2] = {0};
int pontos_usr = 0;
int pontos_cpu = 0;
int jogador = 0;

#include "situacoes.c"
#include "telas.c"
#include "metodos.c"

