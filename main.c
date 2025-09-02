#include <stdio.h>
#include <locale.h>
#include <stdlib.h>


#include "include/utils.h"

int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "Portuguese");
    system("mkdir database");
    const char* diretorio = "database/database.txt";
    FILE *arquivo = NULL;
    arquivo = fopen(diretorio, "a+");
    if(!arquivo) {
        printf("Erro ao iniciar o database.txt");
        exit(1);
    }
    int operacao = 0;
    Aluno nomeAluno;
    while(1) {
        printf("\n --- Gerenciador de Turma --- \n");
        printf("\n Escolha uma opera��o \n\n");
        printf("Aperte [1] para Adicionar Aluno \n");
        printf("Aperte [2] para Listar Alunos \n");
        printf("Aperte [3] para Registrar as notas \n");
        printf("Aperte [4] para Calcular M�dia de um aluno \n");
        printf("Aperte [5] para Mostrar os aprovados \n");
        printf("Aperte [6] para Ver a Estat�stica da Tuma \n");
        printf("Aperte [7] para Ordenar por m�dia e listar \n");
        printf("Aperte [8] para Remover aluno \n");
        printf("Aperte [9] para sair \n\n");
        scanf("%d", &operacao);
        getchar();
        switch (operacao) {
        case 1:
            adicionarAluno(&nomeAluno, arquivo);
            break;  
        case 9:
            printf("Encerrando...");
            exit(0);
            break;
        default:
            printf("\n N�o � uma opera��o v�lida \n");
            break;
        }
    }
    return 0;
}