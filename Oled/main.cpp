#include "hwlib.hpp"
#include "cmath"

constexpr double radians_from_degrees(int degrees) {
    return 2 * 3.14 * (degrees / 360.0);
}

constexpr double pow(double g, int n) {
    double result = 1;
    while (n > 0) {
        result *= g;
        --n;
    }
    return result;
}

constexpr double fac(int n) {
    double result = 1;
    while (n > 0) {
        result *= n;
        --n;
    }
    return result;
}

constexpr double sinus(double radians) {
    return  radians
            - pow( radians, 3 ) / fac( 3 )
            + pow( radians, 5 ) / fac( 5 )
            - pow( radians, 7 ) / fac( 7 )
            + pow( radians, 9 ) / fac( 9 );
}

constexpr hwlib::xy calc_xy_from_center_radius_degrees(const hwlib::xy center, const int radius, const int degrees){
    double deltaX = 0;
    double deltaY = 0;
    if (degrees >= 0 && degrees <= 180) {
//        deltaX = radius * sinus( radians_from_degrees( degrees ));
//        deltaY = radius * sinus( radians_from_degrees( 90 - degrees ));
    }else if (degrees >= 181 && degrees <= 360){
        deltaX = radius * sinus( radians_from_degrees( degrees) * -1);
        deltaY = radius * sinus( radians_from_degrees( 90 - degrees ));
    }
    return hwlib::xy(floor(center.x + deltaX), floor(center.y - deltaY));
}

int main(void) {
    namespace target = hwlib::target;

    auto scl = target::pin_oc( target::pins::scl );
    auto sda = target::pin_oc( target::pins::sda );

    auto i2c_bus = hwlib::i2c_bus_bit_banged_scl_sda( scl, sda );

    auto display = hwlib::glcd_oled( i2c_bus, 0x3c );

    const auto clock_center = hwlib::xy(60,30);
    const auto clock_radius = 25;

    const hwlib::xy table_clock_pos[12] = {
            calc_xy_from_center_radius_degrees(clock_center, clock_radius, 0),
            calc_xy_from_center_radius_degrees(clock_center, clock_radius, 30 ),
            calc_xy_from_center_radius_degrees(clock_center, clock_radius, 60 ),
            calc_xy_from_center_radius_degrees(clock_center, clock_radius, 90 ),
            calc_xy_from_center_radius_degrees(clock_center, clock_radius, 120 ),
            calc_xy_from_center_radius_degrees(clock_center, clock_radius, 150 ),
            calc_xy_from_center_radius_degrees(clock_center, clock_radius, 180 ),
            calc_xy_from_center_radius_degrees(clock_center, clock_radius, 210 ),
            calc_xy_from_center_radius_degrees(clock_center, clock_radius, 240 ),
            calc_xy_from_center_radius_degrees(clock_center, clock_radius, 270 ),
            calc_xy_from_center_radius_degrees(clock_center, clock_radius, 300 ),
            calc_xy_from_center_radius_degrees(clock_center, clock_radius, 330 )
    };

    display.clear();
    display.write(clock_center);
    for (auto i = 0; i <= 11; i++) {
        display.write( table_clock_pos[i]);
    }
    display.flush();
}
