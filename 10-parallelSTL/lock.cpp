#include <iostream>
#include <vector>  
#include <algorithm>  
#include <execution>  
#include <mutex>  
#include <numeric>
#include <chrono>

  
std::vector<int> vec(10'000'000); 

int main() {  

  
  std::iota(vec.begin(), vec.end(), 0);
  std::vector<int> output; 
  std::mutex mut;

  auto begin = std::chrono::steady_clock::now();

  std::for_each(std::execution::par, vec.begin(), vec.end(),  
  [&output, &mut](int& elem) { if (elem % 2 == 0) { std::lock_guard<std::mutex> guard(mut); output.push_back(elem); }  
  });  
  auto end = std::chrono::steady_clock::now();

  std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end-begin).count() << std::endl;
  



  begin = std::chrono::steady_clock::now();

  std::for_each(std::execution::seq, vec.begin(), vec.end(),  
  [&output](int& elem) { if (elem % 2 == 0) { output.push_back(elem); }  
  });  
  end = std::chrono::steady_clock::now();

  std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end-begin).count() << std::endl;

  return 0;
}  
