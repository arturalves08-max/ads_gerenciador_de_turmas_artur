#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>

#define NOME_MAX 100
#define MAX_NOTAS 10

typedef struct {
    char nome[NOME_MAX];
    float notas[MAX_NOTAS];
    int qtdNotas;
} Aluno;

void adicionarAluno(Aluno *aluno, FILE *arquivo);
void listarAluno();
void registrarNota();
void calcularMedia();
void mostrarAprovados(Aluno *notaAluno, FILE *arquivo);
void mostrarEstatistica();
void ordenarAlunoMedia();

char* minuscula(const char *texto);
int isAlunoExist(FILE *arquivo, const char *nome);

#endif
