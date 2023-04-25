
#include <iostream>

template<size_t N, typename T> T dot(T *x, T *y) {
    return x[N-1] * y[N-1] + dot<N-1>(x, y);
}

template<> double dot<0>(double *x, double *y) {
    return 0.0;
}
template<> long long dot<0>(long long *x, long long *y) {
    return 0.0;
}

int main() {
    double x[] = {1.0};
    double y[] = {2};
    std::cout << dot<1, double>(x, y) << std::endl;


    double x2[] = {1.0, 2.0, 3.0};
    double y2[] = {2.0, 3.0, 2.5};
    std::cout << dot<3>(x2, y2) << std::endl;

    
    double x3[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    double y3[] = {2.0, 3.0, 2.5, 3.5, 4.5};
    std::cout << dot<5>(x3, y3) << std::endl;

    float x4[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    float y4[] = {2.0, 3.0, 2.5, 3.5, 4.5};
    std::cout << dot<5>(x4, y4) << std::endl;


    return 0;
}