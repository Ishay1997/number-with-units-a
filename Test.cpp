#include "NumberWithUnits.hpp"
#include "doctest.h"
//#include <algorithm>
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
// TEST_CASE("plus onari"){
// NumberWithUnits::read_units(units_file);
//     CHECK_EQ(+(USDminos1),USD1);
//     CHECK_EQ(+ILSminos3_3,ILS3_3);
// }
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

//  TEST_CASE("exception"){
//      CHECK_THROWS(USD1==m1000);
//      CHECK_THROWS(km1==min1);
//      CHECK_THROWS(kg1==sec60);
//      CHECK_THROWS(ILS3_3==min1);
//  }
// #include "doctest.h"
// #include <algorithm>
// #include <string>
// #include <fstream>
// #include "NumberWithUnits.hpp"

// using namespace std;
// using namespace ariel;

// /**
//  * This class represents the test file for the initial part of the task.
//  *
//  * @author Liav Weiss
//  */

// ifstream units_file{"units.txt"};

// TEST_CASE("Test the operators: (1)+ (2)+= (3)+ (4)- (5)-= (6)- "){
//     NumberWithUnits::read_units(units_file);

//     NumberWithUnits n1{2, "ton"};
//     NumberWithUnits n2{1, "kg"};
//     NumberWithUnits n3{3, "g"};

//     // +
//     CHECK(n1 + n2 == NumberWithUnits {2.001, "ton"});
//     CHECK(n2 + n1 == NumberWithUnits {2001, "kg"});
//     CHECK(n1 + n3 == NumberWithUnits {2.000003, "ton"});
//     CHECK(n3 + n1 == NumberWithUnits {2000003, "g"});

//     // + (unary)
//     CHECK(n1 == NumberWithUnits {2, "ton"});
//     CHECK(n2 == NumberWithUnits {1, "kg"});
//     CHECK(n3 == NumberWithUnits {3, "g"});

//     // +=
//     CHECK((n1 += NumberWithUnits {1, "ton"}) == NumberWithUnits {3, "ton"});
//     CHECK((n2 += NumberWithUnits {1, "kg"}) == NumberWithUnits {2, "kg"});
//     CHECK((n1 += NumberWithUnits {1, "g"}) == NumberWithUnits {4, "g"});

//     // -=
//     CHECK((n1 -= NumberWithUnits {1, "ton"}) == NumberWithUnits {2, "ton"});
//     CHECK((n1 -= NumberWithUnits {1, "kg"}) == NumberWithUnits {1, "kg"});
//     CHECK((n1 -= NumberWithUnits {1, "g"}) == NumberWithUnits {3, "g"});

//     // -
//     CHECK(n1-n2 == NumberWithUnits {1.999, "ton"});
//     CHECK(n2-n1 == NumberWithUnits {1999, "kg"});
//     CHECK(n1-n3 == NumberWithUnits {1.000097, "ton"});
//     CHECK(n3-n1 == NumberWithUnits {1000097, "g"});

//     // - (unary)
//     CHECK(-n1 == NumberWithUnits {-2, "ton"});
//     CHECK(-n2 == NumberWithUnits {-1, "kg"});
//     CHECK(-n3 == NumberWithUnits {-3, "g"});

// }

// TEST_CASE("Test the operators: (1)> (2)>= (3)< (4)<= (5)== (6)!= "){
//     NumberWithUnits::read_units(units_file);

//     NumberWithUnits n1{1, "ton"};
//     NumberWithUnits n2{1, "kg"};
//     NumberWithUnits n3{1, "g"};

//     // >
//     CHECK(n1 > n3);
//     CHECK(n1 > n2);
//     CHECK(n2 > n3);

//     // >=
//     CHECK(n1 >= NumberWithUnits {1000, "kg"});
//     CHECK(n1 >= NumberWithUnits {1000000, "g"});
//     CHECK(n2 >= NumberWithUnits {1000, "g"});

//     // <
//     CHECK(n3 < n1);
//     CHECK(n3 < n2);
//     CHECK(n2 < n1);

//     // <=
//     CHECK(n2 <= NumberWithUnits {0.001, "ton"});
//     CHECK(n3 <= NumberWithUnits {0.000001, "ton"});
//     CHECK(n3 <= NumberWithUnits {0.001, "kg"});

//     // ==
//     CHECK(n1 == NumberWithUnits {1, "ton"});
//     CHECK(n1 == NumberWithUnits {1000, "kg"});
//     CHECK(n1 == NumberWithUnits {1000000, "g"});
//     CHECK(n2 == NumberWithUnits {0.001, "ton"});
//     CHECK(n2 == NumberWithUnits {1, "kg"});
//     CHECK(n2 == NumberWithUnits {1000, "g"});
//     CHECK(n3 <= NumberWithUnits {1, "g"});
//     CHECK(n3 <= NumberWithUnits {0.001, "kg"});
//     CHECK(n3 <= NumberWithUnits {0.000001, "ton"});

//     // !=
//     CHECK(n1 != NumberWithUnits {1, "kg"});
//     CHECK(n2 != NumberWithUnits {1, "g"});
//     CHECK(n3 != NumberWithUnits {1, "ton"});

// }

// TEST_CASE("Test the operators: (1)++(after). (2)++(before). (3)--(after). (4)(before)-- "){
//     NumberWithUnits::read_units(units_file);

//     NumberWithUnits n1{1, "ton"};

//     CHECK(n1++ == NumberWithUnits {1, "ton"});
//     CHECK(n1 == NumberWithUnits {2, "ton"});
//     CHECK(++n1 == NumberWithUnits {3, "ton"});
//     CHECK(n1++ == NumberWithUnits {3, "ton"});
//     CHECK(n1-- == NumberWithUnits {4, "ton"});
//     CHECK(--n1 == NumberWithUnits {2, "ton"});
//     CHECK(--n1 == NumberWithUnits {1, "ton"});

// }

// TEST_CASE("Test the operators: (1)* (2)* (3)*= (4)*= "){
//     NumberWithUnits::read_units(units_file);

//     NumberWithUnits n1{1, "ton"};

//     CHECK(n1*2 == NumberWithUnits {2, "ton"});
//     CHECK(2*n1 == NumberWithUnits {4, "ton"});
//     CHECK((n1*=2) == NumberWithUnits {8, "ton"});

// }

// TEST_CASE("Test the operators: (1)<<(cout) (2)>>(cin)"){
//     NumberWithUnits::read_units(units_file);

//     NumberWithUnits n1{1, "ton"};

//     CHECK(n1*2 == NumberWithUnits {2, "ton"});
//     CHECK(2*n1 == NumberWithUnits {4,"ton"});
//     CHECK((n1*=2) == NumberWithUnits {8, "ton"});

// }
