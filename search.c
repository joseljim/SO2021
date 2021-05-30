#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

int main(int argc, char **argv){
    char *filename = argv[1];
    char *parameter = argv[2];
    char *val = argv[3];
    FILE *forigen;
    forigen = fopen(filename,"rb");
    char buffer;
    STUDENT newstudent;

    while(fread(&newstudent,sizeof(newstudent),1,forigen)){
        if(strcmp(parameter, "name") == 0){
            if(strcmp(val, newstudent.name) == 0){
                printf("%s %s %d %d \n", newstudent.name, newstudent.lastname, newstudent.id, newstudent.semestre);
            } 
        } else if(strcmp(parameter, "lastname") == 0){
            if(strcmp(val, newstudent.lastname) == 0){
                printf("%s %s %d %d \n", newstudent.name, newstudent.lastname, newstudent.id, newstudent.semestre);
            } 
        } else if(strcmp(parameter, "id") == 0){
            if(newstudent.id == atoi(val)){
                printf("%s %s %d %d \n", newstudent.name, newstudent.lastname, newstudent.id, newstudent.semestre);
            } 
        } else if(strcmp(parameter, "semestre") == 0){
            if(newstudent.semestre == atoi(val)){
                printf("%s %s %d %d \n", newstudent.name, newstudent.lastname, newstudent.id, newstudent.semestre);
            }
        } else {
            printf("Error: no se encontró el atributo %s \n", parameter);
            break;
        }
    }
    fclose(forigen);

    return 0;
}