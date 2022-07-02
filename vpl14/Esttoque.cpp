#include <string>

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
  std::map<std::string, unsigned int>::const_iterator it = estoque.begin()++;
  while(it != estoque.end()) {
    std::cout << it->first << ", " << it->second << std::endl;
    it++;
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

    std::map<std::string, unsigned int>::const_iterator it;
    for (it = lhs.estoque.begin(); it != lhs.estoque.end(); it++) {
      if (rhs.get_qtd(it->first) < it->second) {
        return false;
      }
    }
    return true;
}

bool operator > (Estoque& lhs, Estoque& rhs) {

    std::map<std::string, unsigned int>::const_iterator it;
    for (it = lhs.estoque.begin(); it != lhs.estoque.end(); it++) {
      if (rhs.get_qtd(it->first) > it->second) {
        return false;
      }
    }
    return true;
}