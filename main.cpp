#include <cmath>
#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <cstdlib>

#include "data.h"
#include "complejo.h"
#include "array.h"
#include "fourier.h"
#include "cmdline.h"


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
	{1, "m", "method", "dft", opt_method, OPT_DEFAULT},
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
		cerr << "Comando invalido - Solo se permite dft o idft"
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




int main(int argc, char * const argv[])
{
    cmdline cmdl(options);	// Objeto con parametro tipo option_t (struct) declarado globalmente. Ver l�nea 51 main.cc
	cmdl.parse(argc, argv); // Metodo de parseo de la clase cmdline
    
	(*oss) << fixed;      //Para que no imprima en notación científica.
    (*oss).precision(5);  //Para imprimir con dos decimales.

	Array <Complejo> x;
	size_t i = 0;

	while ( * iss)
	{	
		if(validate_line(iss, oss, &i, x) == OK){
			Array <Complejo> y;

			if( method == "dft" )
           		y = DFT(x, i);
			else
				y = IDFT(x, i);

			print_data(y, oss);	
		}
	}
	ifs.close();
	ofs.close();

	iss = NULL;
	oss = NULL;


	return 0;
}



    
