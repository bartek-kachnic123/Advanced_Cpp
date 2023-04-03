#include<vector>
#include<deque>
#include<iostream>

template<typename T,typename U> class Is_convertible {
typedef char one;
typedef struct {char c[2];} two;
/* tym razem korzystamy ze zwykłych przeciążonych funkcji */
static one test(U) ;
static two test(...);
static T makeT();

public: enum {yes = sizeof(test(makeT()) )==sizeof(one),
  same_type=false }; };

template<typename T> class Is_convertible<T,T> {
public:
  enum {yes = true,
      same_type=true }; 
};

int main() {

  std::cout<<Is_convertible<int,double>::yes<<std::endl;
  std::cout<<Is_convertible<double,int>::yes<<std::endl;

  std::cout<<Is_convertible<double,int>::same_type<<std::endl;

  std::cout<<Is_convertible<size_t,unsigned int>::same_type<<std::endl;
  std::cout<<Is_convertible<std::vector<double>::value_type,
    double >::same_type<<std::endl;

  std::cout<<Is_convertible<std::vector<double>::iterator,
    double *>::same_type<<std::endl;

    return 0;
}