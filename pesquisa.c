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
show(Noh val[]){
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

int insert(Noh vector[], int newval){
    int hashval = hash(newval);
    for(int i = 0; i < SIZE; i++){
        if(vector[(hashval+i)%SIZE].status != OCUPADO){
            vector[(hashval+i)%SIZE].status = OCUPADO;
            vector[(hashval+i)%SIZE].valor = newval;
            show(vector);
            return hashval+i;
        }
    }
    return -1;
}

int removeNoh(Noh vector[], int removeNohVall){
    int hashval = hash(removeNohVall);
    for(int i = 0; i < SIZE && vector[(hashval+i)%SIZE].status != FREE; i++){
        if(vector[(hashval+i)%SIZE].valor == removeNohVall){
            vector[(hashval+i)%SIZE].status = REMOVIDO;
            show(vector);
            return hashval+i;
        }
    }
    return -1;
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