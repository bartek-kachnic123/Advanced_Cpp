#include <vector>
#include <iostream>
#include <execution>
#include <algorithm>
#include <random>


std::vector<int> v(1000);
int main() {

    srand(0);
    for(int i = 0; i < 1000; i++){
        v.push_back(rand() % i + 1);
     }
     
    // standard sequential sort
    std::sort(v.begin(), v.end());

    // explicitly sequential sort
    std::sort(std::execution::seq, v.begin(), v.end());

    std::sort(std::execution::unseq, v.begin(), v.end());

    // permitting vectorization as well
    std::sort(std::execution::par_unseq, v.begin(), v.end());


    return 0;
}