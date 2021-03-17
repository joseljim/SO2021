#include <signal.h>
#include <stdio.h>
#include <unistd.h>

int ready;

void signalHandler(int sig){
	ready = 0;
	printf("Recibí señal %d\n", sig);
	ready = 1;
}

int main(){
	
	signal(2, signalHandler); // Cuando signal recibe un 15 ejecuta signalHandler
	signal(15, signalHandler); 
	
	while(1){
		printf("Trabajando ... \n");
		sleep(1);
		
		if(ready == 1){
			break;
		}
	}
	printf("Ya voy a terminar \n");
	return 0;
}