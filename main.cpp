#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <string>
#include "complejo.h"
#include "complejo.cpp"
#include "array.h"
#include "fourier.h"

using namespace std;

int main()
{
    Array <Complejo> x(4);
    string line = "Hello";
    size_t line_count = 0;

    std::cout << std::fixed;

    std::ifstream input_file;
    input_file.open("prueba.txt", ifstream::in);

    while (getline(input_file, line)){
        line_count++;
    }
    
    input_file.close();
    input_file.open("prueba.txt", ifstream::in);
    

    for(int i=0; i<1; i++){
        size_t j = 0;
        int c = input_file.get();   
            //std::cout << "hola" << c << endl;
        while(c != '\n' && c != EOF){
            input_file.putback(c);
            input_file >> x[j];
            cout << x[j];
            c = input_file.get();
            //if(c != ' '){
                //  if(c != EOF){
                //    std::cout << c << "Todo mal" <<endl;
                //}
            //}
            j++;
        }
        Array <Complejo> y = DFT(x);
        // for(int k=0; k<y.getSize(); k++){
        //     std::cout << y[k] << endl;
        // }
    }


    input_file.close();

    

    //y = DFT(x);
    

 

    // for(int i=0; i<4; i++){
    //     std::cin >> y[i];
    // }

    // x = IDFT(y);

    // for(int i=0; i<y.getSize(); i++){
    //     std::cout << x[i] << endl; 
    // }


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