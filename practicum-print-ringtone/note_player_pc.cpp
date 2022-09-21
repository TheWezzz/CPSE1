#include "hwlib.hpp"
#include "note_player_pc.hpp"
#include "iostream"


void note_player_pc::play(const note& n) {
    if (n.frequency == 0) {
        hwlib::wait_us( n.duration );

    } else {
        auto end = hwlib::now_us() + n.duration;
        do {
            static const int f = n.frequency;
            switch(f){
                case 440:
                    hwlib::cout << "A4" << hwlib::endl;
                    break;
                case 466:
                    hwlib::cout << "A4s" << hwlib::endl;
                    break;
                case 494:
                    hwlib::cout << "B4" << hwlib::endl;
                    break;
                case 523:
                    hwlib::cout << "C5" << hwlib::endl;
                    break;
                case 554:
                    hwlib::cout << "C5s" << hwlib::endl;
                    break;
                case 587:
                    hwlib::cout << "D5" << hwlib::endl;
                    break;
                case 622:
                    hwlib::cout << "D5s" << hwlib::endl;
                    break;
                case 659:
                    hwlib::cout << "E5" << hwlib::endl;
                    break;
                case 698:
                    hwlib::cout << "F5" << hwlib::endl;
                    break;
                case 740:
                    hwlib::cout << "F5s" << hwlib::endl;
                    break;
                case 784:
                    hwlib::cout << "G5" << hwlib::endl;
                    break;
                case 830:
                    hwlib::cout << "G5s" << hwlib::endl;
                    break;
                case 880:
                    hwlib::cout << "A5" << hwlib::endl;
                    break;
                case 932:
                    hwlib::cout << "A5s" << hwlib::endl;
                    break;
                case 987:
                    hwlib::cout << "B5" << hwlib::endl;
                    break;

            }
        } while (end > hwlib::now_us());
    }
}
