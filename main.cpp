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
    cout << fixed;      //Para que no imprima en notación científica.
    cout.precision(2);  //Para imprimir con dos decimales.

    ifstream input_file;
    input_file.open("prueba.txt", ifstream::in);

    while( input_file ) {

        Array <Complejo> x; 
        int c = input_file.get();
        size_t i = 0;
        while( c != '\n' && c != EOF ){

            input_file.putback(c);
            input_file >> x[i];
            if((input_file.rdstate() & ifstream::badbit) !=0){
                cout << "Error: los resultados de esta línea no son válidos."<<'\n';
                input_file.clear();
                i = 0;
                c = input_file.get();
                while ( c != '\n' && c != EOF){
                    c = input_file.get();
                }
                break;
                //input_file.putback(c);
            }
            i++;
            c = input_file.get();

        }

        Array <Complejo> y = DFT(x, i);

        
        std::cout << '\n' << "\e[92m Resultado de la linea: \e[0m" << '\n';

        for( int k = 0; k < y.getSize(); k++ ) {
            std::cout << y[k] << '\n';
        }
        
    };

    input_file.close();
    return 0;
}



    
