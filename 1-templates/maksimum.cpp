#include <iostream>

template<typename T>
T maksimum( T a,  T b) {
    return (a < b) ? b : a;
}


int main() {

    int a=5, b=10;
    std::cout << maksimum(a, b) << std::endl;
    return 0;
}
