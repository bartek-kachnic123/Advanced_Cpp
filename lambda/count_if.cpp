#include <iostream>
#include <algorithm>


int main() {
    int tab [] = {1, 2, 3, 4, 5, 6, 2};
    int limit = 4;
    int num = std::count_if(std::begin(tab), std::end(tab), [&limit](int num){return num < limit;});
    std::cout << num << std::endl;

    return 0;
}