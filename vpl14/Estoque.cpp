#include "Estoque.hpp"


void Estoque::add_mercadoria(const std::string& mercadoria, unsigned int qtd) {
  estoque.find(mercadoria) == estoque.end() ? estoque[mercadoria] = qtd : estoque[mercadoria] += qtd;
}

void Estoque::sub_mercadoria(const std::string& mercadoria, unsigned int qtd) {
  if (estoque[mercadoria] < qtd) {
    std::cout << mercadoria << " insuficiente" << std::endl;
  } else {
    estoque[mercadoria] -= qtd;
  }
}

unsigned int Estoque::get_qtd(const std::string& mercadoria) const {
    if(estoque.find(mercadoria) == estoque.end())
        return 0;
    else
        return estoque.find(mercadoria)->second;
}

void Estoque::imprime_estoque() const {
  std::map<std::string, unsigned int>::const_iterator it;
  for (auto it = estoque.begin(); it != estoque.end(); it++) {
    std::cout << it->first << ", " << it->second << std::endl;
  }
}

Estoque& Estoque::operator += (const Estoque& rhs) {
  std::map<std::string, unsigned int>::const_iterator it;
  for (it = rhs.estoque.begin(); it != rhs.estoque.end(); it++) {
    add_mercadoria(it->first, it->second);
  }
  return *this;
}

Estoque& Estoque::operator -= (const Estoque& rhs) {
  
    std::map<std::string, unsigned int>::const_iterator it;
    for (it = rhs.estoque.begin(); it != rhs.estoque.end(); it++) {
      sub_mercadoria(it->first, it->second);
    }
    return *this;
}

bool operator < (Estoque& lhs, Estoque& rhs) {

    int SameGoods = 0;
    int aux = 0;
    std::map<std::string, unsigned int>::const_iterator it_lhs;
    std::map<std::string, unsigned int>::const_iterator it_rhs;
    for (it_lhs = lhs.estoque.begin(); it_lhs != lhs.estoque.end(); it_lhs++) {
        for (it_rhs = rhs.estoque.begin(); it_rhs != rhs.estoque.end(); it_rhs++) {
          if(it_rhs->first == it_lhs->first){
            SameGoods++;
            if (it_rhs->second > it_lhs->second) aux++;
          }
        }
    }
    if(SameGoods != lhs.estoque.size()){
      return false;
    }
    else if(aux == SameGoods){
      return true;
    } else {
      return false;
    }
}

bool operator > (Estoque& lhs, Estoque& rhs) {

    int SameGoods = 0;
    int aux = 0;

    std::map<std::string, unsigned int>::const_iterator it_lhs;
    std::map<std::string, unsigned int>::const_iterator it_rhs;

    for (it_lhs = lhs.estoque.begin(); it_lhs != lhs.estoque.end(); it_lhs++) {
        for (it_rhs = rhs.estoque.begin(); it_rhs != rhs.estoque.end(); it_rhs++) {
          if(it_rhs->first == it_lhs->first){
            SameGoods++;
            if (it_rhs->second < it_lhs->second) aux++;
          }
        }
    }
    if(SameGoods != rhs.estoque.size()){
      return false;
    }
    else if(aux == SameGoods){
      return true;
    } else {
      return false;
    }
}