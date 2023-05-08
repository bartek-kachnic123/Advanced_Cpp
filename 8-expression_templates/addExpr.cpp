#include <iostream>

class Variable {
public:
  double operator()(double x) {
    return x;
  }
};

class Constant {
  double _c;
public:
  Constant(double c) :_c(c){};
  double operator()(double x) {return _c;}
};

template<typename F>
double integrate(F func, double min, double max, double ds) {
    double integral = .0;
    for (double x = min; x < max; x+=ds)
        integral += func(x);

    return integral*ds;
}   

template<typename LHS,typename RHS > class AddExpr {
  LHS _lhs;
  RHS _rhs;
public:
  AddExpr(const LHS &l,const RHS &r) :_lhs(l),_rhs(r) {};
  double operator()(double x) {
    return _lhs(x)+_rhs(x);
  }
};


template<typename LHS,typename RHS > 
AddExpr<LHS,RHS>  operator+(const LHS &l,
                        const RHS &r) {
  return AddExpr<LHS,RHS>(l,r);
};   

template<typename LHS > 
AddExpr<LHS,Constant>  operator+(const LHS &l,
                        double r) {
  return AddExpr<LHS,Constant>(l,Constant(r));
};
template<typename RHS > 
AddExpr<Constant,RHS>  operator+(double l,
                        const RHS &r) {
 return AddExpr<Constant,RHS>(Constant(l),r);
}; 

int main() {
    Constant x(1);
    std::cout << integrate(x + 1.0, 0, 1, 0.01) << std::endl;


    return 0;
}