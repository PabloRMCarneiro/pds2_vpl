#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*void imprimir( const vector <string> &v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << endl;
    }
}*/
void varredura( const vector <string> &p){
    
    vector <int> cont(p.size());
    int maior = 0, indice;

    for(int k = 0; k< p.size(); k++){ // inicializar o vetor de contagem -> ele vai indicar o índice 
        cont[k] = 0; // inicializa com -1 pois todas as palavras vão se contar uma vez
    }

    for(int i = 0; i < p.size(); i++){ 
        for(int j = 0; j < p.size(); j++){
            if(p[i] == p[j]){
                cont[i] += 1;
            }
        }
    }

    for(int n = 0; n < p.size(); n++){
        if(maior < cont[n]){ // verificação do maior valor dos vetores
            maior = cont[n]; 
            indice = n; // que indica que a palavra que mais se repetiu encontra-se no indice do maior valor do contador
        }
    }
    cout <<":[" << p[indice] <<"]" << " - REPETIU: " << cont[indice] << "x" <<endl; // imprime a palavra que mais se repetiu
}

int main(){
    vector <string> s;
    string aux;
    while( cin >> aux){
        s.push_back(aux);
    }
    //imprimir(s);
    varredura(s);

}