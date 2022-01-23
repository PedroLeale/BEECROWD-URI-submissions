#include<bits/stdc++.h>
#include <iostream>
using namespace std;

class Hash{
    int BUCKET;
    list<int> *table;

    public:
        Hash(int V); //construtor

        void insertItem(int key);

        int HashFunction(int x) { 
            return (x % BUCKET); 
        }

        void displayHash();
};

Hash::Hash(int b){
    this->BUCKET = b; 
    table = new list<int>[BUCKET];
}

void Hash::insertItem(int key){
    int index = HashFunction(key);
    table[index].push_back(key);
}

void Hash::displayHash() {
    for (int i = 0; i < BUCKET; i++) {
        cout << i;
    for (auto x : table[i])
        cout << " -> " << x;
    cout << " -> \\" << endl;
    }
}


int main(){
    int N,M,C,c; //N = casos teste, M = tamanho da tabela/buckets, C = numero de chaves, c = chaves
    scanf("%d",&N);
    while(N > 0){
        scanf("%d %d",&M,&C);
        Hash h(M);
        while(C--){
            scanf("%d",&c);
            h.insertItem(c);
        }   
        h.displayHash();
        if(N != 1)
            printf("\n");
        N--;
    }
    return 0;
}