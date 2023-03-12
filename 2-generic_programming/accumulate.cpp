#include <iostream>
#include <bits/stdc++.h>

template <class InputIterator>
typename InputIterator::value_type accumulate(InputIterator first, InputIterator last) {
    
    typename InputIterator::value_type total = 0;
    for( ; first != last; first++)
    total+= *first;
    return total;
}


int main() {
    std::vector<double> v1 = {1, 2, 3, 4, 5};
    std::cout << accumulate(v1.begin(), v1.end()) << std::endl;

    std::list<int> list1 = {1, 2, 3, 4, 5};
    std::cout << accumulate(list1.begin(), list1.end()) << std::endl;

    std::set<double> set1 = {1, 2, 3, 4, 5};
    std::cout << accumulate(set1.begin(), set1.end()) << std::endl;
}