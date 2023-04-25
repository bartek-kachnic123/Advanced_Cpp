#include <iostream>


template<int N> inline double pow(double x) {return x*pow<N-1>(x);}
template<>  inline double pow<0>(double x) {return 1.0;};



int main() {
    

    return 0;
}