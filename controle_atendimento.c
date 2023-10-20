/* Criar um programa para realizar o controle de atendimento presencial 
de clientes em um banco.

Funcionalidades do sistema:
- Cadastrar nome, CPF e setor de atendimento desejado:
    1 - Abertura de Conta
    2 - Caixa
    3 - Gerente Pessoa Física
    4 - Gerente de Pessoa Jurídica
- Listar todos os atendimentos registrados
- Listar atendimento por tipo de atendimento: o usuário deve escolher um
dos tipos e, após a leitura, deve-se mostrar a listagem apenas do tipo escolhido.

O sistema deve conter um menu inicial com as seguintes Opcoes:
Bem-vindo ao sistema de atendimento
1 - Solicitar Atendimento
2 - Listar Atendimentos Registrados
3 - Listar Atendimento por Setor
4 - Sair

Exemplo do formato da listagem dos atendimentos:
Nome: Camila Sonoda
CPF: 123.756.069-63
Tipo Atendimento: 1 - Abertura de Conta
===============================================
Nome: 
CPF:
Tipo Atendimento:
===============================================
*/

#include <stdio.h>
#include <stdlib.h>

//Estrutura para armazenar os dados do atendimento
struct Atendimento {
    char nome[30];
    char sobrenome[30];
    char cpf[15];
    int tipoAtendimento;
};

int main(){
    //Vetor para armazenar cada atendimento
    struct Atendimento atendimentos[100];
    int totalAtendimentos = 0; //Contador 

    /* Criar loop infinito com while(1) - condição 1 é sempre positiva -
    para apresentar o menu na entrada até que o usuário escolha sair.
    O loop só acabará se encontrar alguma condição de saída (item 4 - Sair) */
    while(1){
        printf("BEM-VINDO AO SISTEMA DE ATENDIMENTO! \n\n");
        printf("MENU: \n");
        printf("1 - Solicitar Atendimento \n");
        printf("2 - Listar Atendimentos Registrados\n");
        printf("3 - Listar Atendimentos por Setor\n");
        printf("4 - Sair\n\n");
        int escolha;
        printf("Selecione uma opcao: ");
        scanf("%d", &escolha);

        fflush(stdin); // Limpar o buffer de entrada
        system("cls"); // Limpar a tela de menu


        switch (escolha) {
            case 1:
                printf("1 - SOLICITAR ATENDIMENTO \n\n");
                printf("Nome: ");
                scanf("%29s", atendimentos[totalAtendimentos].nome);
                printf("Sobrenome: ");
                scanf("%29s", atendimentos[totalAtendimentos].sobrenome);
                printf("CPF: ");
                scanf("%14s", atendimentos[totalAtendimentos].cpf);
                printf("Tipo de Atendimento: \n 1 - Abertura de Conta \n 2 - Caixa \n 3 - Gerente Pessoa Fisica \n 4 - Gerente de Pessoa Juridica \n");
                scanf("%d", &atendimentos[totalAtendimentos].tipoAtendimento);
                totalAtendimentos++;
                printf("\n");
                printf("Atendimento registrado com sucesso! \n\n\n");
                break;
            
            case 2: 
                printf("2 - LISTAR ATENDIMENTOS REGISTRADOS \n\n");
                for (int i = 0; i < totalAtendimentos; i++) {
                    printf("Nome: %s\n", atendimentos[i].nome);
                    printf("Sobrenome: %s\n", atendimentos[i].sobrenome);
                    printf("CPF: %s\n", atendimentos[i].cpf);
                    printf("Tipo de Atendimento: %d - ", atendimentos[i].tipoAtendimento);
                    switch (atendimentos[i].tipoAtendimento) {
                        case 1:
                            printf("Abertura de Conta\n");
                        break;
                        case 2:
                            printf("Caixa\n");
                        break;
                        case 3:
                            printf("Gerente de Pessoa Fisica\n");
                        break;
                        case 4:
                            printf("Gerente de Pessoa Juridica\n");
                        break;                        
                        default:
                            printf("Outro\n");
                            break;
                    }
                    printf("=================================================\n\n\n");
                }         
                break;
            
            case 3:
                printf("3 - LISTAR ATENDIMENTO POR SETOR");
                int filtroAtendimento;
                printf("Filtre por um tipo de Atendimento: \n 1 - Abertura de Conta \n 2 - Caixa \n 3 - Gerente Pessoa Fisica \n 4 - Gerente de Pessoa Juridica \n");
                scanf("%d", &filtroAtendimento);
                for (int i = 0; i < totalAtendimentos; i++) {
                    if (atendimentos[i].tipoAtendimento == filtroAtendimento){
                        printf("Nome: %s\n", atendimentos[i].nome);
                        printf("Sobrenome: %s\n", atendimentos[i].sobrenome);
                        printf("CPF: %s\n", atendimentos[i].cpf);
                        printf("Tipo de Atendimento: %d - ", atendimentos[i].tipoAtendimento);
                        switch (atendimentos[i].tipoAtendimento) {
                            case 1:
                                printf("Abertura de Conta\n");
                            break;
                            case 2:
                                printf("Caixa\n");
                            break;
                            case 3:
                                printf("Gerente de Pessoa Fisica\n");
                            break;
                            case 4:
                                printf("Gerente de Pessoa Juridica\n");
                            break;                        
                            default:
                                printf("Outro\n");
                                break;
                        }
                        printf("=================================================\n\n\n");
                    }         
                }
                break;      

            case 4:
                exit(0);           

        default:
            printf("Opcao invalida. Tente novamente. \n");
        }
    }

    return 0;
}