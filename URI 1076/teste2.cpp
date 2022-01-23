#include <bits/stdc++.h>
#include <iostream>
using namespace std;
//accepted
int V, ResFinal, seen[49];
vector <int> adj[49];

void dfsTree(int u) { 
    seen[u] = 1;
	for(int v : adj[u]) {
		if(seen[v]) continue;
		ResFinal += 2;
        dfsTree(v);
	}

}

void reseta_arvore(){
    for (auto& v : adj) {
        v.clear();
    }
}


int main(){
    int T, N, A, inicio, x, y;
    //T casos teste, N primeiro nodo, V qntd vertices, A qntd arestas

    scanf("%d",&T);

    for(int i = 0; i < T; i++){
        memset(seen, 0, sizeof(seen));
        scanf("%d",&inicio);
        scanf("%d %d",&V, &A);
        ResFinal = 0;
        for(int j = 0; j < A;j++){
            scanf("%d %d", &x, &y);
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        dfsTree(inicio);
        printf("%d\n",ResFinal);
        reseta_arvore();
    }
}