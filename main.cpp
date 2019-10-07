#include <cmath>
#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <cstdlib>

#include "complejo.h"
#include "complejo.cpp"
#include "array.h"
#include "fourier.h"


#include "cmdline.h"
#include "cmdline.cc"
using namespace std;


/**************** Prototipos ******************/
static void opt_input(string const &);
static void opt_output(string const &);
static void opt_method(string const &);
static void opt_help(string const &);


/**************** Elementos globales ******************/
static option_t options[] = {
	{1, "i", "input", "-", opt_input, OPT_DEFAULT},
	{1, "o", "output", "-", opt_output, OPT_DEFAULT},
	{1, "m", "factor", "dft", opt_method, OPT_DEFAULT},
	{0, "h", "help", NULL, opt_help, OPT_DEFAULT},
	{0, },
};

static string method;
static istream *iss = 0;	// Input Stream (clase para manejo de los flujos de entrada)
static ostream *oss = 0;	// Output Stream (clase para manejo de los flujos de salida)
static fstream ifs; 		// Input File Stream (derivada de la clase ifstream que deriva de istream para el manejo de archivos)
static fstream ofs;		// Output File Stream (derivada de la clase ofstream que deriva de ostream para el manejo de archivos)



/*****************************************************/

static void
opt_input(string const &arg)
{
	// Si el nombre del archivos es "-", usaremos la entrada
	// est�ndar. De lo contrario, abrimos un archivo en modo
	// de lectura.
	//
	if (arg == "-") {
		iss = &cin;
	}
	else {
		ifs.open(arg.c_str(), ios::in);
		iss = &ifs;
	}

	// Verificamos que el stream este OK.
	//
	if (!iss->good()) {
		cerr << "cannot open "
		     << arg
		     << "."
		     << endl;
		exit(1);
	}
}

static void
opt_output(string const &arg)
{
	// Si el nombre del archivos es "-", usaremos la salida
	// est�ndar. De lo contrario, abrimos un archivo en modo
	// de escritura.
	//
	if (arg == "-") {
		oss = &cout;
	} else {
		ofs.open(arg.c_str(), ios::out);
		oss = &ofs;
	}

	// Verificamos que el stream este OK.
	//
	if (!oss->good()) {
		cerr << "cannot open "
		     << arg
		     << "."
		     << endl;
		exit(1);
	}
}

static void
opt_method(string const &arg)
{
	if (arg == "dft"){
		method = arg;
	}else if(arg == "idft"){
		method = arg;
	}else{
		cerr << "Comando '"<< arg << "' inválido - Solo se permite dft o idft"
		     << endl;
		exit(1);
	}
}

static void
opt_help(string const &arg)
{
	cout << "cmdline [-m method] [-i file] [-o file]"
	     << endl;
	exit(0);
}


static void fourier(istream *is, ostream *os) {

    (*os) << fixed;      //Para que no imprima en notación científica.
    (*os).precision(2);  //Para imprimir con dos decimales.
    while( *is ) {

        Array <Complejo> x; 
        int c = is->get();
        int d;
        size_t i = 0;
        bool line_error = false;

        while( c != '\n'  && c != EOF ){

            if( i >= x.getSize() ){
                x.expand(x.getSize() * 2);
            }

            is->putback(c);
            *is >> x[i];

            if((is->rdstate() & ifstream::badbit) !=0){
                
                is->clear();
                line_error = true;
                i = 0;
                c = is->get();
                while ( c != '\n' && c != EOF){
                    c = is->get();
                }
                break;
            }
            i++;

            c = is->get();

            while ( c == ' ' ) {
                c = is->get();   // Para que no rompa cuando lee espacios al final
            } 
            

        }

        c = is->get();               

        while( c == '\n' || c == ' ' ) { 
            c = is->get();           // Para saltear lineas en blanco o llenas de espacios
        }                                   
        is->putback(c);

        if( line_error ) {
        	(*os) << "Error: los argumentos de esta línea no son válidos." <<endl;
            line_error = false;
            
        } else if( i == 0 ){}
        
        else {
			Array <Complejo> y;

			if( method == "dft")
            	y = DFT(x, i);
			else
				y = IDFT(x, i);

            for( int k = 0; k < y.getSize(); k++ ) {
                *os << y[k] << ' ';
            }
			*os << endl;
        }        
    };
}

int main(int argc, char * const argv[])
{
    cmdline cmdl(options);	// Objeto con parametro tipo option_t (struct) declarado globalmente. Ver l�nea 51 main.cc
	cmdl.parse(argc, argv); // Metodo de parseo de la clase cmdline
    fourier(iss, oss);
}



    
