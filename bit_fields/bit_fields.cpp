#include <iostream>

struct BitFields {
    unsigned int year 	: 16,
				: 1, // skp
				month		: 4,
				: 1,
				day 	: 5;
};

union Date {
    uint32_t d;
    BitFields fields;
};

class DateElement {
    int day, month, year;

    public:
    DateElement(int d,  int m, int y)
        : day(d), month(m), year(y) {};
};

int main() {
    Date date;
    date.fields.year = 1410;
    date.fields.month = 12;
    date.fields.day = 31;
    std::cout << date.fields.day << std::endl;
    std::cout << date.fields.month << std::endl;
    std::cout << date.fields.year << std::endl;

    std::cout << "Sizeof(date) = " << sizeof(date) << std::endl;

    DateElement date2(31, 12, 1410);
    std::cout << "Sizeof(date2) = " << sizeof(date2) << std::endl;


    return 0;
}