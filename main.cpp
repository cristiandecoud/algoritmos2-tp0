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

    string line;
    size_t line_count = 0;

    while (getline(input_file, line)){
        line_count++;
    }
    
    input_file.clear();
    input_file.seekg(0, input_file.beg);    //Vuelvo al comienzo del archivo.
    
    Array <Complejo> x(500);

    for(int i=0; i<line_count; i++){

        size_t j = 0;
        int c = input_file.get();

        while(c != '\n' && c != EOF){

            input_file.putback(c);
            input_file >> x[j];
            j++;
            c = input_file.get();
            
        }

        std::cout << '\n' << "\e[92m Resultado de la linea \e[0m" << i  << endl;

        Array <Complejo> y = DFT(x, j);

        //   std::cout << '\n' << y[0] << '\n' << endl;
        for( int k = 0; k < y.getSize(); k++ ) {
            std::cout << y[k] << endl;
        }
    }

    input_file.close();
    return 0;
}



    
