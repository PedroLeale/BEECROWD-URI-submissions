#include <bits/stdc++.h>
#include <iostream>
using namespace std;
 //accepted
int main() {
 
    int X;
    
    scanf("%d",&X);
    
    for(int i = 1; i <= X;i++){
        if( i%2 != 0 )
            printf("%d\n",i);
    }

    return 0;
}