#include <stdio.h>   // para FILE, fopen, fclose, printf, scanf, fgets, fprintf, fputs, perror
#include <stdlib.h>  // para malloc, free, exit
#include <string.h>  // para strlen, strcpy, strtok, strcmp, strcspn
#include <ctype.h>   // para tolower

#include "include/utils.h"

void registrarNota() {
    FILE *origem, *temporario;
    char *nome = malloc(NOME_MAX * sizeof(char));
    if (nome == NULL) {
        printf("Erro de Alocação de memória");
        exit(1);
    }

    printf("Insira o Nome de um aluno Existente: ");
    fgets(nome, NOME_MAX, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    // Convertendo nome para minúsculas
    size_t tam = strlen(nome);
    char nomeMinusculo[NOME_MAX];
    for (size_t i = 0; i < tam; i++) {
        nomeMinusculo[i] = tolower((unsigned char)nome[i]);
    }
    nomeMinusculo[tam] = '\0';

    const char *diretorio = "database/database.txt";
    origem = fopen(diretorio, "r");
    if (!origem) {
        printf("Erro ao abrir o arquivo de alunos.\n");
        free(nome);
        return;
    }

    if (!isAlunoExist(origem, nomeMinusculo)) {
        printf("Aluno nao encontrado.\n");
        fclose(origem);
        free(nome);
        return;
    }
    rewind(origem); // Volta para o início após verificar a existência

    printf("Insira a quantidade de Notas que o Aluno tera: \n");
    int quantidade;
    scanf("%d", &quantidade);
    getchar(); // consumir \n

    float notas[quantidade];
    for (int i = 0; i < quantidade; i++) {
        printf("Insira a nota[%d]: ", i + 1);
        scanf("%f", &notas[i]);
        if(notas[i] <= 10 && notas[i] >=0) {
            continue;
        } else {
            printf("ERRO: Insira uma nota entre 0 e 10 \n");
            printf("Insira a nota[%d]: \n", i + 1);
            scanf("%f", &notas[i]);
        }
        getchar(); // consumir \n
    }

    temporario = fopen("database/temporario.txt", "w");
    if (temporario == NULL) {
        perror("Erro ao criar arquivo temporario");
        fclose(origem);
        free(nome);
        return;
    }

    char linha[256];
    while (fgets(linha, sizeof(linha), origem)) {
        char linhaCopia[256];
        strcpy(linhaCopia, linha);
        char *token = strtok(linhaCopia, ";");

        if (token) {
            char tokenMinusculo[NOME_MAX];
            size_t len = strlen(token);
            for (size_t i = 0; i < len; i++) {
                tokenMinusculo[i] = tolower((unsigned char)token[i]);
            }
            tokenMinusculo[len] = '\0';

            if (strcmp(tokenMinusculo, nomeMinusculo) == 0) {
                fprintf(temporario, "%s;", token);  // só o nome do aluno
                for (int i = 0; i < quantidade; i++) {
                    fprintf(temporario, "%.2f;", notas[i]);
                }
                fprintf(temporario, "\n");
                continue; // pula o fputs abaixo
            }
        }

        fputs(linha, temporario);
    }

    fclose(origem);
    fclose(temporario);
    free(nome);

    remove("database/database.txt");
    rename("database/temporario.txt", "database/database.txt");

    printf("Nota registrada com sucesso!\n");
}
