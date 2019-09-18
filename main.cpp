#include <iostream>
#include <cmath>
#include "complejo.h"
#include "complejo.cpp"
#include "array.cpp"
#include "array.h"

using namespace std;

int main()
{
    array x(4);
    array y; 

    for(int i=0; i<4; i++){
        std::cin >> x[i];
    }


    for(int k=0; k<x.getSize(); k++){
        for(int n=0; n<x.getSize(); n++){
            complejo aux(cos(2*M_PI*n*k/x.getSize()),(-1)*sin(2*M_PI*n*k/x.getSize()));
            y[k] += x[n] * aux;
        }
    }

    for(int i=0; i<x.getSize(); i++){
        std::cout << y[i] << endl; 
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