#include <iostream>
#include "complex.h"

using namespace std;

int main(){

    Complex aux;
    double module, argument;

    while(cin >> module >> argument){
        aux.cart2pol(module, argument);
        aux.print();
    }

    return 0;
}