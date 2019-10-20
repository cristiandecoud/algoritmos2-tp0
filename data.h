#ifndef _DATA_H_INCLUDED_
#define _DATA_H_INCLUDED_

typedef enum{
    OK,
    ERROR_NULL_POINTER,
    ERROR_INVALID_LINE,
    EMPTY_LINE
}status_t;

status_t st;

status_t validate_line(istream *is, ostream *os, size_t * i , Array <Complejo> &x) {

    int c = is->get();

// Para imprimir lineas en blanco o llenas de espacios y que
// el archivo de salida tenga la misma cantidad de lineas que el de entrada.
    while (c == '\n' || c == ' '){
        if(c == '\n'){
            (*os) << '\n';
            return EMPTY_LINE;
        }
        c = is->get();
    }

    bool line_error = false;
	size_t vect_size = 0;
 
    if ( i==NULL )
        return ERROR_NULL_POINTER;

    while( c != '\n'  && c != EOF ){

        if( vect_size >= x.getSize() ){
            x.expand(x.getSize() * 2);
        }

        is->putback(c);
        *is >> x[vect_size];

        if((is->rdstate() & ifstream::badbit)){
                
            is->clear();
            line_error = true;
            vect_size = 0;
            c = is->get();

            while ( c != '\n' && c != EOF){
                    c = is->get();
            }
            break;
        }
        vect_size++;

        c = is->get();

        while ( c == ' ' ) {
            c = is->get();   // Para que no rompa cuando lee espacios al final
        } 

    }

    if( line_error ) {
        (*os) << "Error: los argumentos de esta línea no son válidos." <<endl;
        return ERROR_INVALID_LINE;
			
            
    } else if( vect_size == 0 ){
        return EMPTY_LINE;
    }
    *i = vect_size;
        return OK;
}


void print_data(Array <Complejo> &y , ostream * oss){


	for( int k = 0; k < y.getSize(); k++ ) {
                
        *oss << y[k] << ' ';
    }
	*oss << endl;
}


#endif