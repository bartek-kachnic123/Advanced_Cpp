#include <iostream>


template<int N> inline double pow(double x) {return x*pow<N-1>(x);}
template<>  inline double pow<0>(double x) {return 1.0;};



int main() {
    std::cout << "Pow<0>(10) : " << pow<0>(10) << std::endl;
    std::cout << "Pow<3>(3) : " << pow<3>(3) << std::endl;
    std::cout << "Pow<10>(2) : " << pow<10>(2) << std::endl;


    return 0;
}