#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>


int main() {

    std::function<double(double)> reverse_number =
        [](double number) {
            if (number != 0)
                return 1 / number;
            throw std::domain_error("Division by 0");
        };
    
    std::vector<double> vec = {1.2, 1.5, 2, 120};
    std::transform(vec.begin(), vec.end(), vec.begin(), reverse_number);
    try {
    for (const double &num : vec)
        std::cout << num << ", ";
    std::cout << std::endl;

    std::for_each(vec.begin(), vec.end(), [](double n){std::cout << n << ", ";});
    std::cout << std::endl;
    } 
    catch (const std::domain_error &err) {
        std::cout << err.what() << std::endl;
    }

    return 0;
}