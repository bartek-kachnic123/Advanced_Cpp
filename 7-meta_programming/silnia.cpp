#include <iostream>

template<int N> struct Silnia {
 enum {val = N * Silnia<N-1>::val};
};
template<> struct Silnia<2> {
 enum {val = 2};
};
template<> struct Silnia<1> {
 enum {val = 1};
};
template<> struct Silnia<0> {
 enum {val = 1};
};

int main() {
    std::cout << "Silnia " << 0 << ": " << Silnia<0>::val << std::endl;
    std::cout << "Silnia " << 5 << ": " <<  Silnia<5>::val << std::endl;
    std::cout << "Silnia " << 8 << ": " << Silnia<8>::val << std::endl;
        
    return 0;
}