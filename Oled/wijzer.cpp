#include "wijzer.h"

void wijzer::print () {

    hwlib::line line (start, end);
    line.draw ( w );
}

void wijzer::change_endpoint(hwlib::xy new_end) {
    end = new_end;
}