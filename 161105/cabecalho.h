#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define T 10

int i, j;
int grade_usr[T][T];
int grade_cpu[T][T];
int grade_usr_s = 0;
int grade_cpu_s = 0;
