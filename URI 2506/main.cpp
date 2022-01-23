#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
    
    int hora, minuto, critico, tempo_total; //tempo total sera contado em minutos
    int N, pac_critic;
    
    while(cin >> N){
        
        pac_critic = 0;
        tempo_total = 420; // 7 horas da manha em minutos

       while(N > 0){
           cin >> hora >> minuto >> critico;

            while(tempo_total < (hora*60) + minuto)
                tempo_total += 30; //O tempo só passa de 30 em 30, tem que ajustar o tempo total com o que o paciente chegou
            
            if(tempo_total - ((hora*60) + minuto) > critico)
                pac_critic++; //Quando o tempo foi ajustado no loop anterior ele criou uma diferença na relação dos tempos,
                //já que eram somados de 30 em 30, se a diferença do tempo total pra da hora que o paciente chegou for maior
                //quer dizer que chegou no estado crítico 
            tempo_total += 30; //Passar o tempo total em 30 minutos
            N--;
       }
        cout << pac_critic << endl;
    }

    return 0;
}