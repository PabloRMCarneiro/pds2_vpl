#include "fila.h"

Fila::Fila(){
    primeiro_ = nullptr;
    ultimo_ = nullptr;
}
string Fila::primeiro(){
    return primeiro_->chave;
}

string Fila::ultimo(){
    return ultimo_->chave;
}

bool Fila::vazia(){
    return (primeiro_ == nullptr);
}

void Fila::Inserir(string k){
    No* aux1 = new No {k, nullptr};

    if(primeiro_ == nullptr){
        primeiro_= aux1;
        ultimo_ = aux1;
    }
    else{
        ultimo_->proximo = aux1;
        ultimo_ = aux1;
    }
    
}

void Fila::Remover(){
    No* aux2 = primeiro_;
    primeiro_ = primeiro_->proximo;
    delete aux2;
}

int Fila::tamanho(){
    int cont = 0;
    No* aux3  = primeiro_;
    while( aux3 != nullptr){
        cont++;
        aux3 = aux3->proximo; 
    }  
    delete aux3;
    return cont;
}

Fila::~Fila(){
    while(!vazia())
        Remover();
}
