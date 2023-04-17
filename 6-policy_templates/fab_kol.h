#if !defined(FAB_KOL_H)
#define FAB_KOL_H
#include <iostream>
#include "kolor.h"
struct DefaultKolor {

  static Kolor nieznanyKolor() {

    return Kolor();
  }
};

template<int red, int green, int blue>
struct ChosenColor {
    static Kolor nieznanyKolor() {
        return Kolor(red, green, blue);
    }
};

template<typename DefaultKolor = DefaultKolor>
class FabrykaKolorow {
    static std::string  colors[];
    public:
    Kolor zwrocKolor(const std::string color) {
        if (color == "green")
            return Kolor(0, 255, 0);
        else if (color == "blue")
            return Kolor(255, 0, 0);
        else if (color == "blue")
            return Kolor(0, 0, 255);
        else 
            return DefaultKolor::nieznanyKolor();
    }
};

#endif // FAB_KOL_H
