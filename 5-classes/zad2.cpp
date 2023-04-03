#include <iostream>
#include <vector>

template<typename T> class has_value_type {
  //najpierw definiujemy dwa typy różniące sie rozmiarem
  typedef char one;
  typedef struct {char c[2];} two;
  //teraz potrzebne bedą dwa przeładowane szablony
  template<typename U> static one test( typename U::value_type); 
  template<typename U> static two test(...);
  //to który szablon został wybrany sprawdzamy poprzez sprawdzenie rozmiaru zwracanego typu
  public:
  enum {yes = (sizeof(test<T>(0))==sizeof(one) )};
};

template<typename T>
class Klasa {
    public:

    typedef T value_type;
};

int main() {


    std::cout << has_value_type<std::vector<int>>::yes << std::endl;
    std::cout << has_value_type<int>::yes << std::endl;
    std::cout << has_value_type<Klasa<int>>::yes << std::endl;




    return 0;
}