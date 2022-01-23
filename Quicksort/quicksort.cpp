#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//Just another code to test quicksort 
//THIS IS NOT A SOLUTION FOR A BEECROWD/URI PROBLEM 
//Apenas outro codigo para testar o quicksort
//ISTO NAO EH A SOLUCAO DE UM PROBLEMA DE BEECROWD/URI


int particiona(int *V,int inicio, int fim){
  int esq,dir,pivo,aux;
  esq = inicio;
  dir = fim;
  pivo = V[inicio];

  while(esq < dir){
    while(esq <= fim && V[esq] <= pivo)
        esq++;

    while(dir >= 0 && V[dir] > pivo)
        dir--;

    if(esq < dir){
        aux = V[esq];
        V[esq] = V[dir];
        V[dir] = aux;
    }

  }
  V[inicio] = V[dir];
  V[dir] = pivo;
  return dir;
}

void quicksort(int *V,int inicio, int fim){
   int pivo;
   if(fim > inicio){
    pivo = particiona(V,inicio,fim);
    quicksort(V,inicio,pivo-1);
    quicksort(V,pivo+1,fim);
    }

}

int main()
{
    int *p;
    int aleatorio,i,qntd;

    printf("Digite a quantidade:\n");
    scanf("%d",&qntd);

    p = (int *) malloc(qntd*sizeof(int));

    srand(time(NULL));
    printf("\n");
    for(i = 0; i < qntd ; i++){
        aleatorio = rand() % 100;
        printf("[%d] ",aleatorio);
        p[i] = aleatorio;
    }
    quicksort(p,0,qntd-1);
    printf("\nQuicksort : \n");
    for(i = 0; i < qntd; i++)
        printf("[%d] ",p[i]);
    free(p);
    return 0;
}