#include "NumberWithUnits.hpp"
#include <fstream>

using namespace std;

namespace ariel
{

    void NumberWithUnits::read_units(ifstream &units_file)
    {
    }



    NumberWithUnits &NumberWithUnits::operator+=(const NumberWithUnits &b)
    {
        return *this;
    }
    NumberWithUnits &NumberWithUnits::operator-=(const NumberWithUnits &b)
    {
        return *this;
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
    
     bool NumberWithUnits::operator==(const NumberWithUnits &a)const
    {
        return true;
    }
    bool NumberWithUnits::operator!=(const NumberWithUnits &a)const
    {
        return true;
    }

    bool NumberWithUnits::operator>(const NumberWithUnits &a) const 
    {
        return true;
    }
    bool NumberWithUnits::operator>=(const NumberWithUnits &a)const
    {
        return true;
    }
    bool NumberWithUnits::operator<(const NumberWithUnits &a) const
    {
        return true;
    }
    bool NumberWithUnits::operator<=(const NumberWithUnits &a)const
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
     NumberWithUnits &NumberWithUnits::operator*=(const double &a)
    {
        return *this;
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
