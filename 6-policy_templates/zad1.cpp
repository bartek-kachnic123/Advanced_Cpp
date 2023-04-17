#include <iostream>
using std::cin;
using std::cout;

#include "kolor.h"
#include "fab_kol.h"

class MojaPolityka
{
public:
    static Kolor nieznanyKolor()
    { return Kolor(); }
};

FabrykaKolorow<> fabryka;
FabrykaKolorow<MojaPolityka> moja_fabryka;
FabrykaKolorow<ChosenColor<255, 128, 128>> fabryka_kolorow;

int main()
{
    try {
        cout << fabryka.zwrocKolor("zielony") << '\n';
        cout << fabryka.zwrocKolor("green") << '\n';
    } catch(...) {
        cout << "Zlapano wyjatek.\n";
    }

    cout << moja_fabryka.zwrocKolor("zielony") << '\n';
    cout << moja_fabryka.zwrocKolor("green") << '\n';

    cout << fabryka_kolorow.zwrocKolor("zielony") << '\n';

    return 0;
}