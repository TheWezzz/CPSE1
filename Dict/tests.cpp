#include "catch.hpp"
#include "set.h"

//////////////////////////////////////////////
TEST_CASE( "add" ){
set test;
test.add(5);

std::vector<int> test_vect = test.get_occupied_entries();
std::vector<int> test_expect = {5};

REQUIRE(test_vect == test_expect);
}

//////////////////////////////////////////////
TEST_CASE( "add twice" ){
set test;
test.add(5);
test.add(5);

std::vector<int> test_vect = test.get_occupied_entries();
std::vector<int> test_expect = {5};

REQUIRE(test_vect == test_expect);
}

//////////////////////////////////////////////
TEST_CASE( "remove" ){
set test;
test.add(5);
test.add(50);
test.remove(5);

std::vector<int> test_vect = test.get_occupied_entries();
std::vector<int> test_expect = {50};

REQUIRE(test_vect == test_expect);
}

//////////////////////////////////////////////
TEST_CASE( "remove non-existent" ){
set test;
test.add(5);
test.add(50);
test.remove(4);

std::vector<int> test_vect = test.get_occupied_entries();
std::vector<int> test_expect = {5, 50};

REQUIRE(test_vect == test_expect);
}

//////////////////////////////////////////////
TEST_CASE( "remove and replace" ){
set test;
test.add(5);
test.add(50);
test.remove(5);
test.add(10);

std::vector<int> test_vect = test.get_occupied_entries();
std::vector<int> test_expect = {10, 50};

REQUIRE(test_vect == test_expect);
}

//////////////////////////////////////////////
TEST_CASE( "contains" ){
set test;
test.add(5);
test.add(50);

bool test_bool1 = test.contains(5) && test.contains(50);
bool test_expect1 = true;

bool test_bool2 = test.contains(500);
bool test_expect2 = false;

REQUIRE(test_bool1 == test_expect1);
REQUIRE(test_bool2 == test_expect2);
}

//////////////////////////////////////////////
TEST_CASE( "too many numbers" ){
set test;
test.add(5);
test.add(50);
test.add(4);
test.add(40);
test.add(3);
test.add(30);
test.add(2);
test.add(20);
test.add(1);
test.add(10);
test.add(900);

std::vector<int> test_vect = test.get_occupied_entries();
std::vector<int> test_expect = {5, 50, 4, 40, 3, 30, 2, 20, 1, 10};

REQUIRE(test_vect == test_expect);
}

//////////////////////////////////////////////
TEST_CASE( "too less numbers" ){
set test;
test.add(5);
test.add(50);
test.remove(5);
test.remove(50);

std::vector<int> test_vect = test.get_occupied_entries();
std::vector<int> test_expect = {};

REQUIRE(test_vect == test_expect);
}

//////////////////////////////////////////////
TEST_CASE( "too many numbers, multiple remove and replace, add twice" ){
set test;
test.add(5);
test.add(50);
test.add(4);
test.add(40);
test.add(3);
test.add(30);
test.add(2);
test.add(20);
test.add(1);
test.add(10);
test.add(900);

test.remove(1);
test.remove(20);
test.remove(2);
test.remove(30);
test.remove(3);
test.add(300);
test.remove(40);
test.remove(4);
test.remove(50);
test.add(5);
test.add(500);

std::vector<int> test_vect = test.get_occupied_entries();
std::vector<int> test_expect = {5, 500, 300, 10};

REQUIRE(test_vect == test_expect);
}
