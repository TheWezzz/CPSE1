#include "hwlib.hpp"
#include "note_player_pc.hpp"

const char* note_player_pc::find_note(int f) {
    switch (f) {
        case 0:
            return "silence";
        case 440:
            return "A4";
        case 466:
            return "A4s";
        case 494:
            return "B4";
        case 523:
            return "C5";
        case 554:
            return "C5s";
        case 587:
            return "D5";
        case 622:
            return "D5s";
        case 659:
            return "E5";
        case 698:
            return "F5";
        case 740:
            return "F5s";
        case 784:
            return "G5";
        case 830:
            return "G5s";
        case 880:
            return "A5";
        case 932:
            return "A5s";
        case 987:
            return "B5";
        default:
            return "error";
    }
}

void note_player_pc::play(const note& n) {
    hwlib::wait_ms( 100 );
    int f = n.frequency;

    if (f < 0) {
        hwlib::cout << "error" << hwlib::endl;
        return;
    } else if (f < 988) {
        hwlib::cout << find_note( f ) << hwlib::endl;
//        hwlib::cout << "note found!" << hwlib::endl;
        return;

    } else {
        hwlib::cout << find_note( f / 2 ) << hwlib::endl;
//        hwlib::cout << "note found!" << hwlib::endl;
        return;
    }
}
