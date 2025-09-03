#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "include/utils.h"

// Verifica se o aluno já existe no arquivo
int isAlunoExist(FILE *arquivo, const char *nome) {
    char buffer[NOME_MAX];
    rewind(arquivo);  // Garante que começamos a ler do início

    while (fgets(buffer, sizeof(buffer), arquivo)) {
        buffer[strcspn(buffer, ";")] = '\0'; // Remove parte após ';'
        if (strcmp(buffer, nome) == 0) {
            return 1;
        }
    }

    return 0;
}

// Adiciona um aluno ao arquivo
void adicionarAluno(Aluno *nomeAluno, FILE *arquivo) {
    printf("Digite o nome do aluno: \n");
    fgets(nomeAluno->nome, NOME_MAX, stdin);
    nomeAluno->nome[strcspn(nomeAluno->nome, "\n")] = '\0'; // Remove '\n'

    // Criar uma cópia do nome para converter para minúsculas
    char bufferFile[NOME_MAX];
    strcpy(bufferFile, nomeAluno->nome);

    char *nomeMinusculo = minuscula(bufferFile);

    if (isAlunoExist(arquivo, nomeMinusculo)) {
        printf("Aluno ja existe!\n");
        free(nomeMinusculo);
        return;
    }

    fprintf(arquivo, "%s;\n", nomeMinusculo);
    fflush(arquivo);
    free(nomeMinusculo);

    printf("Aluno Adicionado com Sucesso!\n\n");
}

// Converte uma string para minúsculas e retorna uma nova string
char* minuscula(const char *texto) {
    char *string = malloc(strlen(texto) + 1);  // +1 para '\0'
    if (string == NULL) {
        printf("Erro de Alocacao de Memoria!\n");
        exit(1);
    }

    for (int i = 0; texto[i]; i++) {
        string[i] = tolower((unsigned char) texto[i]);
    }
    string[strlen(texto)] = '\0';

    return string;
}

void listarAluno() {

}
