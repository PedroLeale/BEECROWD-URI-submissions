#include<bits/stdc++.h>
#include <iostream>
using namespace std;

void reverse_string(string &str)
{
    int n = str.length();
    //troca as posicoes entre os caracteres equivalentes
    for(int i = 0; i < n/2;i++)
        swap(str[i],str[n-i-1]);
}
//URI 1024
int main(){
    int N,i,j;
    vector<string> palavra;
    string str;
    cin >> N;
    cin.sync(); //limpa buffer
    for(i = 0; i < N; i++){
        getline(cin,str);
        palavra.push_back(str);
    }
    for(i = 0; i < N; i++){
        for(j = 0; j < palavra[i].length(); j++){
            if( (palavra[i][j] > 64 && palavra[i][j] < 91) || (palavra[i][j] > 96 && palavra[i][j] < 123) ){
                palavra[i][j] = palavra[i][j] + 3;
            }
        }
        reverse_string(palavra[i]); 
        for(j = (palavra[i].length())/2; j < palavra[i].length(); j++){
            palavra[i][j] = palavra[i][j] - 1;
        }
    }
    for(i = 0; i < N; i++){
        cout << palavra[i] << '\n';
    }
}