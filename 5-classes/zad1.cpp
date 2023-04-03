#include <iostream>

template<typename T> class Is_class {
  //najpierw definiujemy dwa typy różniące sie rozmiarem
  typedef char one;
  typedef struct {char c[2];} two;
  //teraz potrzebne bedą dwa przeładowane szablony
  template<typename U> static one test(int U::*); 
  template<typename U> static two test(...);
  //to który szablon został wybrany sprawdzamy poprzez sprawdzenie rozmiaru zwracanego typu
  public:
  enum {yes = (sizeof(test<T>(0))==sizeof(one) )};
};

class Klasa {

};

int main() {


    std::cout << Is_class<int>::yes << std::endl;
    std::cout << Is_class<Klasa>::yes << std::endl;




    return 0;
}