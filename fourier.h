#ifndef _FOURIER_H_INCLUDED_
#define _FOURIER_H_INCLUDED_

Array <Complejo> DFT(const Array <Complejo>& x){
    Array <Complejo>  y;

    for(int k=0; k<x.getSize(); k++){
        for(int n=0; n<x.getSize(); n++){
            Complejo aux(cos(2*M_PI*n*k/x.getSize()),(-1)*sin(2*M_PI*n*k/x.getSize()));
            y[k] += x[n] * aux;
        }
    }

    for(int k=0; k<y.getSize(); k++){
         std::cout << y[k] << endl;
    }
    return y;

}

Array <Complejo> IDFT(const Array <Complejo>& y){
    Array <Complejo>  x;

    for(int n=0; n<y.getSize(); n++){
        for(int k=0; k<y.getSize(); k++){
            Complejo aux(cos(2*M_PI*n*k/x.getSize()),sin(2*M_PI*n*k/x.getSize()));
            x[n] += (y[k] * aux) / y.getSize();
        }
        //x[n] = x[n] / y.getSize();
    }
    return x;

}

#endif