#ifndef  ARRAY_INCLUDED
#define ARRAY_INCLUDED

//Clase array para complejos

class array
{
    public:
        array(); // constructor
        array( const array & );
        array(size_t);
        ~array( );
        size_t getSize( ) const;
        array &operator=( const array & );
        bool operator==( const array & ) const;
        complejo &operator[ ]( size_t );
        void emitir();

    private:
        size_t size;
        complejo *ptr;
};

#endif