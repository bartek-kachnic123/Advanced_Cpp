#include <iostream>
#include <memory>

std::weak_ptr<int> weak_ptr;
 
void test()
{
    std::cout << "Number of shared ptr used:  == " << weak_ptr.use_count() << "; ";
    
    std::shared_ptr<int> shared_ptr = weak_ptr.lock();

    if (weak_ptr.expired())
    {
        std::cout << "Expired " << std::endl;
    }
    else {
        std::cout << "Shared ptr: " << *shared_ptr << std::endl;
    }
}
 
int main()
{
    {
        auto shared_ptr = std::make_shared<int>(100);
        weak_ptr = shared_ptr;
 
        test();
    }
 
    test();
}