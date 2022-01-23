#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define N 201


int main(){
    int i,j, consumo, moradores, media[N], n;
    int cidade = 1, total_moradores, total_consumo; 
    int consumo_medio;
    double temp;
    bool b = false; //para printar '\n'

    while(true){
        cin >> n;
        if(n == 0) break;
        
        if(b) printf("\n"); 
        b = true;

        total_moradores = 0;
        total_consumo = 0;
        memset(media, 0, sizeof(media)); //zera todas as posicoes

        for(i = 0; i < n; i++){
            cin >> moradores >> consumo;

            total_moradores += moradores;
            total_consumo += consumo;

            media[consumo/moradores] += moradores; 
            //desse jeito a propria posicao no vetor eh a media
            //armazenando a quantidade de moradores apenas
        }

        printf("Cidade# %d:\n", cidade);
        cidade++;

        for(i = 0, j = 0; i < N;i++){
            //exibindo a quantidade de moradores primeiro
            //e depois a media(posicao)
            if(media[i] > 0){
                if(j != 0)
                    printf(" ");
                printf("%d-%d",media[i],i);
                j = 1;
            }
        }
        printf("\n");
    
        temp = ((double)total_consumo/total_moradores)*100;
        consumo_medio = temp;
        temp = consumo_medio/100.0;

        printf("Consumo medio: %.2f m3.\n",temp);
    }
}