#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(int argvnum, char **argv){
    char *path1 = argv[1];
    char *path2 = argv[2];
    struct stat sb;
    if(stat(path1, &sb) == -1){
        printf("Error el archivo no existe \n");
        return -1;
    }
    if(S_ISDIR(sb.st_mode)){
        printf("Es un directorio \n");
    } 

    if(S_ISREG(sb.st_mode)){ 
        //printf("Es un archivo normal \n");

        if(stat(path2, &sb) == -1) { // No se dió segundo argumento
            link(path1, path2);
            unlink(path1);
        }
        else if(S_ISDIR(sb.st_mode)) { // El segundo argumento es un directorio
            printf("%s\n", strcat(path2,path1));
            link(path1, path2);
            unlink(path1);
        }
        else if(S_ISREG(sb.st_mode)) { // Segundo argumento ya existe
            printf("Error, %s ya existe \n", path2);
        }

    }  
    return 1;
}