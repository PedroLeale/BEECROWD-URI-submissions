#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int num_calls = 0;

int fib(int n){
    if(n <= 1)
        return n;
    else{
        num_calls += 2;
        return fib(n-1) + fib(n-2);
    }
}

int main(){
    int N,X,resultado;
    scanf("%d",&N);
    while(N--){
        scanf("%d",&X);
        resultado = fib(X);
        printf("fib(%d) = %d calls = %d\n",X,num_calls,resultado);
        num_calls = 0;
    }
}
