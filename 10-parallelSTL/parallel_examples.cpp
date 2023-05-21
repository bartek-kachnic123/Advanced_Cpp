#include <iostream>
#include <vector>  
#include <algorithm>  
#include <execution>  
#include <chrono>
#include <numeric>
#include <functional>
  
void testFill() {
    std::vector<int> vec(1'000'000);
    std::vector<int> vec2(1'000'000);

    auto begin = std::chrono::steady_clock::now();
    std::fill(vec.begin(), vec.end(), 1);

    auto end = std::chrono::steady_clock::now();

    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end-begin).count() << std::endl;
  

    begin = std::chrono::steady_clock::now();
    std::fill(std::execution::par, vec2.begin(), vec2.end(), 1);
    end = std::chrono::steady_clock::now();

    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end-begin).count() << std::endl;
  
}

void noneOf() {
    std::vector<int> vec(1'000'000);

     auto begin = std::chrono::steady_clock::now();
    std::count(vec.begin(), vec.end(), 0);

    auto end = std::chrono::steady_clock::now();

    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end-begin).count() << std::endl;
  
    begin = std::chrono::steady_clock::now();
    std::count(std::execution::par, vec.begin(), vec.end(), 0);
    end = std::chrono::steady_clock::now();

    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end-begin).count() << std::endl;
}

int main() {  

  testFill();
  noneOf();

  return 0;
}  
