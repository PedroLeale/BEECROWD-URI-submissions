#include<bits/stdc++.h>
#include <iostream>
using namespace std;

void reverse_string(char *x,int begin, int end)
{
   char c;
   if (begin >= end)
      return;

   c          = *(x+begin);
   *(x+begin) = *(x+end);
   *(x+end)   = c;

   reverse_string(x, ++begin, --end);
}
//URI 1024
int main(){
    int N,i,j;
    scanf("%d",&N);
    char pa[N][1000];
    for(i = 0; i < N; i++){
        scanf(" %[^\n]s",pa[i]);
    }
    for(i = 0; i < N; i++){
        for(j = 0; pa[i][j] != '\0'; j++){
            if( (pa[i][j] > 64 && pa[i][j] < 91) || (pa[i][j] > 96 && pa[i][j] < 123) ){
                pa[i][j] = pa[i][j] + 3;
            }
        }
        //reverse_string(pa[i],0,strlen(pa[i])-1); forma recursiva
        //procedimental
        char pa_inversa[1000];
        strcpy(pa_inversa,pa[i]);
        int x = strlen(pa_inversa)-1;
        for(j = 0; pa[i][j] != '\0'; j++,x--){
            pa[i][j] = pa_inversa[x];
        }
        //---------------------------------------
        for(j = strlen(pa[i])/2; pa[i][j] != '\0'; j++){
            pa[i][j] = pa[i][j] - 1;
        }
    }
    for(i = 0; i < N; i++){
        printf("%s\n",pa[i]);
    }
}