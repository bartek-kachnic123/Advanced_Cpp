#include <iostream>
#include <memory>

int main() {

    int *ptr = new int[10];
    std::unique_ptr<int> smart_ptr(new int[10]);
    std::shared_ptr<int> shared_ptr(new int[10]);

    std::cout << "Ptr size: " << sizeof(ptr) << std::endl;
    std::cout << "Smart ptr size: " << sizeof(smart_ptr) << std::endl;
    std::cout << "Shared ptr size: " << sizeof(shared_ptr) << std::endl;


    delete [] ptr;
    return 0;
}