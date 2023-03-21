#include <iostream>
#include <vector>
#include <cstring>
#include <set>
#include <functional>
/*
1.Podaj implementacje funkcji maxdla różnego typu argumentów.
Skorzystaj z możliwości przeciążania i specjalizacji szablonów funkcji:
*/

template<typename T> T max(T a,T b) {
    return (a>b) ? a : b ;
}

template<typename T> T* max(T *a, T *b) {
  return ((*a)>(*b)) ? a : b;
}

template<typename T> T max(T *data,size_t n) {
  T _max = data[0];
  for(size_t i=0;i<n;i++)
    if(data[i]>_max) _max=data[i];
  return _max;
}

template<> char *max(char *a,char *b) {
  return (strcmp(a,b)>0) ? a : b;
}
template<> const char* max(const char *a,const char *b) {
  return (strcmp(a,b)>0) ? a : b ;
}


template<typename T> const T* max(T *a,const T*b) {
  return ((*a)>(*b)) ? a : b;
}

template<> const char* max(char *a,const char *b) {
  return (strcmp(a,b)>0) ? a : b ;
}

/*
Na  przykładzie  szablonu  funkcji convert pokazać,  że  
jest  możliwe zdefiniowanie dwóch funkcji o tej samej
nazwie i argumentach wywołania, różniących się tylko zwracanym typem.
*/

template<typename T,typename U> T convert(U u) {
  return static_cast<T>(u);
};

template<> int    convert<int>(double u) {return u;};
template<> double convert<double>(double u) {return u;};
/*
Zad 3
W  przeciwieństwie  do  szablonów  funkcji,  szablony  klas  
nie  mogą  być przeciążane, a jedynie specjalizowane. Oznacza to, że 
w programie może istnieć  tylko  jeden  szablon  podstawowy  o  danej  nazwie.
Proszę zaimplementować specjalizację częściową, która jest dozwolona  tylko  
dla szablonów klas, dla podanych podzbiorów parametrów
*/

template<typename T,int N = 100> class Stack {
   T _rep[N];
  unsigned int _top;
public:
  Stack():_top(0){};
  void push(T e) {_rep[_top++]=e;}
  T pop() {return _rep[--_top];}
};

/*
4.Zaimplementować szablon klasy Stack  wraz  z jej 
specjalizacjami  tak  aby „działała” ze zwykłymi tablicami oraz kontenerami STL
*/
// template<typename T,int N = 100, typename R = T*> class Stack;

// template<typename T,int N> class Stack<T,N,T*> {
//   T _rep[N];
//   unsigned int _top;
// public:
//   Stack():_top(0){};
//   void push(T e) {_rep[_top++]=e;}
//   T pop() {return _rep[--_top];}
// };

// template<typename T,int N,template<typename E> class Sequence> 
//   class Stack<T,N,Sequence<T> > {
//   Sequence<T> _rep;
// public:
//   void push(T e) {_rep.push_back(e);};
//   T pop() {T top = _rep.top();_rep.pop_back();return top;}
//   bool is_empty() const {return _rep.empty();}
// };

/*
Zad.5
Zapoznaj  się  z  rodziną  funktorów  porównujących, 
do  której  należą  np. less<>(),  greater<>(),   
less_equal<>(),   greater_equal<>(). Przypomnij sobie pojemnik std::set. 
Następnie napisz programik korzystający ze zbioru liczb posortowanego odwrotnie
(czyli malejąco)
*/
void homework() {
    std::set<int, std::greater<> > reverse_set;
     for (int i = 1; i < 10; ++i)
         reverse_set.insert(i);
    
    for (auto& element : reverse_set){
        std::cout << element << ", ";
    }
    std::cout << std::endl;
    
}
int main() {
    std::cout << "Zad 1: " << std::endl;
    std::cout << max(10, 5) << std::endl;
    int i = 5, j = 10;
    std::cout << *max(&i, &j) << std::endl;
    int tab[] = {1, 3, 2};
    std::cout << max(tab, 3) << std::endl;
    char tab_chars[] = "abcde";
    char tab_chars2[] = "defg";
    std::cout << max(tab_chars, tab_chars2) << std::endl;
    std::cout << max("char1", "char011") << std::endl;
    std::cout << max(tab_chars, "xyz") << std::endl;

    std::cout << "Zad 2: " << std::endl;
    std::cout << convert<double>(12.2) << std::endl;
    std::cout << convert<int>(12.2) << std::endl;
    
    std::cout << "Zad 3: " << std::endl;
    Stack<int,20>      s0;
    Stack<int,666>     s1;
    Stack<double *,30> s2;
    Stack<double ,30>  s3;
    Stack<double *,44> s4;
    Stack<int *,20>    s5;
    Stack<double,666>  s6;

    std::cout <<"Zad 4: " << std::endl;

    // Stack<int, 100> s_array;
    // Stack<int, 0, std::vector<int> > s_vector;

    std::cout << "Zad 5: " << std::endl;
    homework();
    return 0;
}