# Gerenciador de Turmas

Este projeto é um sistema simples em C para gerenciar alunos de uma turma, permitindo cadastrar nomes, registrar notas e realizar operações como listagem, cálculo de médias e verificação de aprovados.

## Funcionalidades

- **Adicionar Aluno:** O usuário pode cadastrar um novo aluno, informando o nome. O sistema impede a duplicidade de nomes, verificando se já existe um aluno cadastrado com o mesmo nome (ignorando maiúsculas/minúsculas).
- **Listar Alunos:** Exibe todos os alunos cadastrados no arquivo.
- **Registrar Notas:** Permite associar notas aos alunos.
- **Calcular Média:** Calcula a média das notas de um aluno específico.
- **Mostrar Aprovados:** Lista os alunos que atingiram a média mínima para aprovação.
- **Ver Estatística da Turma:** Mostra dados estatísticos gerais da turma.
- **Ordenar por Média:** Lista os alunos ordenados pela média das notas.
- **Remover Aluno:** Permite excluir um aluno do cadastro.
- **Sair:** Encerra o programa.

## Estrutura dos Arquivos

- **main.c:** Contém o menu principal e o fluxo de interação com o usuário.
- **utils.c / utils.h:** Funções auxiliares para manipulação de alunos, notas e operações no arquivo.
- **database/database.txt:** Arquivo onde os dados dos alunos são armazenados. Cada linha representa um aluno, com os campos separados por ponto e vírgula.

## Como funciona o cadastro

Ao escolher a opção de adicionar aluno, o sistema solicita o nome, converte para minúsculas (inclusive acentuação básica), verifica se já existe no arquivo e, se não existir, grava o nome no arquivo `database.txt`. O mesmo processo é seguido para outras operações, sempre garantindo integridade dos dados.

## Observações Técnicas

- O sistema utiliza `setlocale(LC_ALL, "Portuguese")` para garantir suporte a acentuação.
- O arquivo é aberto em modo `a+`, permitindo leitura e escrita sem sobrescrever dados antigos.
- Funções como `strcspn` e `tolower` são usadas para tratar strings e garantir que nomes sejam comparados corretamente.
- O tamanho da fonte do terminal não é controlado pelo código, mas pode ser ajustado nas configurações do terminal.

## Como executar

1. Compile todos os arquivos `.c` do projeto. 
2. Execute o programa.
3. Siga o menu interativo para realizar as operações desejadas.

---

**Exemplo de linha no arquivo:** 