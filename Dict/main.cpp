#include "set.h"
#include "iostream"

int main() {
    set test;
    test.add(400);
    test.add(6);
    test.remove(400);
    std::cout << test.get_occupied_entries()[0];
}
