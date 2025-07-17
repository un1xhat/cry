#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

    void encripta(int key, char *nameFile)
    {
        FILE *r = fopen(nameFile, "r");
        if(r == NULL){
            perror("file error");
            exit(1);
        }
        strcat(nameFile, ".cry");
        FILE *w = fopen(nameFile, "w");
        int letter;
        while((letter = getc(r)) != EOF){
            letter = letter + key;
            fprintf(w, "%c", letter);
        }

        fclose(r);
        fclose(w);
    }

    void decripta(int key, char *nameFile)
    {
        FILE *r = fopen(nameFile, "r");
        if(r == NULL){
            perror("file error");
            exit(1);
        }
        nameFile[strlen(nameFile)-4]='\0';
        FILE *w = fopen(nameFile, "w");
        int letter;
        while((letter = getc(r)) != EOF){
            letter = letter - key;
            fprintf(w, "%c", letter);
        }

        fclose(r);
        fclose(w);
    }

    int main()
    {
        char file[256];
        int key, opc;
        printf("File: ");
        fgets(file, 256, stdin);
        printf("Key: ");
        scanf("%d", &key);
        file[strlen(file)-1]='\0';
        printf("[0]=>Encripta; [1]=>Decripta: ");
        scanf("%d", &opc);
        if(opc == 0){
            encripta(key, file);
        }
        else if(opc == 1){
            decripta(key, file);
        }
        else{
            printf("???\n");
            return 1;
        }

      return 0;
    }
