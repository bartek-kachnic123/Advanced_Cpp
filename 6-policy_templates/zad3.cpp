#include <iostream>

struct No_checking_policy {
  static void check_push(size_t,size_t) {};
  static void check_pop(size_t) {};
  static void check_top(size_t) {};
};

template<typename T,size_t N = 0> struct Static_table_allocator {
         typedef T rep_type[N];
         void init(rep_type &,size_t) {};
         void expand_if_needed(rep_type &,size_t) {};
         void shrink_if_needed(rep_type &size_t) {};
         void dealocate(rep_type &){};

         static size_t size() {return N;};

};

template<typename T,size_t N > struct Dynamic_table_allocator {
  typedef T * rep_type;
  size_t _size;
  void init(rep_type &rep,size_t n) {_size=n;rep = new T[_size];};
  void expand_if_needed(rep_type &,size_t) {};
  void shrink_if_needed(rep_type &,size_t) {};
  void dealocate(rep_type &rep){delete [] rep;};

  size_t size() const {return _size;};

};


template<typename T = int, int N = 100, typename Checking_policy = No_checking_policy,  
         template<typename U,size_t M>  class Allocator_policy 
         = Static_table_allocator> class Stack {

  typedef typename Allocator_policy<T,N>::rep_type rep_type;
  rep_type  _rep;
  size_t _top;
  Allocator_policy<T,N> alloc;
public:
  Stack(size_t n = N):_top(0) {
    alloc.init(_rep,n);
  };

  void push(const T &val) {
    alloc.expand_if_needed(_rep,_top);
    Checking_policy::check_push(_top,alloc.size());
    _rep[_top++]=val;
  }

  void pop()              {
    Checking_policy::check_pop(_top);
    --_top;
    alloc.shrink_if_needed(_rep,_top);
  }

  const T& top()  const   {
    Checking_policy::check_top(_top);
    return _rep[top-1];
  }

  bool is_empty()         {
    return !_top;
  }

  ~Stack() {alloc.dealocate(_rep);}

};

int main() {
    Stack<int, 10, No_checking_policy, Static_table_allocator> s1;
    Stack<int, 10, No_checking_policy, Dynamic_table_allocator> s2;




    return 0;
}