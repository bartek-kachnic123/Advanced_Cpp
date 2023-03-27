#include <iostream>



/*
Szablony funkcji nie dopuszczają stosowania parametrów domyślnych. 
Można to ograniczenie obejść za pomocą przeciążenia szablonu definiując 
szablon o mniejszej ilości argumentów, który zwraca wynik podstawienia domyślnych 
parametrów do bardziej ogólnego szablonu. Zmienić implementację funkcji sum tak 
aby podając odpowiednią klasę cech (sum_char) jako pierwszy z argumentów szablonu 
można było zażądać sumowania znaków char do zmiennej total również typu char. 
Równocześnie, w przypadku gdy nie jest podana klasa cech, szablon powinien działać 
tak jak w zad. 2. */

template<typename T>  struct sum_traits;


template<>  struct sum_traits<char> {
typedef int sum_type; 
};

template<>  struct sum_traits<int> {
typedef long int sum_type; 
};

template<>  struct sum_traits<float> {
typedef double sum_type; 
};

template<>  struct sum_traits<double> {
typedef double sum_type; 
};

template<typename Traits,typename T > 
typename Traits::sum_type sum(T *beg,T *end) { 
  typedef typename Traits::sum_type sum_type;
  sum_type total = sum_type(); 
  while(beg != end ) { 
    total += *beg; beg++; 
  } 
  return total; 
};

template<typename T > 
typename sum_traits<T>::sum_type sum(T *beg,T *end) { 
  return sum<sum_traits<T>, T>(beg,end);
}

struct char_sum {
  typedef char sum_type;
};


int main() {
    char tab[] = "str";

    std::cout   <<  (int)sum(tab, &tab[3]) <<  std::endl;
    std::cout   <<  (int)sum<char_sum>(tab,&tab[3]) << std::endl;
    std::cout   <<  (int)sum<char>(tab,&tab[3]) << std::endl;


    return 0;
}