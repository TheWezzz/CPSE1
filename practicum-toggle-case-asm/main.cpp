#include "hwlib.hpp"

extern "C" {
    void application();
    void print_asciz(const char* s);
    void uart_put_char(char c) {
        hwlib::cout << c;
    }
    char toggle_case(char c);
}

int main(void) {

    namespace target = hwlib::target;

    // wait for the PC console to start
    hwlib::wait_ms( 2000 );

    application();
}