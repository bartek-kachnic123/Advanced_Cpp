#include<iostream>
using namespace std;


template<typename S> typename S::value_type sum(S s) {
  typename S::value_type total; 
 
  while(!s.is_empty() ) {
    total+=s.pop();
  }
  return total;
}


template<typename T = int , size_t N = 100> class Stack {
private:	
 T _rep[N];
 size_t _top;
public:
  typedef T value_type;

  Stack():_top(0) {};

 void push(T val) {_rep[_top++]=val;}
 T pop()          {return _rep[--_top];}
 bool is_empty() const     {return (_top==0);} 
};

int main() {

 Stack<double,10> stack;
 stack.push(3.0);
 stack.push(2.10);
 stack.push(5);

 cout<<sum(stack)<<endl;
 
 return 0;
}
