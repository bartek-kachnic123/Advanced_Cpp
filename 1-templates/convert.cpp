#include <iostream>

template<typename T, typename U>
T convert(U arg) {
    return (T)arg;
}


int main() {
    double x = 10.5;
    std::cout << convert<int>(x) << std::endl;



    return 0;
}