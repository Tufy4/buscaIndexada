#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100
#define INDICE 11

int main() {
    int key;
    int menor = 0;
    int maior;
    int indice_um[INDICE];
    int achou = 0;

    int array[SIZE];
    srand((unsigned) time(NULL));

    // Geração de números aleatórios e preenchimento do array
    array[0] = rand() % 100;
    for(int i = 1; i < SIZE; i++) {
        array[i] = array[i-1] + (rand() % 100);
        
         printf("%d ", array[i-1]);
    }

    printf("\nInsira o valor da key: ");
    scanf("%d", &key); 

    
    for(int i = 0; i < INDICE; i++) {
        int index = (i * SIZE / 10) - 1;
        if (index < 0){
            index = 0; 
        } 
        indice_um[i] = array[index];
    }



clock_t comeco = clock();
    
    
    for(int i = 1; i < INDICE && achou == 0; i++) {
        maior = (i * SIZE / 10) - 1;
        if(key > indice_um[i]) {
            menor = maior;
        } else {
            for(int j = menor; j <= maior && achou == 0; j++) {
                if(array[j] == key) {
                    printf("O valor se encontra na posicao %d\n", j+1);
                    achou = 1;
                }
            }
        }
    }

    if(achou == 0) {
        printf("VALOR NÃO ENCONTRADO\n");
    }

    clock_t final = clock();

    // Calcula o tempo de execução em segundos
    double tempo = (double)(final - comeco) / CLOCKS_PER_SEC;
    printf("Tempo de execução: %.10f segundos\n", tempo);
}
