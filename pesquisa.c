#include <stdio.h>
#include <stdlib.h>

#define SIZE 8
#define FREE 0
#define OCUPADO 1
#define REMOVIDO 2

struct noh
{
    int valor;
    int status;
};

typedef struct noh Noh;

int hash(int valor){
    return valor % SIZE;
}


void show(Noh val[]){
    for(int i=0; i < SIZE; i++){
        printf(
            "\n %d %s",
            val[i].valor, 
            val[i].status==FREE?
            "Livre":
            val[i].status==OCUPADO?
            "Ocupado":
            "Removido"
        );
    }
    printf("\n ---------------------\n");
}

int insert(Noh vector[], int val){
    int hashval = hash(val);
    for(int i = 0; i < SIZE; i++){
        if(vector[(hashval+i)%SIZE].status != OCUPADO){
            vector[(hashval+i)%SIZE].status = OCUPADO;
            vector[(hashval+i)%SIZE].valor = val;
            show(vector);
            return hashval+i;
        }
    }
    return -1;
}

int removeNoh(Noh vector[], int val){
    int hashval = hash(val);
    for(int i = 0; i < SIZE && vector[(hashval+i)%SIZE].status != FREE; i++){
        if(vector[(hashval+i)%SIZE].valor == val){
            vector[(hashval+i)%SIZE].status = REMOVIDO;
            show(vector);
            return hashval+i;
        }
    }
    return -1;
}

int addqt(Noh vector[], int val){
    int hashval = hash(val);
    for(int i = 0; i < SIZE; i++){
        if(vector[(hashval+pow(i,2))%SIZE].status != OCUPADO){
            vector[(hashval+pow(i,2))%SIZE].status = OCUPADO;
            vector[(hashval+pow(i,2))%SIZE].valor = val;
            show(vector);
            return hashval+i;
        }
    }
    return -1;
}

int removeqt(Noh vector[], int val){
    int hashval = hash(val);
    for(int i = 0; i < SIZE && vector[(hashval+i)%SIZE].status != FREE; i++){
        if(vector[(hashval+i)%SIZE].valor == val){
            vector[(hashval+i)%SIZE].status = REMOVIDO;
            show(vector);
            return hashval+i;
        }
    }
    return -1;
}

int adduni(Noh vector[], int val, int *size){
    int p = 13;
    int m = 8;
    int a = 5;
    int b = 7;
    int state = 0;
    int hash;
    if(sizeof(vector)/sizeof(Noh) < size){
        return - 1;
    }
    do{
        hash = !state ? ((a*val+b)%p)%m : ((a*hash+b)%p)%m;
        state = 1;
        if(vector[hash].status != OCUPADO){
            vector[hash].valor = val;
            show(vector);
            *size++; 
            return hash;
        }
    }
    while(1);

}

int main(){
    Noh vector[SIZE] = {0};
    insert(vector, 16);
    insert(vector, 23);
    insert(vector, 41);
    insert(vector, 25);
    insert(vector, 39);
    removeNoh(vector,41);
    removeNoh(vector,23);
    removeNoh(vector,25);
    insert(vector,34);
}