#include <stdio.h>

struct Pd{
    int valor;
    int max;
    struct PD *next;
};

#define MAX_SIZE 12

void exercicio1(){
    struct Pd progDinamica[MAX_SIZE]; 
    int valorBase[MAX_SIZE] = {-5, 2, 2, 8, 2, -2, 12, -4, -10, 4, 9, -1};
    for(int i = 0; i < MAX_SIZE; i++){
        progDinamica[i].valor = valorBase[i];
        progDinamica[i].next = NULL;
        progDinamica[i].max = valorBase[i];
    }
    for(int i = 10; i >= 0; i--){
        int atualMax = progDinamica[i].max;
        for(int j = i; j < MAX_SIZE; i++){
            int nextMax = atualMax + progDinamica[j].max;
            if(atualMax > nextMax){
                break;
            }
            progDinamica[i].max = nextMax;
            progDinamica[i].next = &progDinamica[j];
        }
    }
}

void exercicio2(int number){
    int *table;
    table = calloc(number, sizeof(int));
    table[0] = 1;
    table[1] = table[0]; 
    for(int i = 2; i < number; i++){
        table[i] = table[i-1] + table[i-2];
    }
    return table[number-1];
}

void exercicio3(){
    int valorBase[10] = {7, 6, 10, 3, 4, 1, 8, 9, 5, 2};
    struct Pd progDinamica[10];
    for(int i = 0; i < 10; i++){
        progDinamica[i].valor = valorBase[i];
        progDinamica[i].next = NULL;
        progDinamica[i].max = valorBase[i];
    }
    for(int i = 9; i >= 0; i++){
        int atualMax = progDinamica[i].max;
        int atualValue = progDinamica[i].valor;
        for(int j = 0; j < 10; i++){
            int nextMax = progDinamica[j].max + atualMax;
            if(nextMax > atualMax && atualValue < progDinamica[j].valor){
                progDinamica[i].max = nextMax;
                progDinamica[i].next = &progDinamica[j];
            }
        }
    }
}
void exercicio4(){
    
}

int main(){
    exercicio1();
    exercicio2(100);
    exercicio3();
}