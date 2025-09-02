#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "include/utils.h"

int isAlunoExist(FILE *arquivo, const char *nome) {
    char buffer[NOME_MAX];
    rewind(arquivo);
    while (fgets(buffer, sizeof(buffer), arquivo)) {
        buffer[strcspn(buffer, ";")] = '\0';
        if(strcmp(buffer, nome) == 0) {
            return 1;
        } 
    } 
    return 0;
}

void adicionarAluno(Aluno *nomeAluno, FILE *arquivo) {
    nomeAluno->nome = (char *) malloc(NOME_MAX * sizeof(char));
    if(nomeAluno->nome == NULL) {
        printf("Erro de alocação de memória! \n");
        exit(1);
    }

    printf("Digite o nome do aluno: \n");
    fgets(nomeAluno->nome, NOME_MAX, stdin);
    nomeAluno->nome[strcspn(nomeAluno ->nome, "\n")] = '\0';
    
    char bufferFile[strlen(nomeAluno->nome)];
    strcpy(bufferFile, nomeAluno->nome);
    
    char *nomeMinusculo = minuscula(bufferFile);

    if(isAlunoExist(arquivo, nomeMinusculo)) {
        printf("Aluno já existe");
        return;
    }

    fprintf(arquivo,"%s;\n", nomeMinusculo);
    fflush(arquivo);
    printf("Aluno Adicionado com Sucesso! \n\n");
}

char* minuscula(const char *minuscula) {
    char *string = (char *) malloc(strlen(minuscula) *sizeof(char));
    if(string == NULL) {
        printf("Erro de Alocação !");
        exit(1);
    }
    for(int i = 0; i < strlen(minuscula); i++) {
        string[i] = tolower((unsigned char) minuscula[i]);
    }
    string[strlen(minuscula)] = '\0';
    return string;
}

void registrarNota() {

}