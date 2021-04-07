#include <unistd.h>
#include <stdio.h>

int main(){
    int fd[2];
    int pid;
    pipe(fd);
    pid = fork();
    if(pid == 0){ // hijo
        close(fd[1]); // 1 input, 0 output
        dup2(fd[0], STDIN_FILENO); // conexión, segunda posición es la salida
        execl("/usr/bin/tr","tr","' '","-", NULL);
    }
    if(pid > 0){ // padre
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO); // conexión, segunda posición es la salida
        execl("/usr/bin/cat","cat", NULL);

    }
    return 0;
}