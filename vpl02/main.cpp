#include <iostream>
#include <string>

using namespace std;

int main(){

    string s;
    

    while (cin >> s){

        int v[5] = {0, 0, 0, 0, 0}; // cada loop de while a contagem das vogais reinicia, cada posição do vetor representa as vogais

        for(int i = 0; i < s.size(); i++){ // faz um loop com o tamanho de cada string que irá ser recebida pelo cin e verifica quais vogais corresspondem a palavra, por fim acresecnta 1 no valor do vetor correspondente
            if(s[i] == 'a') v[0] += 1;
            if(s[i] == 'e') v[1] += 1;
            if(s[i] == 'i') v[2] += 1;
            if(s[i] == 'o') v[3] += 1;
            if(s[i] == 'u') v[4] += 1;
        }
        
        //impressão das vogais que compõe a palavra
        
        if(v[0] != 0) cout << "a = " << v[0] << endl;
        if(v[1] != 0) cout << "e = " << v[1] << endl;
        if(v[2] != 0) cout << "i = " << v[2] << endl;
        if(v[3] != 0) cout << "o = " << v[3] << endl;
        if(v[4] != 0) cout << "u = " << v[4] << endl;

    }

    return 0;
}