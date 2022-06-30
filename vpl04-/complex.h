#ifndef COMPLEX_H
#define COMPLEX_H

class Complex{
    private:
        double real;
        double imag;
    public:
        void cart2pol(double module, double argument);
        void print();
};

#endif
