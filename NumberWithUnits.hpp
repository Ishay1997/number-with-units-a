#pragma once
#include <string>
#include <iostream>

namespace ariel
{
    class NumberWithUnits
    {

    private:
        std::string unit;
        double number;

    public:
        NumberWithUnits(double num, std::string c)
        {
            number = num;
            unit = c;
        }

        ~NumberWithUnits() {}

        static void read_units(std::ifstream &units_file);


        friend NumberWithUnits &operator+=(NumberWithUnits &a, const NumberWithUnits &b);
        friend NumberWithUnits &operator-=(NumberWithUnits &a, const NumberWithUnits &b);
        friend NumberWithUnits operator+(const NumberWithUnits &a, const NumberWithUnits &b);
        friend NumberWithUnits operator-(const NumberWithUnits &a, const NumberWithUnits &b);
        friend NumberWithUnits &operator+(NumberWithUnits &a); 
        friend NumberWithUnits &operator-(NumberWithUnits &a);

        //////////

        friend bool operator>(const NumberWithUnits &a, const NumberWithUnits &b);
        friend bool operator>=(const NumberWithUnits &a, const NumberWithUnits &b);
        friend bool operator<(const NumberWithUnits &a, const NumberWithUnits &b);
        friend bool operator<=(const NumberWithUnits &a, const NumberWithUnits &b);
        friend bool operator==(const NumberWithUnits &a, const NumberWithUnits &b);
        friend bool operator!=(const NumberWithUnits &a, const NumberWithUnits &b);

        //////////

        friend NumberWithUnits &operator++(NumberWithUnits &a);      
        friend NumberWithUnits operator++(NumberWithUnits &a, int); 
        friend NumberWithUnits &operator--(NumberWithUnits &a);      
        friend NumberWithUnits operator--(NumberWithUnits &a, int); 

        ////////////

        friend NumberWithUnits operator*(const NumberWithUnits &a, const double b);
        friend NumberWithUnits operator*(const double b, const NumberWithUnits &a);
        friend NumberWithUnits operator*=(NumberWithUnits &a, double b);

        ////////////

        friend std::ostream &operator<<(std::ostream &out, const NumberWithUnits &b);
        friend std::istream &operator>>(std::istream &in, const NumberWithUnits &b);
    };
} 
