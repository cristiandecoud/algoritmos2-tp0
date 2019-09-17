#include <iostream>
#include "complejo.h"


complejo:: complejo () 
{ 
    vec[0] = 0.0 ;
    vec[1] = 0.0;    
}

complejo:: complejo ( const complejo & c )
{
    vec[0] = c.vec[0]; 
    vec[1] = c.vec[1];
}


complejo:: complejo ( double a, double b )
{
    vec[0] = a;
    vec[1] = b;
}


complejo& complejo:: operator = ( const complejo & b )
{
    vec[0] = b.vec[0];
    vec[1] = b.vec[1];
    return *this;
}

complejo complejo:: operator + (const complejo &r)
{
    return complejo ( vec[0] + r.vec[0] , vec[1] + r.vec[1] );
}

complejo complejo:: operator + (double f)
{ 
    return complejo ( vec[0] + f, vec[1] );
}



//y además, esta función para sumar real y complejo
complejo operator +(float x , const complejo & c)
{
    complejo aux;

    aux.SetReal( x + c.GetReal() );
    aux.SetImag( c.GetImag() );

    return aux;
}