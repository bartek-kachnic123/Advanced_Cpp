#include <iostream>


template<size_t N, typename T>
T dot_product(T *a, T *b) {
    T total = T();
    for (size_t i=0; i < N; i++)
        total += a[i] * b[i];
    return total;
}


int main() {
    double  a[] = {1, 2, 3},
            b[] = {1.5, 2.5, 3.5};

    std::cout << dot_product<3>(a, b) << std::endl;


    return 0;
}