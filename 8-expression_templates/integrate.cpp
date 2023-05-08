#include <iostream>
#include <cmath>

class Sina {
    double _a;

    public:
    Sina(double a) : _a(a) {};
    
    double operator()(double x) {return sin(_a*x);}
};

template<typename F>
double integrate(F func, double min, double max, double ds) {
    double integral = .0;
    for (double x = min; x < max; x+=ds)
        integral += func(x);

    return integral*ds;
}   
int main() {
    std::cout << ::integrate(Sina(1), 0, 3.1415929, 0.01) << std::endl;
    std::cout << ::integrate(Sina(2), 0, 3.1415929, 0.01) << std::endl;








    return 0;
}