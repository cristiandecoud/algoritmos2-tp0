#ifndef _FOURIER_H_INCLUDED_
#define _FOURIER_H_INCLUDED_

Array <Complejo> DFT(const Array <Complejo>& x, const size_t size){
    Array <Complejo>  y(size);             //y debe tener el mismo tamaño que x

    for(int k=0; k<size; k++){
        for(int n=0; n<size; n++){
            Complejo aux(cos(2*M_PI*n*k/size),(-1)*sin(2*M_PI*n*k/size));
            y[k] += x[n] * aux;
        }
    }
    return y;

}

// Array <Complejo> IDFT(const Array <Complejo>& y){
//     Array <Complejo>  x;

//     for(int n=0; n<size; n++){
//         for(int k=0; k<size; k++){
//             Complejo aux(cos(2*M_PI*n*k/size),sin(2*M_PI*n*k/size));
//             x[n] += (y[k] * aux) / size;
//         }
//         //x[n] = x[n] / y.size;
//     }
//     return x;

// }

#endif