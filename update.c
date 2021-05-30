#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

int main(int argc, char **argv){
    char *filename = argv[1];
    char *parameter = argv[2];
    char *val = argv[3];
    char *new_val = argv[4];
    FILE *forigen;
    forigen = fopen(filename,"r+"); // r+: leer, escribir y modificar el contenido del archivo
    STUDENT newstudent;

    while(fread(&newstudent,sizeof(newstudent),1,forigen)){
        if(strcmp(parameter, "name") == 0){
            if(strcmp(val, newstudent.name) == 0){
                strcpy(newstudent.name, new_val);
                fseek(forigen, -1 * sizeof(newstudent), SEEK_CUR);
                fwrite(&newstudent,sizeof(newstudent),1,forigen);
            } 
        } else if(strcmp(parameter, "lastname") == 0){
            if(strcmp(val, newstudent.lastname) == 0){
                strcpy(newstudent.lastname, new_val);
                fseek(forigen, -1 * sizeof(newstudent), SEEK_CUR);
                fwrite(&newstudent,sizeof(newstudent),1,forigen);
            } 
        } else if(strcmp(parameter, "id") == 0){
            if(newstudent.id == atoi(val)){
                newstudent.id = atoi(new_val);
                fseek(forigen, -1 * sizeof(newstudent), SEEK_CUR);
                fwrite(&newstudent,sizeof(newstudent),1,forigen);
            } 
        } else if(strcmp(parameter, "semestre") == 0){
            if(newstudent.semestre == atoi(val)){
                newstudent.semestre = atoi(new_val);
                fseek(forigen, -1 * sizeof(newstudent), SEEK_CUR);
                fwrite(&newstudent,sizeof(newstudent),1,forigen);
            }
        } else {
            printf("Error: no se encontró el atributo %s \n", parameter);
            break;
        }
    }
    fclose(forigen);

    return 0;
}