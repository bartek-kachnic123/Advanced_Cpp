#include <iostream>



class Variable {
public:
  double operator()(double x ) {return x;}
  double operator()(double,double x) {return x;}
};

template<typename LHS,typename RHS > class AddExpr {
  LHS _lhs;
  RHS _rhs;
public:
  AddExpr(const LHS &l,const RHS &r) :_lhs(l),_rhs(r) {};
  double operator()(double x) {
    return _lhs(x)+_rhs(x);
  }
  double operator()(double x,double y) {
    return _lhs(x,y)+_rhs(x,y);
  }
}; 


template<typename LHS,typename RHS > 
AddExpr<LHS,RHS>  operator+(const LHS &l,
                        const RHS &r) {
  return AddExpr<LHS,RHS>(l,r);
};   

template<typename F>
double integrate(F func, double min, double max, double ds) {
    double integral = .0;
    for (double x = min; x < max; x+=ds)
        integral += func(x);

    return integral*ds;
}   


int main() {
    Variable x, y;

    std::cout << integrate(x+y, 0, 1, 0.01) << std::endl;



    return 0;
}