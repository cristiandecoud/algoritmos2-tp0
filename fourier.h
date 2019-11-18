#ifndef _FOURIER_H_INCLUDED_
#define _FOURIER_H_INCLUDED_

#include <valarray>

class Fourier
{
    public:
        Fourier();
        ~Fourier();
        void DFT(const Array <Complejo>& x, const size_t size, Array <Complejo> & y);
        void IDFT(const Array <Complejo>& y,  const size_t size, Array <Complejo> & x);
        void FFT(const Array <Complejo>& x, const size_t size, Array <Complejo> & y);
        void IFFT(const Array <Complejo>& y, const size_t size, Array <Complejo> & x);
    private:
        void _IFFT(const Array <Complejo>& y, const size_t size, Array <Complejo> & x);
};

Fourier::Fourier()
{
}

Fourier::~Fourier()
{
}

void Fourier::DFT(const Array <Complejo>& x, const size_t size, Array <Complejo> & y){

    for(int k=0; k<size; k++){
        for(int n=0; n<size; n++){
            Complejo aux(cos(2*M_PI*n*k/size),(-1)*sin(2*M_PI*n*k/size));
            y[k] += x[n] * aux;
        }
    }
}

void Fourier::IDFT(const Array <Complejo>& y,  const size_t size, Array <Complejo> & x){

    for(int n=0; n<size; n++){
        for(int k=0; k<size; k++){
            Complejo aux(cos(2*M_PI*n*k/size),sin(2*M_PI*n*k/size));
            x[n] += (y[k] * aux) / size;
        }
    }
}

void Fourier::FFT(const Array <Complejo>& x, const size_t size, Array <Complejo> & y){

    if (size <= 1){
        y[0] = x[0];
        return;
    }
    Array <Complejo> x_par(size/2);
    Array <Complejo> x_impar(size/2);

    for (size_t i = 0; i < (size/2); i++){
        x_par[i] = x[2*i];
        x_impar[i] = x[2*i+1];
    }

    Array <Complejo> y_par(size/2);
    Array <Complejo> y_impar(size/2);

    FFT(x_par, size/2, y_par);
    FFT(x_impar, size/2, y_impar);

    Complejo Wn (cos(2*M_PI/size), sin(2*M_PI/size));
    Complejo W = 1;
    
    for(size_t k = 0; k < (size/2); k++){
        y[k] = y_par[k] + W * y_impar[k];
        y[k + size/2] = y_par[k] - W * y_impar[k];
        W = W * Wn;
    }
}

void Fourier::IFFT(const Array <Complejo>& y, const size_t size, Array <Complejo> & x){

    _IFFT(y, size, x);
    for (size_t i = 0; i < size; i++){
        x[i] = x[i] / size;
    }
}
    

void Fourier::_IFFT(const Array <Complejo>& y, const size_t size, Array <Complejo> & x){

    if (size <= 1){
        x[0] = y[0];
        return;
    }

    Array <Complejo> y_par(size/2);
    Array <Complejo> y_impar(size/2);

    for (size_t i = 0; i < (size/2); i++){
        y_par[i] = y[2*i];
        y_impar[i] = y[2*i+1];
    }

    Array <Complejo> x_par(size/2);
    Array <Complejo> x_impar(size/2);

    _IFFT(y_par, size/2, x_par);
    _IFFT(y_impar, size/2, x_impar);

    Complejo Wn (cos(2*M_PI/size), (-1)*sin(2*M_PI/size));
    Complejo W = 1;

    for(size_t k = 0; k < (size/2); k++){
        x[k] = (x_par[k] + W * x_impar[k]);
        x[k + size/2] = (x_par[k] - W * x_impar[k]);
        W = W * Wn;
    }
}

#endif