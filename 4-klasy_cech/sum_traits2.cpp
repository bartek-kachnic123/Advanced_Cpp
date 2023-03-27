#include <iostream>


template<typename T>  struct sum_traits;
/*
    Rozwiązać za pomocą klas cech również problem inicjalizacji zmiennej total.  */
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


template<typename T> 
typename sum_traits<T>::sum_type sum(T *beg,T *end) { 
  typedef typename sum_traits<T>::sum_type sum_type;
  sum_type total = sum_traits<T>::zero(); 
  while(beg != end ) { 
    total += *beg; beg++; 
  } 
  return total; 
}

int main() {
    char tab[] = "string";
    int tab2[] = {1, 2, 3};
    float tab3[] = {1.1, 1.2, 1.3};
    double tab4[] = {1.1, 1.2, 1.3};

    std::cout << sum(tab, &tab[7])   << std::endl;
    std::cout << sum(tab2, &tab2[3]) << std::endl;
    std::cout << sum(tab3, &tab3[3]) << std::endl;
    std::cout << sum(tab4, &tab4[3]) << std::endl;



    return 0;
}