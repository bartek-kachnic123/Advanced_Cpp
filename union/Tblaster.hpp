#if !defined(TBLASTER_HPP)
#define TBLASTER_HPP

#include<iostream>

class Tblaster
{
    double * accumulator {nullptr};
    static  int CAPACITY;

    void allocate();
public:
    Tblaster(double k = 1) {  

        allocate();

        for ( int i = 0 ; i < CAPACITY ; ++i ) {
            accumulator[i] = k* i;
        }
    }

    ~Tblaster();   									
    Tblaster ( const Tblaster & );
    Tblaster&  operator= ( const Tblaster &other ); 		

    void info()  {
        for ( int i = 0 ; i < 7 ; ++i ) {   std::cout <<  accumulator[i] << "  ";  }
    }
}; 

int Tblaster::CAPACITY = 150;

void Tblaster::allocate()
{
    try {					
        accumulator = new double[CAPACITY];
    }
    catch(const std::bad_alloc &e) {
            std::cerr << e.what() << std::endl;
        }
}

Tblaster::~Tblaster()
{
    if (accumulator!=nullptr)
        delete [] accumulator;
}

Tblaster::Tblaster(const Tblaster &other)
{
    allocate();
    std::copy(other.accumulator, other.accumulator+Tblaster::CAPACITY, accumulator);
}

Tblaster& Tblaster::operator=(const Tblaster &other) {
    if (this == &other)
        return *this;
    
    allocate();
    std::copy(other.accumulator, other.accumulator+Tblaster::CAPACITY, accumulator);
    
    return *this;
}


#endif // TBLASTER_HPP
