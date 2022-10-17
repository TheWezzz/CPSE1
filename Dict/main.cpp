#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
//#include "catch.hpp"
#include "set.h"
#include "iostream"

int main(){
    set test;
    test.add(5);
    test.add(8);
    test.add(10);
    test.remove(8);
    std::cout << test;
}