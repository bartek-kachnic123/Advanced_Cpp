#include <iostream>
#include "Tequipment.hpp"


int main() {
    Tequipment eq("some words");

    eq = "Just another string";
    eq.info();
    Tblaster    gun(20);
 	eq = gun;
 	eq.info();
 	eq = std::vector<double> { 1.0, 2.2, 3,3, 4.4}; 	
 	eq.info();
 	eq = Tblaster(3);
 	eq.info();
 	eq = Tblaster(0.2);
 	eq.info();
 	eq = "Third string";
 	eq.info();  
 
    return 0;
}