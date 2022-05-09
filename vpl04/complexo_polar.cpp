// Copyright 2022 Universidade Federal de Minas Gerais (UFMG)

#include "complexo.h"

#include <cmath>

Complexo::Complexo() {
  real_ = 0;
  imag_ = 0;
}

Complexo::Complexo(double a, double b) {
  real_ = sqrt(a*a + b*b);
  imag_ = atan(b/a);
}

double Complexo::real() {
  return real_;
}

double Complexo::imag() {
  return imag_;
}

bool Complexo::igual(Complexo x) {
  return (x.real() == real() && x.imag() == imag());
}

void Complexo::Atribuir(Complexo x) {
  x.real_ = real(); // real_ = x.real();
  x.imag_ = imag(); //o complexo que está chamando a função é atribuido ao que é passado como argumento;  imag_ = x.imag(); - o complexo que está passado como argumento é atribuido ao que está chamando a função.
}

double Complexo::modulo() {
  return real();
}

Complexo Complexo::conjugado() {
  Complexo c;
  c.real_ = real();
  c.imag_ = -imag();
  return c;
}

Complexo Complexo::simetrico() {
  Complexo c;
  c.real_ = -real();
  c.imag_ = -imag();
  return c;
}

Complexo Complexo::inverso() {
  Complexo i;
  i.real_ = 1.0/real();
  i.imag_ = -imag();
  return i;
}

Complexo Complexo::somar(Complexo y) {
  Complexo s;
  s.real_ = real()*cos(imag()) - y.real()*cos(y.imag());
  s.imag_ = real()*sin(imag()) - y.real()*sin(y.imag());
  return s;
}

Complexo Complexo::subtrair(Complexo y) {
  Complexo s;
  s.real_ = real()*cos(imag()) + y.real()*cos(y.imag());
  s.imag_ = real()*sin(imag()) + y.real()*sin(y.imag());
  return s;
}

Complexo Complexo::multiplicar(Complexo y) {
  Complexo p;
  p.real_ = real()*y.real();
  p.imag_ = imag() + y.imag();
  return p;
}

Complexo Complexo::dividir(Complexo y) {
  Complexo d;
  d.real_ = real()/y.real();
  d.imag_ = imag() - y.imag();  
  return d;
}
