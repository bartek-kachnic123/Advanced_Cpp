#include <iostream>
#include <vector>  
#include <algorithm>  
#include <execution>  
#include <chrono>
#include <numeric>
#include <functional>
#include <iomanip>
  
void testFill() {
    std::vector<int> vec(10'000'000);
    std::vector<int> vec2(10'000'000);

    auto begin = std::chrono::steady_clock::now();
    std::fill(vec.begin(), vec.end(), 1);

    auto end = std::chrono::steady_clock::now();

    std::cout << "Normal fill " << std::chrono::duration_cast<std::chrono::milliseconds>(end-begin).count() << " ms "<< std::endl;
  

    begin = std::chrono::steady_clock::now();
    std::fill(std::execution::par, vec2.begin(), vec2.end(), 1);
    end = std::chrono::steady_clock::now();

    std::cout << "Fill with policy par " << std::chrono::duration_cast<std::chrono::milliseconds>(end-begin).count() << " ms " << std::endl;
  
}

void testCount() {
    std::vector<int> vec(10'000'000, 1);

     auto begin = std::chrono::steady_clock::now();
    std::count(vec.begin(), vec.end(), 1);
    auto end = std::chrono::steady_clock::now();
    
    std::cout <<"Normal count " <<  std::chrono::duration_cast<std::chrono::milliseconds>(end-begin).count() << " ms " << std::endl;
    
    begin = std::chrono::steady_clock::now();
    std::count(std::execution::par, vec.begin(), vec.end(), 1);
    end = std::chrono::steady_clock::now();

    std::cout << "Count with policy par " <<  std::chrono::duration_cast<std::chrono::milliseconds>(end-begin).count() << " ms " << std::endl;
}

void testSearch() {
  std::vector<int> vec(10'000'000, 1);
  std::vector<int> vec2(1'000'000, 2);

  auto begin = std::chrono::steady_clock::now();
  std::search(vec.begin(), vec.end(), vec2.begin(), vec2.end());
  auto end = std::chrono::steady_clock::now();
  std::cout <<"Normal search " << std::chrono::duration_cast<std::chrono::milliseconds>(end-begin).count() << " ms " << std::endl;

  begin = std::chrono::steady_clock::now();
  std::search(std::execution::par, vec.begin(), vec.end(), vec.begin(), vec.end());
  end = std::chrono::steady_clock::now();
  std::cout << "Search with policy par: "<< std::chrono::duration_cast<std::chrono::milliseconds>(end-begin).count() << " ms " << std::endl;
}


void testReverse() {
  std::vector<int> vec(10'000'000, 0);
  int i = 0; 
  for (int &e : vec)
    e = ++i;
  

  auto begin = std::chrono::steady_clock::now();
  std::reverse(vec.begin(), vec.end());
  auto end = std::chrono::steady_clock::now();
  std::cout <<"Normal reverse " << std::chrono::duration_cast<std::chrono::milliseconds>(end-begin).count() << " ms " << std::endl;

  begin = std::chrono::steady_clock::now();
  std::reverse(std::execution::par, vec.begin(), vec.end());
  end = std::chrono::steady_clock::now();
  std::cout << "Reverse with policy par: "<< std::chrono::duration_cast<std::chrono::milliseconds>(end-begin).count() << " ms " << std::endl;
}

void testFind() {
  std::vector<int> vec(10'000'000, 0);
  vec[9'000'000] = 1;

  auto begin = std::chrono::steady_clock::now();
  std::find(vec.begin(), vec.end(), 1);

  auto end = std::chrono::steady_clock::now();
  std::cout <<"Normal find " << std::chrono::duration_cast<std::chrono::milliseconds>(end-begin).count() << " ms " << std::endl;

  begin = std::chrono::steady_clock::now();
  std::find(std::execution::par, vec.begin(), vec.end(), 1);
  end = std::chrono::steady_clock::now();
  std::cout << "Find with policy par: "<< std::chrono::duration_cast<std::chrono::milliseconds>(end-begin).count() << " ms " << std::endl;
}



int main() {  

  testFill();
  testCount();
  testSearch();
  testReverse();
  testFind();

  return 0;
}  
