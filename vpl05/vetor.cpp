#include "vetor.h"
#include <cassert>

Vetor::Vetor(int inicio, int fim){
   
    if (fim < inicio)
        throw ExcecaoIntervaloInvalido {inicio, fim};
    inicio_ = inicio;
    fim_ = fim;
    elementos_ = new string [fim - inicio + 1];
    inicializado_ = new bool [fim - inicio + 1];
}
void Vetor::atribuir(int i, string valor){
    
    if(i < inicio_ || i > fim_)
        throw ExcecaoIndiceForaDoIntervalo {inicio_, fim_, i};
    elementos_[i - inicio_] = valor;
    inicializado_[i - inicio_] = true;
}
string Vetor::valor(int i) const{
    
    if(i < inicio_ || i > fim_)
        throw ExcecaoIndiceForaDoIntervalo {inicio_, fim_, i};
    if(!inicializado_[i - inicio_])
        throw ExcecaoIndiceNaoInicializado {i};
    
    assert(i >= inicio_ && i <= fim_);
    return elementos_[i - inicio_];
}
Vetor::~Vetor(){
    delete [] elementos_;
    delete [] inicializado_;
}
