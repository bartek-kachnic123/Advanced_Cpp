#if !defined(KOLOR_H)
#define KOLOR_H
#include <iostream>

class Kolor {
    int r,g,b;
    public:

    Kolor() {
        r = 0;
        g = 0;
        b = 0;
    }
    Kolor(int red, int green, int blue)
        : r(red), g(green), b(blue) {};

    friend std::ostream& operator<<(std::ostream& os, const Kolor &color) {
        os << '[' << color.r << ',' << color.g << ',' << color.b << ']';
        return os;
    }
};

#endif // KOLOR_H
