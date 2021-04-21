#include "NumberWithUnits.hpp"
#include "doctest.h"
#include <string>
#include <fstream>

using namespace std;
using namespace ariel;

ifstream units_file{"units.txt"};

NumberWithUnits m1(1, "m");
NumberWithUnits m1000(1000, "m");
NumberWithUnits cm1(1, "m");
NumberWithUnits km1(1, "km");
NumberWithUnits ton1(1, "ton");
NumberWithUnits g1000(1000, "g");
NumberWithUnits g1(1, "g");
NumberWithUnits kg1(1, "kg");
NumberWithUnits hour0_5(0.5, "hour");
NumberWithUnits hour1(1, "hour");
NumberWithUnits min60(60, "min");
NumberWithUnits min1(1, "min");
NumberWithUnits sec60(60, "sec");
NumberWithUnits USD1(1, "USD");
NumberWithUnits USDminos1(-1, "USD");
NumberWithUnits ILS3_3(3.3, "ILS");
NumberWithUnits ILSminos3_3(-3.3, "ILS");

TEST_CASE("equal")
{
    NumberWithUnits::read_units(units_file);
    CHECK_EQ(USD1, ILS3_3);
    CHECK_EQ(km1, m1000);
    CHECK_EQ(hour1, min60);
    CHECK_EQ(min1, sec60);
    CHECK_EQ(USD1, ILS3_3);
    CHECK_EQ(kg1, g1000);
}
TEST_CASE("cafel")
{
    NumberWithUnits::read_units(units_file);
    CHECK_EQ(km1, 1000 * m1);
    CHECK_EQ(kg1, 1000 * g1);
    CHECK_EQ(2 * min1, 2 * sec60);
    CHECK_EQ(5 * hour1, 5 * min60);
}
TEST_CASE("plus")
{
    NumberWithUnits::read_units(units_file);
    CHECK_EQ(hour1 + hour0_5, 90 * min1);
    CHECK_EQ(kg1 + 400 * g1, 1400 * g1);
    CHECK_EQ(min1 + 0.5 * sec60, 1.5 * sec60);
    CHECK_EQ(min1 + 0.5 * sec60, 1.5 * min1);
}
TEST_CASE("minos")
{
    NumberWithUnits::read_units(units_file);
    CHECK_EQ(hour1 - hour0_5, 30 * min1);
    CHECK_EQ(kg1 - 400 * g1, 600 * g1);
    CHECK_EQ(min1 - 0.5 * sec60, 0.5 * sec60);
    CHECK_EQ(min1 - 0.5 * sec60, 0.5 * min1);
}
TEST_CASE("minos onari")
{
    NumberWithUnits::read_units(units_file);
    CHECK_EQ(USDminos1, -USD1);
    CHECK_EQ(ILSminos3_3, -ILS3_3);
}
TEST_CASE("left bigger")
{
    NumberWithUnits::read_units(units_file);
    CHECK_GT(USD1, 0.4 * ILS3_3);
    CHECK_GT(km1, m1);
    CHECK_GT(kg1, 0.8 * g1000);
}
TEST_CASE("right bigger")
{
    NumberWithUnits::read_units(units_file);
    CHECK_GT(USDminos1, USD1);
    CHECK_GT(km1, 1200 * m1);
    CHECK_GT(km1, m1000 + 5 * cm1);
}
TEST_CASE("not equal")
{
    NumberWithUnits::read_units(units_file);
    CHECK_NE(km1, m1);
    CHECK_NE(kg1, 500 * g1);
    CHECK_NE(USDminos1, USD1);
    CHECK_NE(USD1, 0.4 * ILS3_3);
    CHECK_NE(km1, 1200 * m1);
}


