#include <iostream>

template<int K,int N> struct Pow { enum 
 {val=K*Pow<K,N-1>::val}; };
template<int K> struct Pow<K,0> {
 enum {val=1};
};


int main() {
    std::cout << "Pow<10, 0> : " << Pow<10, 0>::val << std::endl;
    std::cout << "Pow<3, 3> : " << Pow<3, 3>::val << std::endl;
    std::cout << "Pow<2, 10> : " << Pow<2, 10>::val << std::endl;


    return 0;
}