#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

#include "include/utils.h"

int main(int argc, char *argv[]) {
    system("mkdir database");

    // Cria o arquivo se não existir
    FILE *arquivo = fopen("database/database.txt", "a+");
    if (!arquivo) {
        printf("Erro ao iniciar o database.txt\n");
        exit(1);
    }

    int operacao = 0;
    Aluno nomeAluno;

    while (1) {
        printf("\n --- Gerenciador de Turma --- \n");
        printf("\n Escolha uma operacao \n\n");
        printf("Aperte [1] para Adicionar Aluno \n");
        printf("Aperte [2] para Listar Alunos \n");
        printf("Aperte [3] para Registrar as notas \n");
        printf("Aperte [4] para Calcular Media de um aluno \n");
        printf("Aperte [5] para Mostrar os aprovados \n");
        printf("Aperte [6] para Ver a Estatistica da Tuma \n");
        printf("Aperte [7] para Ordenar por media e listar \n");
        printf("Aperte [8] para Remover aluno \n");
        printf("Aperte [9] para sair \n\n");

        scanf("%d", &operacao);
        getchar(); // limpar o buffer do teclado

        switch (operacao) {
        case 1:
            adicionarAluno(&nomeAluno, arquivo);  // ou ajustar conforme sua implementação
            break;
        case 3:
            fclose(arquivo);
            registrarNota(); // essa função já abre e fecha o arquivo sozinha
            arquivo = fopen("database/database.txt", "a+");  // REABRIR
            if (!arquivo) {
                printf("Erro ao reabrir database.txt\n");
                exit(1);
            }
            break;
        case 9:
            fclose(arquivo);
            printf("Encerrando...\n");
            exit(0);
        default:
            printf("\n Nao e uma operacao valida \n");
            break;
        }
    }

    return 0;
}
