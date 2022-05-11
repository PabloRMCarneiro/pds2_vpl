// Copyright 2022 Universidade Federal de Minas Gerais (UFMG)

#include "complexo.h"

#include <cmath>

Complexo::Complexo() {
  real_ = 0;
  imag_ = 0;
}

Complexo::Complexo(double a, double b) {
  real_ = sqrt(a*a + b*b);
  imag_ = atan2(b,a);
}

double Complexo::real() {
  return real_*cos(imag_);
}

double Complexo::imag() {
  return real_*sin(imag_);
}

bool Complexo::igual(Complexo x) {
  return (x.real_ == real_ && x.imag_ == imag_);
}

void Complexo::Atribuir(Complexo x) {
  x.real_ = real_; 
  x.imag_ = imag_; 
}

double Complexo::modulo() {
  return real_;
}

Complexo Complexo::conjugado() {
  Complexo c;
  c.real_ = real_;
  c.imag_ = -imag_;
  return c;
}

Complexo Complexo::simetrico() {
  Complexo c;
  c.real_ = -real_;
  c.imag_ = -imag_;
  return c;
}

Complexo Complexo::inverso() {
  Complexo i;
  i.real_ = 1.0/real_;
  i.imag_ = -imag_;
  return i;
}

Complexo Complexo::somar(Complexo y) {
  Complexo s;
  s.real_ = real_*cos(imag_) - y.real_*cos(y.imag_);
  s.imag_ = real_*sin(imag_) - y.real_*sin(y.imag_);
  return s;
}

Complexo Complexo::subtrair(Complexo y) {
  Complexo s;
  s.real_ = real_*cos(imag_) + y.real_*cos(y.imag_);
  s.imag_ = real_*sin(imag_) + y.real_*sin(y.imag_);
  return s;
}

Complexo Complexo::multiplicar(Complexo y) {
  Complexo p;
  p.real_ = real_*y.real_;
  p.imag_ = imag_ + y.imag_;
  return p;
}

Complexo Complexo::dividir(Complexo y) {
  Complexo d;
  d.real_ = real_/y.real_;
  d.imag_ = imag_ - y.imag_;  
  return d;
}
