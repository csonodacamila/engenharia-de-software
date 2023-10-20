#include <stdio.h>

int main() {
    int linhas = 2;
    int colunas = 3;

    // Declarar a matriz
    int matriz[2][3];

    // LOOPS DE REPETIÇÃO PARA PREENCHER A MATRIZ
    // 1. Criar a variável i (contador) que inicia com 0
    // 2. Definir a condição: enquanto i for menor que o número de linhas
    // 3. Definir o incremento: i++ ou i = i + 1 (começa do 0 até que chegue a 3)
    for (int i = 0; i <= linhas; i++) {
        // Aqui serão preenchidas todas as colunas por cada linha
        for (int j = 0; j <= colunas; j++) {
            matriz[i][j] = 1;
        }
    }

    // Apresentar a matriz
    // Utilizar o mesmo loop para que ele apresente cada elemento
    // (Ele não lê a matriz inteira de uma vez)
    for (int i = 0; i <= linhas; i++) {
        for (int j = 0; j <= colunas; j++) {
            /*Usamos o %d para formatar números int em 
            entrada (scanf) e saída (printf) de dados*/
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}



