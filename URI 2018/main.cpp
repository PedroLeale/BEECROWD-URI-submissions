#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct PAIS{
    string nome;
    int ouro;
    int prata;
    int bronze;
};

bool compara(PAIS x, PAIS y){
    if (x.ouro == y.ouro){
        if (x.prata == y.prata){
            if (x.bronze == y.bronze){
                return x.nome < y.nome;
            }
            else{
                return x.bronze > y.bronze;
            }
        }
        else{
            return x.prata > y.prata;
        }
    }
    else{
        return x.ouro > y.ouro;
    }
}

int main()
{
    struct PAIS pais[600];
    string prova, ouro, prata, bronze;
    map<string, int> mapa;
    int j = 0;
    while (getline(cin, prova)){
        //---------------------------------------------------------------------------
        getline(cin, ouro);
        if (mapa[ouro] == 0){
            pais[j].nome = ouro;
            pais[j].ouro += 1;
            j++;
            mapa[ouro] = j;
        }
        else{
            pais[mapa[ouro] - 1].ouro = pais[mapa[ouro] - 1].ouro + 1;
        }
        //----------------------------------------------------------------------------
        getline(cin, prata);
        if (mapa[prata] == 0){
            pais[j].nome = prata;
            pais[j].prata += 1;
            j++;
            mapa[prata] = j;
        }
        else{
            pais[mapa[prata] - 1].prata = pais[mapa[prata] - 1].prata + 1;
        }
        //-----------------------------------------------------------------------------
        getline(cin, bronze);
        if (mapa[bronze] == 0){
            pais[j].nome = bronze;
            pais[j].bronze += 1;
            j++;
            mapa[bronze] = j;
        }
        else{
            pais[mapa[bronze] - 1].bronze = pais[mapa[bronze] - 1].bronze + 1;
        }
    }
    //-----------------------------------------------------------------------------
    sort(pais, pais + j, compara);
    printf("Quadro de Medalhas\n");
    for (int i = 0; i < j; i++){
        cout << pais[i].nome << " " << pais[i].ouro << " " << pais[i].prata << " " << pais[i].bronze << endl;
    }

    return 0;
}
