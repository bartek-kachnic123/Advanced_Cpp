#include <iostream>
#include <vector>


/*
    Uogólnić funkcję sum, aby działała nie tylko ze wskaźnikami, ale 
    i iteratorami. Widać, że tu użycie klas cech jest już niezbędne, musimy 
    bowiem dowiedzieć się na obiekty jakiego typu wskazuje iterator.
    Nie można do tego celu użyć typów stowarzyszonych IT::value_type, bo 
    jako iterator może zostać podstawiony zwykły wskaźnik. Dlatego w STL 
    istnieje klasa iterator_traits, definiująca podstawowe typy dla każdego 
    rodzaju iteratora. Korzystając z tej klasy zdefiniuj ogólny szablon funkcji 
    sum. */

template<typename T>  struct sum_traits;


template<>  struct sum_traits<char> {
typedef int sum_type; 
static  sum_type zero() {return 0;} 
};

template<>  struct sum_traits<int> {
typedef  long int sum_type; 
static  sum_type zero() {return 0;} 
};

template<>  struct sum_traits<float> {
typedef double sum_type;
static  sum_type zero() {return 0.0;} 

};

template<>  struct sum_traits<double> {
typedef double sum_type; 
static  sum_type zero() {return 0.0;} 
};

template<typename IT> 
typename 
sum_traits<typename std::iterator_traits<IT>::value_type>::sum_type 
sum(IT beg,IT end) { 
  typedef typename std::iterator_traits<IT>::value_type value_type;
  typedef typename sum_traits<value_type>::sum_type sum_type;
  sum_type total = sum_traits<value_type>::zero(); 
  while(beg != end ) { 
    total += *beg; beg++; 
  } 
  return total; 
}

int main() {
    std::vector<int> v1 = {1, 2, 3};

    std::cout << sum(v1.begin(), v1.end()) << std::endl;

    return 0;
}