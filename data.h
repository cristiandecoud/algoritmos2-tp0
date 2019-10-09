#ifndef _DATA_H_INCLUDED_
#define _DATA_H_INCLUDED_

// char * errors [MAX_ERRORS]{
// 	"OK",
// 	"ERROR ARCHIVO DE SALIDA",
// 	"ERROR ARCHIVO DE ENTRADA",
// 	"ERROR LINEA :",
// 	"DE LECTURA DE ARCHIVO"
// };

typedef enum{
    OK,
    ERROR_NULL_POINTER,
    ERROR_INVALID_LINE,
    EMPTY_LINE
}status_t;

status_t st;

status_t validate_line(istream *is, ostream *os, size_t * i , Array <Complejo> &x) {

    int c = is->get();
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
		
    c = is->get();     
		
    while( c == '\n' || c == ' ' ) { 
        c = is->get();           // Para saltear lineas en blanco o llenas de espacios
    }                                   
    is->putback(c);

    if( line_error ) {
        (*os) << "Error: los argumentos de esta línea no son válidos." <<endl;
        // line_error = false;

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