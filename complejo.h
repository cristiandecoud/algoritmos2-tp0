#include <iostream>
using namespace std;
#ifndef COMPLEJO_INCLUDED
#define COMPLEJO_INCLUDED

class complejo
{
    private:
        double vec[2];

    public:
        complejo();
        complejo( double , double );
        complejo( const complejo & );
        complejo& operator= ( const complejo & );

        double GetReal() const 
        {
            return vec[0];
        }

        double GetImag() const 
        {
            return vec[1];
        }

        void SetReal( double xx )
        { 
            vec[0] = xx; 
        }

        void SetImag(double yy)
        {
            vec[1] = yy;
        }

        complejo operator+ ( const complejo & );
        complejo operator+ ( double );

        ~complejo() {}
};

#endif // COMPLEJO_INCLUDED