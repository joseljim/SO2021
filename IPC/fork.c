#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

int ready;
int pid_hijo_termino;

void signalHandler(int sig){
	ready = 0;
	pid_hijo_termino = wait(NULL);
    printf("Mi hijon terminó %d\n", pid_hijo_termino);
	ready = 1;
}

int main(){
    signal(17, signalHandler);
    int pid = fork();
    
    if (pid == 0){
        // proceso hijo
        printf("Soy el proceso hijo\n");
    } else {
        printf("Soy el proceso padre y mi hijo es %d\n", pid);
        //pid_hijo_termino = wait(NULL);
        while(1) {
            printf("Trabajando\n");
            sleep(1);

            if(ready == 1){
			break;
		    }
        }

    }

    printf("Terminando\n");
    return 0;
}