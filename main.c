#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "./headers/arranjo.h"
#include "./headers/entrada.h"

int main() {
    int loop; loop = 1;
    int option;

    while (loop) {
        printf("\n-------------------- PROBLEMAS DAS BOLINHA DE NATAL --------------------\n");
        printf("Escolha um modo:\n");
        printf("1. Arranjos\n");
        printf("2. Tabela de adjacências\n");
        printf("3. Sair do programa\n");
        printf("------------------------------------------------------------------------\n");
        printf("Opção desejada: "); scanf("%d", &option);
        system("cls || clear");

        switch (option) {
        case 1 :
            {
            char in_color[100];
            int size;
            clock_t tempo_cont;
            printf("Modo arranjos escolhido!\n\n");
            printf("Letra inicial de cada cor (sem espaços): "); scanf("%s", in_color);
            printf("Espaços: "), scanf("%d", &size);
            printf("\n");
            clock_t start, end;
            time_t t_start, t_end;
            double cpu_time_used;
            double time_used;
            start = clock();
            t_start = time(NULL);
            gerar_arranjo(in_color, size);
            end = clock();
            t_end = time(NULL);
            cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
            time_used = difftime(t_end, t_start);
            printf("Tempo (método clock_t): %lf\n", cpu_time_used);
            printf("Tempo (método time_t): %lf\n", time_used);
            size = 0;
            break;
            }
        case 2 :
            {
            char file_name[100]; // Variável que recebe o nome do arquivo para ser lido
            int size; // Determina o tamanho da matriz das adjacências
            printf("Modo tabela de adjacências escolhido!\n\n");
            do {
                printf("Nome do arquivo: "); scanf("%s", file_name);
                if (open_file(file_name) == 1) {
                    printf("Erro na abertura do arquivo!\nTente novamente!\n");
                }
                printf("\n");
            } while (open_file(file_name) == 1);
            size = get_size_arvore_natal(file_name);
            int matriz[size][size];
            iniciar_matriz_adj(file_name, size, matriz);
            imprime_matriz_adj(size, matriz);
            size = 0;
            break;
            }
        case 3 :
            {
            loop = 0;
            break;
            }
        default:
            {
            printf("Opção inválida! Tente novamente!\n");
            }
        }
    }
}