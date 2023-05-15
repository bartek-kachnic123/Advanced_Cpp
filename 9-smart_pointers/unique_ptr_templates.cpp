#include <iostream>
#include <memory>


template< class T, class... Args > std::unique_ptr<T> make_unique( Args&&... args );

template< class T > std::unique_ptr<T> make_unique( std::size_t size );
int main() {
    
    auto ptr = make_unique<int>(1, 2, 3, 4, 5);
    auto ptr2 = make_unique<int[]>(10);

    return 0;
}