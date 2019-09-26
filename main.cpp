#include <iostream>
#include <cmath>
#include <iomanip>
#include "complejo.h"
#include "complejo.cpp"
#include "array.h"
#include "fourier.h"

using namespace std;

int main()
{
    Array <Complejo> x(4);
    Array <Complejo> y(4);

    std::cout << std::fixed;

    for(int i=0; i<4; i++){
        std::cin >> x[i];
    }

    y = DFT(x);
    

    for(int i=0; i<x.getSize(); i++){
        std::cout << y[i] << endl; 
    }

    for(int i=0; i<4; i++){
        std::cin >> y[i];
    }

    x = IDFT(y);

    for(int i=0; i<y.getSize(); i++){
        std::cout << x[i] << endl; 
    }


    // cout << "a vale" << endl;
    // std:: cout << "(" << a.GetReal() << "," << a.GetImag() << ")" << endl;

    // cout << " b vale" << endl;
    // std:: cout << "(" << b.GetReal() << "," << b.GetImag() << ")" << endl;

    // cout << " c vale" << endl;
    // std:: cout << "(" << c.GetReal() << "," << c.GetImag() << ")" << endl;

    // cout << "a=b+c" << endl;

    // a = b + c;

    // cout << "resultado: a vale" << endl;
    // std:: cout << "(" << a.GetReal() << "," << a.GetImag() << ")" << endl;

    // cout << "suma el complejo b y el real 5" << endl;

    // a = b + 5; //

    // std:: cout << "(" << a.GetReal() << "," << a.GetImag() << ")" << endl;

    return 0;
}