#include "hwlib.hpp"
#include "set.h"
#include "cmath"
#include "ctime"

// returns degrees converted to radians
constexpr double radians_from_degrees(int degrees) {
    return 2 * 3.14 * (degrees / 360.0);
}

// returns n to the power of g
constexpr double pow(double g, int n) {
    double result = 1;
    while (n > 0) {
        result *= g;
        --n;
    }
    return result;
}

// returns n factorial
constexpr double fac(int n) {
    double result = 1;
    while (n > 0) {
        result *= n;
        --n;
    }
    return result;
}

// returns sinus from radians with Taylorreeks
constexpr double sinus(double radians) {
    return radians
            - pow( radians, 3 ) / fac( 3 )
            + pow( radians, 5 ) / fac( 5 )
            - pow( radians, 7 ) / fac( 7 )
            + pow( radians, 9 ) / fac( 9 );

}

// calculate x and y difference from center point to edge of circle
constexpr hwlib::xy calc_dx_dy_from_center_of_circle(const int radius, const int degrees) {
    double deltaX = radius * sinus( radians_from_degrees( degrees ));
    double deltaY = radius * sinus( radians_from_degrees( 90 - degrees ));
    return hwlib::xy( deltaX, deltaY );
}

// returns absolute position of any 60 positions on a clock
constexpr hwlib::xy clock_pos_from_minute(int& minute, const hwlib::xy& clock_center, const hwlib::xy table[15], const bool short_length) {
    minute = minute % 60;
    hwlib::xy result;
    if (short_length) {
        if (minute >= 0 && minute <= 14) {
            result = hwlib::xy( clock_center.x + 0.7 * table[minute].x, clock_center.y - 0.7 * table[minute].y );
        } else if (minute >= 15 && minute <= 29) {
            result = hwlib::xy( clock_center.x + 0.7 * table[minute - 15].y, clock_center.y + 0.7 * table[minute - 15].x );
        } else if (minute >= 30 && minute <= 44) {
            result = hwlib::xy( clock_center.x - 0.7 * table[minute - 30].x, clock_center.y + 0.7 * table[minute - 30].y );
        } else if (minute >= 45 && minute <= 59) {
            result = hwlib::xy( clock_center.x - 0.7 * table[minute - 45].y, clock_center.y - 0.7 * table[minute - 45].x );
        } else {
            result = hwlib::xy( 0, 0 );
        }
    } else {
        if (minute >= 0 && minute <= 14) {
            result = hwlib::xy( clock_center.x + table[minute].x, clock_center.y - table[minute].y );
        } else if (minute >= 15 && minute <= 29) {
            result = hwlib::xy( clock_center.x + table[minute - 15].y, clock_center.y + table[minute - 15].x );
        } else if (minute >= 30 && minute <= 44) {
            result = hwlib::xy( clock_center.x - table[minute - 30].x, clock_center.y + table[minute - 30].y );
        } else if (minute >= 45 && minute <= 59) {
            result = hwlib::xy( clock_center.x - table[minute - 45].y, clock_center.y - table[minute - 45].x );
        } else {
            result = hwlib::xy( 0, 0 );
        }
    }
    return result;
}

int main(void) {
    namespace target = hwlib::target;

    // buttons
    auto b1 = target::pin_in( target::pins::a10 );
    auto b2 = target::pin_in( target::pins::a11 );

    // display configuration
    auto scl = target::pin_oc( target::pins::scl );
    auto sda = target::pin_oc( target::pins::sda );
    auto i2c_bus = hwlib::i2c_bus_bit_banged_scl_sda( scl, sda );

    auto display = hwlib::glcd_oled( i2c_bus, 0x3c );
    display.clear();

    // clock properties
    const auto clock_center = hwlib::xy( 60, 30 );
    const auto clock_radius = 30;

    // lookup-table for first quarter of a clock (centerpoint still not defined)
    const hwlib::xy table_clock_pos[15] = {
            calc_dx_dy_from_center_of_circle( clock_radius, 0 ),
            calc_dx_dy_from_center_of_circle( clock_radius, 6 ),
            calc_dx_dy_from_center_of_circle( clock_radius, 12 ),
            calc_dx_dy_from_center_of_circle( clock_radius, 18 ),
            calc_dx_dy_from_center_of_circle( clock_radius, 24 ),
            calc_dx_dy_from_center_of_circle( clock_radius, 30 ),
            calc_dx_dy_from_center_of_circle( clock_radius, 36 ),
            calc_dx_dy_from_center_of_circle( clock_radius, 42 ),
            calc_dx_dy_from_center_of_circle( clock_radius, 48 ),
            calc_dx_dy_from_center_of_circle( clock_radius, 54 ),
            calc_dx_dy_from_center_of_circle( clock_radius, 60 ),
            calc_dx_dy_from_center_of_circle( clock_radius, 66 ),
            calc_dx_dy_from_center_of_circle( clock_radius, 72 ),
            calc_dx_dy_from_center_of_circle( clock_radius, 78 ),
            calc_dx_dy_from_center_of_circle( clock_radius, 84 )
    };

    // wijzers
    int seconds_pos = 0;
    int minutes_pos = 0;
    int hours_pos = 0;
    wijzer seconds = wijzer( display, clock_center, clock_pos_from_minute( seconds_pos, clock_center, table_clock_pos, false ));
    wijzer minutes = wijzer( display, clock_center, clock_pos_from_minute( minutes_pos, clock_center, table_clock_pos, false ));
    wijzer hours = wijzer( display, clock_center, clock_pos_from_minute( hours_pos, clock_center, table_clock_pos, true ));
    unsigned int offset_minutes = 0;
    unsigned int offset_hours = 0;

    // draw center
    display.write( clock_center );
    display.flush();

    // draw clock
    for (auto i = 0; i <= 59; i += 5) {
        display.write( clock_pos_from_minute( i, clock_center, table_clock_pos, false ));
        display.flush();
    }

    // loop
    const int zero = hwlib::now_us();
    while (true) {
        // check real time and skip if we're not in a tenth of a second
        long long int ms_from_zero = (hwlib::now_us() - zero) / 1000;
        if (ms_from_zero % 100 != 0) {
            continue;
        } else {
            // update display
            display.clear();

            display.write( clock_center );

            for (auto i = 0; i <= 59; i += 5) {
                display.write( clock_pos_from_minute( i, clock_center, table_clock_pos, false ));
            }

            seconds_pos = (ms_from_zero / 1000);
            minutes_pos = seconds_pos/60 + offset_minutes;
            hours_pos =   minutes_pos/12 + offset_hours;

            seconds.change_endpoint( clock_pos_from_minute(seconds_pos, clock_center, table_clock_pos, false ));
            minutes.change_endpoint( clock_pos_from_minute(minutes_pos, clock_center, table_clock_pos, false ));
            hours.change_endpoint( clock_pos_from_minute(hours_pos, clock_center, table_clock_pos, true ));

            seconds.print();
            minutes.print();
            hours.print();

            display.flush();
        }
        // read buttons and apply offset
        if (b1.read()) {
            offset_minutes++;
        }
        if (b2.read()) {
            offset_hours++;
        }
    }
}
