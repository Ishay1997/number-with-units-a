#include "NumberWithUnits.hpp"
#include <fstream>

using namespace std;

namespace ariel
{

    void NumberWithUnits::read_units(ifstream &units_file)
    {
    }

    // double NumberWithUnits::getValue(NumberWithUnits& n1){
    //     return n1.number;
    // }

    // string NumberWithUnits::getmUnits(NumberWithUnits& n1){
    //     return n1.unit;
    // }

    NumberWithUnits &operator+=(NumberWithUnits &a, const NumberWithUnits &b)
    {
        return a;
    }
    NumberWithUnits &operator-=(NumberWithUnits &a, const NumberWithUnits &b)
    {
        //return NumberWithUnits{2,"ton"};
        return a;
    }
    NumberWithUnits operator+(const NumberWithUnits &a, const NumberWithUnits &b)
    {
        return a;
    }
    NumberWithUnits operator-(const NumberWithUnits &a, const NumberWithUnits &b)
    {
        return a;
    }
    NumberWithUnits &operator+(NumberWithUnits &a) //onari
    {
        return a;
    }
    NumberWithUnits &operator-(NumberWithUnits &a)
    {
        return a;
    }

    //////////

    bool operator>(const NumberWithUnits &a, const NumberWithUnits &b) //maybe do this here
    {
        return true;
    }
    bool operator>=(const NumberWithUnits &a, const NumberWithUnits &b)
    {
        return true;
    }
    bool operator<(const NumberWithUnits &a, const NumberWithUnits &b)
    {
        return true;
    }
    bool operator<=(const NumberWithUnits &a, const NumberWithUnits &b)
    {
        return true;
    }
    bool operator==(const NumberWithUnits &a, const NumberWithUnits &b)
    {
        return true;
    }
    bool operator!=(const NumberWithUnits &a, const NumberWithUnits &b)
    {
        return true;
    }

    //////////

    NumberWithUnits &operator++(NumberWithUnits &a) //prefix
    {
        return a;
    }
    NumberWithUnits operator++(NumberWithUnits &a, int) //postfix
    {
        return a;
    }
    NumberWithUnits &operator--(NumberWithUnits &a) //prefix
    {
        return a;
    }
    NumberWithUnits operator--(NumberWithUnits &a, int) //postfix
    {
        return a;
    }

    ////////////

    NumberWithUnits operator*(const NumberWithUnits &a, const double b)
    {
        return a;
    }
    NumberWithUnits operator*(const double b, const NumberWithUnits &a)
    {
        return a;
    }
    NumberWithUnits operator*=(NumberWithUnits &a, double b)
    {
        return a;
    }

    ////////////

    ostream &operator<<(ostream &out, const NumberWithUnits &b)
    {
        return out;
    }
    istream &operator>>(istream &in, const NumberWithUnits &b)
    {
        return in;
    }

}