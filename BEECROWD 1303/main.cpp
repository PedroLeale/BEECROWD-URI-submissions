#include <bits/stdc++.h>
#include <iostream>
using namespace std;
//accepted 

typedef struct time{
    int pontos;
    int marcados;
    int recebidos;
    int inscricao;
    double ca; //cesta average = pontos marcados/pontos recebidos

    void calculaCA(){
        if(recebidos == 0)
            ca = marcados;
         else
            ca = ((double) marcados / recebidos);
    }


    //empates na pontuação são resolvidos com cesta average
    //empates no cesta average são resolvidos com pontos marcados
    //persistindo empates, vence quem tem menor numero de inscrição

    bool operator < (time aux){
        if(pontos != aux.pontos) return pontos > aux.pontos;
        if(ca != aux.ca) return ca > aux.ca;
        if(marcados != aux.marcados) return marcados > aux.marcados;
        return inscricao < aux.inscricao;
    }

} times;


int main(){
    int n,h,i,x,y,z,w;
    //n = qntd de times, 0 = acabou, n*(n-1)/2 linhas de entrada após entrada de n
    times t[110]; // 0 <= n <= 100
    //h = instancia
    
    h = 1; // primeiro caso
    while(true){
        cin >> n;
        if(n == 0) break;

        //Zerando todos os valores---------------------
        for(i = 1; i <= n; i++){
            t[i].marcados = 0;
            t[i].recebidos = 0;
            t[i].pontos = 0;
            t[i].inscricao = i;
            t[i].ca = 0.0;
        }
        //--------------------------------------------
        for(i = 0;i < (n*(n-1)/2); i++){
            cin >> x >> y >> z >> w;

            //x,z inscricao dos times
            //y,z pontos de x e y
            t[x].marcados += y;
            t[x].recebidos += w;
            t[z].marcados += w;
            t[z].recebidos += y;

            //vitoria = 2 pts, derrota = 1 pt
            if(y > w){
                t[x].pontos += 2;
                t[z].pontos += 1;
            } else {
                t[z].pontos += 2;
                t[x].pontos += 1;
            }
            //--------------------------------------
        }
            for(i = 1;i <= n;i++)
                t[i].calculaCA();
            sort(t+1,t+n+1);
            //--------------------------------------
            if(h != 1) printf("\n");
            cout << "Instancia " << h << endl;
            h++; //contando para o proximo caso
            //--------------------------------------
            for(i = 1;i <= n; i++){
                cout << t[i].inscricao;
                if(i != n)
                   printf(" ");
            }
        printf("\n");
    }
}
