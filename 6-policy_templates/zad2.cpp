#include <iostream>

struct No_checking_policy {
  static void check_push(size_t,size_t) {};
  static void check_pop(size_t) {};
  static void check_top(size_t) {};
};

class Abort_on_error_policy {
public:
  static void check_push(size_t top,size_t size) {

    if(top >= size) {
      std::cerr<<"trying to push element on full stack: aborting"<<std::endl;
      abort();
    }
  };

  static void check_pop(size_t top) {

    if(top < 1) {
      std::cerr<<"trying to pop element on empty stack: aborting"<<std::endl;
      abort();
    }
  };

  static void check_top(size_t top) {

    if(top < 1) {
      std::cerr<<"trying to get top element on empty stack: aborting"<<std::endl;
      abort();
    }
  };

};

template<typename T = int , size_t N = 100,
         typename Checking_policy = No_checking_policy > 
class Stack {
private:	
  T _rep[N];
  size_t _top;
public:
  Stack():_top(0) {};

  void push(const T &val) {

    Checking_policy::check_push(_top,N);
    _rep[_top++]=val;
  }

  void pop()              {
    Checking_policy::check_pop(_top);
    --_top;
  }

  const T& top()  const   {
    Checking_policy::check_top(_top);
    return _rep[top-1];
  }

  bool is_empty()         {
    return !_top;
  }

};



int main() {
    Stack<> s;
    Stack<int, 10> s1;
    Stack<int, 10, Abort_on_error_policy> s2;
   // s1.push(1);
    //s1.pop();
    //s1.pop();

    //s2.push(2);
    //s2.pop();
    //s2.pop();


    return 0;
}