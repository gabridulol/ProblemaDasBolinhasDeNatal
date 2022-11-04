#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função que gera os arranjos de acorodo com as cores e o tamanho
// e realiza a análise de possíveis soluções para o PBN
// Crédito:
// Marcos Paulo Ferreira (Daemonio)
// https://daemoniolabs.wordpress.com
// OBS.: detalhes do funcionamento do código 
// podem ser encontrados na documnetação
int valida_pbn(int size, int matriz[size][size]) {
    // Nosso número na base n. Ele é um vetor
    // de n+1 posições representando um número
    // na base n.
    int *num; 

    // O in_color é a string de entrada, e string
    // receberá cada permutação.
    char in_color[100] = "AB";
    char string[100];

    int n, r, i, j, k;
    int m, o;

    // Declaração de variáveis inteiras contadores para auxiliar
    // no processo de análise dos arranjos.
    int cont_true; cont_true = 0;
    int cont_false; cont_false = 0;
    int cont_total; cont_total = 0;

    // O código começa recebendo o conjunto de entrada (in_color) e do r (size). 
    // O conjunto pode ser uma string qualquer e o r deve ser um inteiro 
    // maior ou igual a 1.
    r = size;

    // Essa parte elimina os caracteres repetidos da string. 
    // Devemos ter esse tipo de código, pois a entrada deve conter elementos distintos.
    n = strlen(in_color);
    j = 0;
    string[0] = 0;
    for (i = 0; i < n; i++) {
        if (strchr(string, in_color[i]) == NULL) {
            string[j] = in_color[i];
            j++;
            string[j] = 0;
        }
    }
    strcpy(in_color, string);
    n = strlen(in_color);

    // Cria o nosso número. Ele é um vetor de
    // r+1 posições, sendo que a última é
    // reservada para indicar quando todos os
    // números de tamanho r foram gerados.
    num = (int *) calloc((r + 1), sizeof(int));
    if (num == NULL) {
        perror("calloc");
        return -1;
    }

    // Termina quando a última posição do vetor for 1.
    while (num[r] == 0) {
        for (i = 0; i < n; i++) {
            // Processo de mapeamento.
            for (j = 0, k = r - 1; j < r; j++) {
                string[k] = in_color[num[j]];
                k--;
            }
            // Mostra o resultado.
            string[r] = 0;
            printf("%s\n\n", string);

            // Realiza a verificação para analisar se o arranjo é válido ou inválido
            for (m = 0; m < size; m++) {
                for (o = 0; o < size; o++) {
                    if (matriz[m][o] == 1) {
                        if (string[m] == string[o]) {
                            cont_false++;
                            break;
                        }
                    }
                }
            }
            if (cont_false != 0) {
                cont_true++;
            }
            // Incrementa o algarismo menos significativo.
            num[0]++;
            cont_total++;
        }
        // Muda de "casa" e lança os vai uns. 
        for (i = 0; i < r; i++) {
            if (num[i] == n) {
                num[i] = 0;
                num[i + 1]++;
            }
        }
    }

    // Exibe o número de arranjos válidos e inválidos
    printf("Arranjos válidos: %d\n", cont_total - cont_true);
    printf("Arranjos inválidos: %d\n", cont_true);

    return 0;
}