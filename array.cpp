#include "array.h"

array::array()
{
    size=10;
    ptr = new complejo[10];
}

array::array(size_t x)
{
    if ((x<1)||(x>500)) size=10; else size=x;   
    ptr = new complejo[size];
}

array::array( const array &init )
{
    size=init.size ;
    ptr = new complejo[ size ];
    for ( int i = 0; i < size; i++ )
    ptr[ i ] = init.ptr[ i ];
}
array::~array()
{
    if (ptr)
    delete [ ] ptr;
}
size_t array::getSize() const { return size; }

array& array::operator=( const array &rigth )
{
    if ( &rigth != this )
    {
        if ( size != rigth.size )
        {
            complejo *aux;
            aux=new complejo[ rigth.size ];
            delete [] ptr;
            size =rigth.size ;
            ptr=aux;
            for ( int i = 0; i < size; i++ )
            {   
                ptr[ i ] = rigth.ptr[ i ];
            }
                return *this;
            }
        else
        {
            for ( int i = 0; i < size; i++ )
            {       
                ptr[ i ] = rigth.ptr[ i ];
            }
            return *this; // al retornar una referencia permite x = y = z;
        }
    }
    return *this;
}

bool array::operator==( const array &rigth ) const
{
    if ( size != rigth.size )
        return false;
    else
    for ( int i = 0; i < size; i++ )
        if ( ptr[ i ] != rigth.ptr[ i ] )
            return false;
    return true;
}




complejo& array::operator [ ]( size_t subscript )
{
    
    return ptr[ subscript ]; // retorna referencia
  
}



