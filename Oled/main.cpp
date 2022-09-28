#include "hwlib.hpp"
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
    return hwlib::xy(deltaX, deltaY);
}

// returns absolute position of any 60 positions on a clock
constexpr hwlib::xy clock_pos_from_minute(const int minute, const hwlib::xy clock_center, const hwlib::xy table_clock_pos[15]){
    if (minute >= 0 && minute <= 14) {
        return hwlib::xy(clock_center.x + table_clock_pos[minute].x, clock_center.y - table_clock_pos[minute].y );
    }else if(minute >= 15 && minute <= 29){
        return hwlib::xy(clock_center.x + table_clock_pos[minute-15].y, clock_center.y + table_clock_pos[minute-15].x );
    }else if(minute >= 30 && minute <= 44){
        return hwlib::xy(clock_center.x - table_clock_pos[minute-30].x, clock_center.y + table_clock_pos[minute-30].y );
    }else if(minute >= 45 && minute <= 59){
        return hwlib::xy(clock_center.x - table_clock_pos[minute-45].y, clock_center.y - table_clock_pos[minute-45].x );
    }else{
        return hwlib::xy(0, 0);
    }
}

int main(void) {
    namespace target = hwlib::target;

    // display configuration
    auto scl = target::pin_oc( target::pins::scl );
    auto sda = target::pin_oc( target::pins::sda );
    auto i2c_bus = hwlib::i2c_bus_bit_banged_scl_sda( scl, sda );

    auto display = hwlib::glcd_oled( i2c_bus, 0x3c );

    // clock properties
    const auto clock_center = hwlib::xy( 60, 30 );
    const auto clock_radius = 25;

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
    hwlib::line wijzer_seconds = hwlib::line( clock_center, clock_pos_from_minute(11, clock_center, table_clock_pos) );

    // draw center
    display.clear();
    display.write( clock_center );
    display.flush();

    for (auto i = 0; i <= 59; i += 5) {
        display.write( clock_pos_from_minute( i, clock_center, table_clock_pos ));
        display.flush();
    }

//    wijzer_seconds = hwlib::line( clock_center, clock_pos_from_minute(12, clock_center, table_clock_pos) );
    wijzer_seconds.draw( display );
    display.flush();

//    int zero = hwlib::now_us();
//    while (true) {
//
//        wijzer_seconds.draw( display );
//    }
}
