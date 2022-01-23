#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){
    
    vector<int> v;
    int i, x;

    while(cin >> x){
        v.push_back(x);
    }

    sort(v.begin(),v.end());

    if(v[0] * v[3] == v[1] * v[2])
        printf("S\n");
    else
        printf("N\n");
    
    return 0;
}