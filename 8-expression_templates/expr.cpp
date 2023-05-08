#include <iostream>
#include <complex>


template<typename T> class Variable {
public:
  T operator()(T x) {
     return x;
  }
};
template<typename T> class Constant {
  T _c;
public:
  Constant(T c) :_c(c){};
  T operator()(T x) {return _c;}
};
template<typename T, typename LHS,typename RHS > class AddExpr {
  LHS _lhs;
  RHS _rhs;
public:
  AddExpr(const LHS &l,const RHS &r) :_lhs(l),_rhs(r) {};
  T operator()(T x) {
    return _lhs(x)+_rhs(x);
  }
}; 


template<typename T,typename R = Variable<T> > class Expr {
  R _rep;
 public:
  Expr() {};
  Expr(R rep):_rep(rep) {};
  T operator()(T x) {return _rep(x);}
  R rep() const {return _rep;};
};


template<typename T,typename LHS,typename RHS > 
Expr<T,AddExpr<T,LHS,RHS> >  operator+(const Expr<T,LHS> &l,
                        const Expr<T,RHS> &r) {
  return Expr<T,AddExpr<T,LHS,RHS> >(AddExpr<T,LHS,RHS>(l.rep(),r.rep()));
};

template<typename T,typename LHS > 
Expr<T,AddExpr<T,LHS,Constant<T> > >   
operator+(const Expr<T,LHS>  &l,
                        T r) {
return Expr<T,AddExpr<T,LHS,Constant<T> > >
       (AddExpr<T,LHS,Constant<T> >(l.rep(),Constant<T>(r)));
};

template<typename T,typename RHS > 
Expr<T,AddExpr<T,Constant<T>, RHS > >   
operator+(  T l, const Expr<T,RHS>  &r) {
return Expr<T,AddExpr<T,Constant<T>, RHS > >
       (AddExpr<T,Constant<T>, RHS> (Constant<T>(l), r.rep()));
};

template<typename F>
double integrate(F func, double min, double max, double ds) {
    double integral = .0;
    for (double x = min; x < max; x+=ds)
        integral += func(x);

    return integral*ds;
}   

int main() {
    Expr<int> x;
    Expr<int> y;
    
    std::cout << integrate(x+1, 0, 1, 0.01) << std::endl;
    std::cout << integrate(1+x, 0, 1, 0.01) << std::endl;
    std::cout << integrate(x+y, 0, 1, 0.01) << std::endl;

    Expr<double> x2;
    Expr<double> y2;

    std::cout << integrate(x2+1.0, 0, 1, 0.01) << std::endl;
    std::cout << integrate(1.0+x2, 0, 1, 0.01) << std::endl;
    std::cout << integrate(x2+y2, 0, 1, 0.01) << std::endl;


    return 0;
}