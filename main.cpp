#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include "complejo.h"
#include "complejo.cpp"
#include "array.h"
#include "fourier.h"

using namespace std;

int main()
{
    cout << fixed;      //Para que no imprima en notación científica.
    cout.precision(2);  //Para imprimir con dos decimales.

    ifstream input_file;
    input_file.open("prueba.txt", ifstream::in);

    vector <Complejo> x; 
    Complejo aux;

    while( input_file ) {

        int c = input_file.get();
        x.clear();
 
        while( c != '\n' && c != EOF ){

            input_file.putback(c);
            input_file >> aux;
            x.push_back( aux );
            
            c = input_file.get();
        }

        vector <Complejo> y = DFT(x);

        if( input_file ) {
            std::cout << '\n' << "\e[92m Resultado de la linea \e[0m" << endl;

            for( int k = 0; k < y.size(); k++ ) {
                std::cout << y[k] << endl;
            }
        }
    };

    input_file.close();
    return 0;
}



    
