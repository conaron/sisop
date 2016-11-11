#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <time.h>

#define T 10

int i, j;
int grade_usr[T][T];
int grade_cpu[T][T];
int pontos_usr = 0;
int pontos_cpu = 0;
int jogada = 0;