#include <iostream>
#include <complex>
#include <map>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

int main(){
    double a, b, c, delta, x1, x2;

    map <double, double> s;  
    
    vector <double> coeficientes();
    vector <double> raizes();

    /*cout<< "Infomre o coeficiente a: ";
    cin >> a;

    cout <<"Informe o coeficiente b: ";
    cin >> b;

    cout << "Informe o coeficiente c: ";
    cin >> c; */

    while( cin >> coeficientes >> raizes){
        s[coeficientes] = raizes;
    }


    delta = pow(b,2) - 4*a*c;

    if( delta > 0){
        x1 = (-b + sqrt(delta))/(2*a);
        x2 = (-b - sqrt(delta))/(2*a);
        cout << "x1: " << x1 << " x2: " << x2 << endl;
    }

    if(delta == 0){
        x1 = -b/(2*a);
        x2 = x1;
        cout << "x1: " << x1 << " x2: " << x2 << endl;
    }

    if(delta < 0){
        double aux = abs(delta); // modulo de delta
        double real, imag_x1, imag_x2;
        real = -b/(2*a);
        imag_x1 = sqrt(aux)/(2*a); // (parte real, parte imaginária)
        imag_x2 = -sqrt(aux)/(2*a);

        cout << "x1: " << real << "+" << imag_x1 << "*i x2: " << real << imag_x2 <<"*i" << endl;

    }

    return 0;
}