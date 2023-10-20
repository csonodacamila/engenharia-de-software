/*
Uma corretora de investimentos solicitou a criação de um simulador de 
rendimentos na Linguagem C. A ferramenta deve considerar o cálculo de juros
COMPOSTOS, ou seja, juros sobre juros, mês a mês, por exemplo:

R$ 1.000,00 investidos
Período: 3 meses
% de Rendimento por mês: 1%
(1% de 1000 = 10)

Depois do mês 1, terá = R$ 1.010,00
Depois do mês 2, terá = R$ 1.020,10
Depois do mês 3, terá = R$ 1.030,301

Valor saldo final = R$ 1.030,301

Após o rendimento, é necessário pagar 15% de imposto sobre o lucro do investimento,
no ato do saque. Ficaria, então:

Lucro do investimento (1.030,301 - 1.000): 30,301
15% de 30,301 = 4,54515
Lucro - imposto = 25,755
Investimento + lucro = R$ 1.025,75

Desenvolva um programa que realize esse cálculo de juros compostos. O rendimento 
deve ser mostrado mês a mês, e no final, mostrar o saldo final bruto e o saldo
final líquido (menos os 15% de impostos sobre o rendimento).
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {

    setlocale(LC_ALL, "pt_BR.utf8");

    float valorInvestido = 0;
    int periodo = 0;
    float percentualRendimento = 0;
    float rendimentoFinalBruto = 0;
    float lucro = 0;
    float rendimentoFinalLiquido = 0;
    float descontoImposto = 0;
   
    printf("Digite o valor investido (somente numeros): \n ");
    scanf("%f", &valorInvestido);

    printf("Digite a quantidade de meses do investimento (somente numeros): \n");
    scanf("%d", &periodo);

    printf("Digite o percentual de rendimento ao mes (somente numeros): \n");
    scanf("%f", &percentualRendimento);

    rendimentoFinalBruto = valorInvestido;
    percentualRendimento = percentualRendimento / 100;

    //Calculo de rendimento mes a mes
    printf("\n\n");
    printf("--- RENDIMENTO MES A MES ---\n");

    for (int i = 1; i <= periodo; i++)
    {
        rendimentoFinalBruto = rendimentoFinalBruto + (percentualRendimento * rendimentoFinalBruto);
        printf("Rendimento mes %i: R$ %.3f\n", i, rendimentoFinalBruto);
    }
    
    //Rendimento final bruto
    printf("\n");
    printf("RENDIMENTO FINAL BRUTO: R$ %.3f\n", rendimentoFinalBruto);

    //Rendimento final líquido (com imposto de 15% sobre o lucro)
    //Calculo do lucro:
    lucro = rendimentoFinalBruto - valorInvestido;
    descontoImposto = 0.15 * lucro;
    lucro = lucro - descontoImposto;
    rendimentoFinalLiquido = valorInvestido + lucro;    

    printf("\n");
    printf("RENDIMENTO FINAL LIQUIDO: R$ %.3f\n", rendimentoFinalLiquido);

    return 0;
}