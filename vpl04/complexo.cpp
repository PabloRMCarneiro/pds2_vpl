// Copyright 2022 Universidade Federal de Minas Gerais (UFMG)

#include "complexo.h"

#include <cmath>

Complexo::Complexo() {
  real_ = 0;
  imag_ = 0;
}

Complexo::Complexo(double a, double b) {
  real_ = a;
  imag_ = b;
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
  x.real_ = real();
  x.imag_ = imag();
}

double Complexo::modulo() {
  return sqrt(pow(real(), 2) + pow(imag(), 2));
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
  i.real_ = real()/modulo();
  i.imag_ = imag()/modulo();
  return i;
}

Complexo Complexo::somar(Complexo y) {
  Complexo s;
  s.real_ = real() + y.real();
  s.imag_ = imag() + y.imag();
  return s;
}

Complexo Complexo::subtrair(Complexo y) {
  Complexo s;
  s.real_ = real() - y.real();
  s.imag_ = imag() - y.imag();
  return s;
}

Complexo Complexo::multiplicar(Complexo y) {
  Complexo p;
  p.real_ = real()*y.real() - imag()*y.imag();
  p.imag_ = real()*y.imag() + imag()*y.real();
  return p;
}

Complexo Complexo::dividir(Complexo y) {
  Complexo d;
  d.real_ = (real()*y.real() + imag()*y.imag())/(pow(y.real(), 2) + pow(y.imag(), 2));
  d.imag_ = (imag()*y.real() - real()*y.imag())/(pow(y.real(), 2) + pow(y.imag(), 2));  
  return d;
}
