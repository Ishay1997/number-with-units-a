#include "NumberWithUnits.hpp"
#include <fstream>

using namespace std;

namespace ariel
{

    void NumberWithUnits::read_units(ifstream &units_file)
    {
    }



    NumberWithUnits &operator+=(NumberWithUnits &a, const NumberWithUnits &b)
    {
        return a;
    }
    NumberWithUnits &operator-=(NumberWithUnits &a, const NumberWithUnits &b)
    {
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

    bool operator>(const NumberWithUnits &a, const NumberWithUnits &b) 
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

    NumberWithUnits &operator++(NumberWithUnits &a) 
    {
        return a;
    }
    NumberWithUnits operator++(NumberWithUnits &a, int) 
    {
        return a;
    }
    NumberWithUnits &operator--(NumberWithUnits &a) 
    {
        return a;
    }
    NumberWithUnits operator--(NumberWithUnits &a, int) 
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
