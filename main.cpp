#include <iostream>
#include "complejo.h"
#include "complejo.cpp"

using namespace std;

int main()
{
    complejo a, b(2,3) , c(b);

    cout << "a vale" << endl;
    std:: cout << "(" << a.GetReal() << "," << a.GetImag() << ")" << endl;

    cout << " b vale" << endl;
    std:: cout << "(" << b.GetReal() << "," << b.GetImag() << ")" << endl;

    cout << " c vale" << endl;
    std:: cout << "(" << c.GetReal() << "," << c.GetImag() << ")" << endl;

    cout << "a=b+c" << endl;

    a = b + c;

    cout << "resultado: a vale" << endl;
    std:: cout << "(" << a.GetReal() << "," << a.GetImag() << ")" << endl;

    cout << "suma el complejo b y el real 5" << endl;

    a = b + 5; //

    std:: cout << "(" << a.GetReal() << "," << a.GetImag() << ")" << endl;

    return 0;
}