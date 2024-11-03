//EXEMPLO MAIS EFICIENTE
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000
#define INDICE 11

int main(){
    int key;
    int menor = 0;
    int maior;
    int indice_um[INDICE];
    int indice_dois[INDICE];
    int achou = 0;
   
    int array[SIZE];
    srand((unsigned) time(NULL));

    array[0] = rand() % 100;
    for(int i = 1; i < SIZE+1; i++){
        array[i] = array[i-1] + (rand() % 100);
        printf("%d ", array[i-1]);
    }
    printf("\n");





    for(int i = 1; i < INDICE; i++){
        indice_um[i] = array[(i * (SIZE / 2) / 10) - 1];
        printf("VALOR INDICE UM %d\n", indice_um[i]);
    }

    printf("\n");

    for(int i = 1, j = 1; i < INDICE; i++, j++){
        indice_dois[i] = array[(SIZE / 2) + (j * (SIZE / 2) / 10) - 1];
        printf("VALOR INDICE DOIS %d\n", indice_dois[i]);
    }






    printf("\nInsira o valor da key: ");
    scanf("%d", &key);

    clock_t comeco = clock();

    if(indice_um[INDICE - 1] >= key){
       
        for(int i = 1; i < INDICE && achou == 0; i++){
             maior = (i * (SIZE / 2) / 10) - 1;

            if(key > indice_um[i]){
                menor = maior;
            } else {
                for(int j = menor; j <= maior && achou == 0; j++){
                    if(array[j] == key){
                        printf("O valor se encontra na posicao %d\n", j);
                        achou = 1;
                    }
                }
            }
        }
    } else {
        for(int i = 1; i < INDICE && achou == 0; i++){
            maior = (SIZE / 2) + (i * (SIZE / 2) / 10) - 1;

            if(key > indice_dois[i]){
                menor = maior;
            } else {
                for(int j = menor; j <= maior && achou == 0; j++){
                    if(array[j] == key){
                        printf("O valor se encontra na posicao %d\n", j);
                        achou = 1;
                    }
                }
            }
        }
    }

    if(achou == 0) {
        printf("VALOR NÃO ENCONTRADO\n");
    }

    clock_t final = clock();
    double tempo = (double)(final - comeco) / CLOCKS_PER_SEC;
    printf("Tempo de execução: %.10f segundos\n", tempo);

    return 0;
}
