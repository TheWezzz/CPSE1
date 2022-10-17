#include "catch.hpp"
#include "ostream"
#include "sstream"
#include "set.h"

//////////////////////////////////////////////
//TEST_CASE( "simple add" ){
//set x;
//x.add(5);
//
//REQUIRE(x.get_occupied_entries() = {5});
//}
////////////////////////////////////////////////
//TEST_CASE( "add vector to vector by positive" ){
//vector v( 20, 150 );
//std::stringstream s;
//
//vector x = v + vector( 5, 90 );
//s << x;
//REQUIRE( s.str() == "[25,240]" );
//
//s.str("");
//
//vector y = vector(50, 15) + v;
//s << y;
//REQUIRE( s.str() == "[70,165]" );
//}
////////////////////////////////////////////////
//TEST_CASE( "add vector to vector by negative" ){
//vector v( 50, 10 );
//std::stringstream s;
//
//vector x = v + vector( -75, 90 );
//s << x;
//REQUIRE( s.str() == "[-25,100]" );
//
//s.str("");
//
//vector y = vector(50, -15) + v;
//s << y;
//REQUIRE( s.str() == "[100,-5]" );
//}
////////////////////////////////////////////////
//TEST_CASE( "add to vector" ){
//vector v( 1, 2 );
//std::stringstream s;
//
//v += vector( 3, 20 );
//s << v;
//REQUIRE( s.str() == "[4,22]" );
//}
////////////////////////////////////////////////
//TEST_CASE( "multiply vector by integer" ){
//vector v( 5, 9 );
//std::stringstream s;
//
//vector x = v * 4;
//s << x;
//REQUIRE( s.str() == "[20,36]" );
//}
////////////////////////////////////////////////
//TEST_CASE( "multiply vector by vector" ){
//vector v( 45, 7 );
//std::stringstream s;
//
//vector x = v * vector( 3, 20 );
//s << x;
//REQUIRE( s.str() == "[135,140]" );
//
//s.str("");
//
//vector y = vector(1, 11) * v;
//s << y;
//REQUIRE( s.str() == "[45,77]" );
//}
////////////////////////////////////////////////
//TEST_CASE( "multiply vector" ){
//vector v( 11, 5 );
//std::stringstream s;
//
//v *= 11;
//s << v;
//REQUIRE( s.str() == "[121,55]" );
//}
////////////////////////////////////////////////
