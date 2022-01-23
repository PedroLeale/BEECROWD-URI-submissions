#include<bits/stdc++.h>
#include <iostream>
using namespace std;

#define N 100010//canais de 1 ate 100.000
//operacoes = +1 , -1 , *2 , *3 , /2
//canais = vertices do grafo, operacoes = arestas
int proibido[N], distancia[N]; 
int main(){
    int O,D,K,i;
    while(1){
        scanf("%d %d %d",&O,&D,&K);
        if(O == 0 && D == 0 && K == 0)
            break;
        int a;
        memset(proibido, 0, sizeof proibido);
        memset(distancia, -1, sizeof distancia); 
        queue<int> q;

        for(i = 0;i < K; i++){
            scanf("%d",&a);
            proibido[a] = 1;
        }
        
        distancia[O] = 0;
        q.push(O);
        while(!q.empty()){
            if(distancia[D] != -1)
                break;
            int u = q.front(); 
            q.pop(); 
            if(((u - 1 > 0) && !proibido[u-1]) && distancia[u-1] == -1 ){
                distancia[u-1] = distancia[u] + 1;
                q.push(u-1);
            }
            if(((u + 1 <= 100000 && !proibido[u+1])) && distancia[u+1] == -1 ){
                distancia[u+1] = distancia[u] + 1;
                q.push(u+1);
            }
            if(((u * 2 <= 100000) && !proibido[u*2]) && distancia[u*2] == -1 ){
                distancia[u*2] = distancia[u] + 1;
                q.push(u*2);
            }
            if(((u * 3 <= 100000) && !proibido[u*3]) && distancia[u*3] == -1 ){
                distancia[u*3] = distancia[u] + 1;
                q.push(u*3);
            }
            if(((u % 2 ==  0) && !proibido[u/2]) && distancia[u/2] == -1 ){
                distancia[u/2] = distancia[u] + 1;
                q.push(u/2);
            }

        }
        printf("%d\n",distancia[D]);
    }
    
}