#ifndef _FOURIER_H_INCLUDED_
#define _FOURIER_H_INCLUDED_

vector <Complejo> DFT(const vector <Complejo>& x ){
    vector <Complejo>  y( x.size() );

    for(int k=0; k<x.size(); k++){
        for(int n=0; n<x.size(); n++){
            Complejo aux(cos(2*M_PI*n*k/x.size()),(-1)*sin(2*M_PI*n*k/x.size()));
            y[k] += x[n] * aux;
        }
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