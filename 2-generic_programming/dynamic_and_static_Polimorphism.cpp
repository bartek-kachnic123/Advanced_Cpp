#include <iostream>

class Animal {
    protected:
        std::string _name;
    
    public:
        Animal(std::string name) : _name(name){};
        virtual void makeSound() = 0;
        virtual ~Animal(){};

};

class Dog : public Animal {

public:
    Dog(std::string name) : Animal(name) {};
    virtual void makeSound() {
        std::cout << _name << ": woof woof...." << std::endl;
    }
};

class Cat : public Animal {

public:
    Cat(std::string name) : Animal(name) {};
    virtual void makeSound() {
        std::cout << _name << ": miauu miauu..." << std::endl;
    }
};
// dynamic
void makeSoundForAnimals(Animal *animals[], size_t n) {
    for (size_t i = 0; i < n; i++)
        animals[i]->makeSound();
}
// static
template<typename T>
void makeSoundForAnimals_T(T table[], size_t n) {
    for (size_t i = 0; i < n; i++)
        table[i].makeSound();
    
}

class Cow {
    
public:
    void makeSound() {
        std::cout << "Muuu muuu..." << std::endl;
    }
};

int main() {
    Animal *animals[] = {
        new Cat("Tiger"),
        new Dog("Boo"),
        new Dog("Pluto"),
        new Cat("Mruczek")
    };

    makeSoundForAnimals(animals, 4);
    std::cout << std::endl;

    Cat table_cats[] = {Cat("Tiger"), Cat("Mruczek")};
    makeSoundForAnimals_T(table_cats, 2);
    std::cout << std::endl;

    Cow table_cows[] = {Cow()};
    makeSoundForAnimals_T(table_cows, 1);





    return 0;
}