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

static void
saltar_lineas_blanco( ifstream &input_file )
{
    int c;
    c = input_file.get();                   // 
                                            //
        while( c == '\n' || c == ' ' ) {    //
            c = input_file.get();           // Para saltear lineas en blanco o llenas de espacios
        }                                   //
        input_file.putback(c);              //

}

static void
saltar_espacios( int &c ,ifstream &input_file )
{
    
    while ( c == ' ' ) {        //
        c = input_file.get();   // Para que no rompa cuando lee espacios al final
    } 
}



int main()
{
    cout << fixed;      //Para que no imprima en notación científica.
    cout.precision(2);  //Para imprimir con dos decimales.

    ifstream input_file;
    input_file.open("prueba.txt", ifstream::in);
    

    while( input_file ) {

        Array <Complejo> x; 
        int c = input_file.get();
        int d;
        size_t i = 0;
        bool line_error = false;

        while( c != '\n'  && c != EOF ){

            if(i>=x.getSize()){
                //cout << "Tamaño inicial de x:" <<x.getSize() <<'\n';
                x.expand(x.getSize() * 2);
                //cout << "Tamaño final de x:" <<x.getSize() <<'\n';
            }

            input_file.putback(c);
            input_file >> x[i];

            if((input_file.rdstate() & ifstream::badbit) !=0){
                
                input_file.clear();
                line_error = true;
                i = 0;
                c = input_file.get();
                while ( c != '\n' && c != EOF){
                    c = input_file.get();
                }
                break;
            }
            i++;

            c = input_file.get();

            saltar_espacios( c, input_file );                          //
            

        }

        saltar_lineas_blanco( input_file );

        if( line_error ) {
            cout << '\n' << "Error: los resultados de esta línea no son válidos."<<'\n';
            line_error = false;
            
        } else if( i == 0 ){}
        
        else {
            Array <Complejo> y = DFT(x, i);
            std::cout << '\n' << "\e[92m Resultado de la linea: \e[0m" << '\n';

            for( int k = 0; k < y.getSize(); k++ ) {
                std::cout << y[k] << '\n';
            
            }
        }        
    };

    input_file.close();
    return 0;
}



    
