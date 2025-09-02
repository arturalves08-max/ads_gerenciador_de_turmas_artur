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
        printf("\n Escolha uma operação \n\n");
        printf("Aperte [1] para Adicionar Aluno \n");
        printf("Aperte [2] para Listar Alunos \n");
        printf("Aperte [3] para Registrar as notas \n");
        printf("Aperte [4] para Calcular Média de um aluno \n");
        printf("Aperte [5] para Mostrar os aprovados \n");
        printf("Aperte [6] para Ver a Estatística da Tuma \n");
        printf("Aperte [7] para Ordenar por média e listar \n");
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
            printf("\n Nï¿½o ï¿½ uma operaï¿½ï¿½o vï¿½lida \n");
            break;
        }
    }
    return 0;
}