#include "vetor.h"


Vetor::Vetor(int inicio, int fim){
    inicio_ = inicio;
    size_ = abs(fim - inicio) + 1;
    elementos_ = new string [size_];

}

void Vetor::atribuir(int i, string valor){
    elementos_[abs(i - inicio_)] = valor;
}

string Vetor::valor(int i) const{
    string value = elementos_[abs(inicio_ - i)];
    return value;
}


Vetor::~Vetor(){
    delete [] elementos_;
}
