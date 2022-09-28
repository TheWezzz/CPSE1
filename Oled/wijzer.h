#ifndef V2CPSE1_EXAMPLES_JAN_LINE_H
#define V2CPSE1_EXAMPLES_JAN_LINE_H

#include "hwlib.hpp"

class wijzer {
private:

    hwlib::glcd_oled& w;
    hwlib::xy start;
    hwlib::xy end;

public:

    wijzer(
            hwlib::glcd_oled& w,
            hwlib::xy p_start,
            hwlib::xy p_end
    )
            :
            w( w ) {
        start = p_start;
        end = p_end;
    }

    void print();

    void change_endpoint(hwlib::xy new_end);
};


#endif //V2CPSE1_EXAMPLES_JAN_LINE_H
