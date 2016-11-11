#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <time.h>

int main(int argc, char** argv) {
	int x,y,d,seed;

	time_t temporizador;
	time(&temporizador);
	
	printf("%d\n", (int) temporizador);
	
	// struct tm *local;
	// time_t t;
	// t= time(NULL);
	// local=localtime(&t);

	// seed = local->tm_sec * local->tm_min;

	// while(1){
		// y = seed % 100/10;
		// x = seed % 10;
		// d = (x*3) % 2;
		
		// printf("%d - %d - %d - %d\n", seed, x, y,d);
		// // sleep(1);
		
		// seed++;
	// }
	
		
	exit(0);
}

