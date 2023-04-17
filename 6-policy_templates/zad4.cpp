#include <iostream>


template<typename T,size_t N > class Dynamic_table_allocator {
protected:
  typedef T * rep_type;
  rep_type _rep;
  size_t _size;
  void init(size_t n) {_size=n;_rep = new T[_size];};
  void expand_if_needed(size_t) {};
  void shrink_if_needed(size_t) {};
  void dealocate(){delete [] _rep;};

  size_t size() const {return _size;};
public:
  void resize(size_t n) {
      T *tmp= new T[n];
      std::copy(_rep,&_rep[(_size<n)?_size:n],tmp);
      delete [] _rep;
      _rep = tmp;
      _size=n;
  }
};

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

template<typename T = int , size_t N = 100,
         typename Checking_policy = No_checking_policy,  
         template<typename U,size_t M>  class Allocator_policy 
         = Static_table_allocator > 
class Stack: private Checking_policy, public Allocator_policy<T,N> {

  size_t _top;

  public: Stack(size_t n = N):_top(0) { Stack::init(n); }; void
  push(const T &val) { 
    Stack::expand_if_needed(_top);
    Checking_policy::check_push(_top,this->size());
    Stack::_rep[_top++]=val; 
  } 
  void pop() {
    Checking_policy::check_pop(_top); --_top;
    Stack::shrink_if_needed(_top); 
  } 
  const T& top() const {
    Checking_policy::check_top(_top); 
    return Stack::_rep[top-1]; }
  bool is_empty() { return !_top; }  Stack() {
    Stack::dealocate();} 
};


int main() {
    const int n = 100;
    Stack<int, n, No_checking_policy, Dynamic_table_allocator> s(n);
    s.resize(200);
}