#if !defined(TEQUIPMENT_H)
#define TEQUIPMENT_H

#include <iostream>
#include <vector>
#include <string>
#include "Tblaster.hpp"

class Tequipment {
    private:
        union 
        {
            std::string _name;
            std::vector<double> _rubbish;
            Tblaster _gun;
        };
    enum Current_data {STR_NAME, VEC_RUBBISH, TBLASTER, NONE};
    Current_data current{Current_data::NONE};

    void delete_current();
    public:
        Tequipment(const std::string name);
        Tequipment(const std::vector<double> &rubbish);
        Tequipment(const Tblaster &gun);

        Tequipment& operator=(const std::string name);
        Tequipment& operator=(const std::vector<double> &rubbish);
        Tequipment& operator=(const Tblaster &gun);

        void info();
        ~Tequipment();
        
};

Tequipment::Tequipment(const std::string name) 
    : current(Current_data::STR_NAME)
{
    new (&_name) std::string(name);
}

Tequipment::Tequipment(const std::vector<double> &rubbish)
    : current(Current_data::VEC_RUBBISH)
{
    new (&_rubbish) std::vector<double>(rubbish);
}

Tequipment::Tequipment(const Tblaster &gun)
: current(Current_data::TBLASTER) 
{    
    new (&_gun) Tblaster(gun);
}

Tequipment &Tequipment::operator=(const std::string name)
{
        delete_current();
        new (&_name) std::string(name);
        current = Current_data::STR_NAME;
        return *this;
}

Tequipment &Tequipment::operator=(const std::vector<double> &rubbish)
{
        delete_current();
        new (&_rubbish) std::vector<double>(rubbish);
        current = Current_data::VEC_RUBBISH;
        return *this;
}

Tequipment &Tequipment::operator=(const Tblaster &gun)
{
        delete_current();
        new (&_gun) Tblaster(gun);
        current = Current_data::TBLASTER;
        return *this;
}

void Tequipment::delete_current() {
    switch (current)
    {
    case Current_data::STR_NAME:
        _name.std::string::~string();
        break;
    case Current_data::VEC_RUBBISH:
        _rubbish.~vector<double>();
        break;
    case Current_data::TBLASTER:
        _gun.~Tblaster();
        break;
    default:
        break;
    }   
}

void Tequipment::info()
{
     switch (current)
    {
    case Current_data::STR_NAME:
        std::cout << _name << std::endl;
        break;
    case Current_data::VEC_RUBBISH:
        std::cout << "[";
        for (const double &x : _rubbish)
            std::cout << x << ", ";
        std::cout << "]\n";
        break;
    case Current_data::TBLASTER:
        _gun.info();
        std::cout << std::endl;
        break;
    default:
        break;
    }   
}

Tequipment::~Tequipment()
{
    delete_current();
}

#endif // TEQUIPMENT_H
