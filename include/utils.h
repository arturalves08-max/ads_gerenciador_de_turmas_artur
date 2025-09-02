#ifndef UTILS_H
#define UTILS_H

#define NOME_MAX 100

#include <stdio.h>

typedef struct {
    char *nome;
    float notas;
} Aluno;

extern FILE *arquivo;

void adicionarAluno();
void listarAluno();
void calcularMedia();
void mostrarAprovados(Aluno *notaAluno, FILE *arquivo);
void MostrarEstatisca();
void ordenarAlunoMedia();
void registrarNota();
char* minuscula(const char *minuscula);
int isAlunoExist(FILE *arquivo, const char *nome);

#endif