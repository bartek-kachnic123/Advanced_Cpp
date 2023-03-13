#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

template<typename T> class SequenceGen {
private:
  T _start; 
  T _step;
public:
  SequenceGen(T start = T(),T step = 1 ): _start(start),_step(step){};

  T operator()() {T tmp = _start; _start+= _step; return tmp;}
};


int main() {

    const size_t n = 20;
    vector<int> v(n);

    generate_n(v.begin(),n,SequenceGen<int>(1,2));
    for (int i=0; i < n; ++i) {
        std::cout << v[i] << ", ";
    }
    std::cout << std::endl;

    vector<int>::iterator it=find_if(v.begin(),v.end(),std::bind(greater<int>(),std::placeholders::_1, 4));
    cout<<*it<<endl;

return 0;
}