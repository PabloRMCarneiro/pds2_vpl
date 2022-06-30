#include "complex.h"
#include <iostream>
#include <cmath>

using namespace std;


void Complex::cart2pol(double module, double argument){
    this->real = module*cos(argument);
    this->imag = module*sin(argument);
   /* if(argument == 0){
        this->real = module*cos(2*M_PI);
        this->imag = module*sin(2*M_PI);
    }
    */
}

void Complex::print(){
    if(this->imag == 0.0) cout << this->real << endl;
    if(this->imag > 0.0 ) cout << this->real << " + " << this->imag << "i" << endl;
    if(this->imag < 0.0) cout << this->real << " - " << -this->imag << "i" << endl;
}