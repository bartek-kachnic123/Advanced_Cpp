#include <iostream>

template<size_t N> double inner(double *x, double *y) {
    return x[N-1]*y[N-1] + inner<N-1>(x, y);
};

template<> double inner<1>(double *x, double *y) {
    return x[0] * y[0];
}
template<> double inner<0>(double *x, double *y) {
    return 0.0;
}



int main() {
    double x[] = {1.0};
    double y[] = {2};
    std::cout << inner<1>(x, y) << std::endl;


    double x2[] = {1.0, 2.0, 3.0};
    double y2[] = {2.0, 3.0, 2.5};
    std::cout << inner<3>(x2, y2) << std::endl;

    
    double x3[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    double y3[] = {2.0, 3.0, 2.5, 3.5, 4.5};
    std::cout << inner<5>(x3, y3) << std::endl;

    return 0;
}