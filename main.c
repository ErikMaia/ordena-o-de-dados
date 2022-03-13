#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void createFiles(){
    FILE *ordenado, *invertido, *randomico;
    int x;
    char nomeArquivo[255];
    srand (time(NULL));

    for(int i = 500000; i <= 1000000; i += 250000){

        // Arquivo Ordenada
        sprintf(nomeArquivo, "Ordenado%05d.txt", i);
        ordenado = fopen(nomeArquivo, "w");
        for (x=1;x<=i;x++){
            fprintf(ordenado, "%d\n", x);
        }
        fclose(ordenado);

        // Arquivo Invertido
        sprintf(nomeArquivo, "Invertido%05d.txt", i);
        invertido = fopen(nomeArquivo, "w");
        for (x=i;x>=1;x--){
            fprintf(invertido, "%d\n", x);
        }
        fclose(invertido);

        // Arquivo Randomico
        sprintf(nomeArquivo, "Randomico%05d.txt", i);
        randomico = fopen(nomeArquivo, "w");
        for (x=1;x<=i;x++){
            fprintf(randomico, "%d\n", rand()%i);
        }
        fclose(randomico);
    }

}

int* getVetor(char* nomeArquivo, int tam){
    FILE *arquivo = NULL;
    char strArq[255];
    int *vetor = malloc(sizeof(int) * tam);
    sprintf(strArq, nomeArquivo, tam);
    arquivo = fopen(strArq, "r");
    if(arquivo==NULL){
        return NULL;
    }
    else{
        for(int i=0;i<tam;i++){
            fscanf(arquivo, "%d", &vetor[i]);
        }
        fclose(arquivo);
        return vetor;
    }
    
}

void bubleSort(int vetor[], int tam) {
    int aux;
    for(int i = 0; i < tam; i++){
        for(int j = i+1; j < tam; j++){
            if(vetor[j]< vetor[i]){
                aux = vetor[j];
                vetor[j] = vetor[i];
                vetor[j] = aux;
            }
        }
    }
}

void insertSort(int vetor[], int tam){
    int aux;
    for(int i = 1; i < tam; i++){
        aux = vetor[i];
        int posiçãoDeTeste = i;
        while(aux < vetor[posiçãoDeTeste] && posiçãoDeTeste>0){
            vetor[posiçãoDeTeste+1] = vetor[posiçãoDeTeste];
            posiçãoDeTeste--;
        }
        vetor[posiçãoDeTeste] = aux;
    }
}

float singleTest(int vetor[], int tam, void functionOrder(int v[], int t)){
    clock_t start = clock();
    functionOrder(vetor, tam);
    float tempo = (float)(clock()-start) / CLOCKS_PER_SEC;
    return tempo;
}

void executeTestes(){
    int *vetor;
    float tempo;
    for(int i = 500000; i <= 1000000; i += 250000){
        printf("%d", i);
        
        // invertido
        printf("\n Invertido");
        vetor = getVetor("Invertido%d.txt",i);
        
        printf("\n BubleSort: %.2f", singleTest(vetor,i, bubleSort));
        printf("\n InsertSort: %.2f", singleTest(vetor,i, insertSort));
        
        printf("\n Ordenada: ");
        vetor = getVetor("Ordenado%d.txt",i);
        
        printf("\n BubleSort: %.2f\n", singleTest(vetor,i, bubleSort));
        printf("\n InsertSort: %.2f\n", singleTest(vetor,i, insertSort));
        
        printf("\n Randomico: ");
        vetor = getVetor("Randomico%d.txt",i);
        
        printf("\n\t\t BubleSort: %.2f", singleTest(vetor,i, bubleSort));
        printf("\n\t\t InsertSort: %.2f", singleTest(vetor,i, insertSort));
    }
}

int main(){
    // int tam;
    int* vetor;

    // scanf("%d",&tam);
    vetor = getVetor("Invertido%d.txt",500000);
    if(vetor==NULL){
        createFiles();
    }
    executeTestes();
    return 0;
}