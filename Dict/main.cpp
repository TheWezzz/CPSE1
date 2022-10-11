#include "set.h"
#include "iostream"

int main() {
    set test;
    test.add(4);
    test.add(6);
    std::cout << test.get_occupied_entries()[0];
}
