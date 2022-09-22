#include "melody.hpp"

class fur_elise_2 : public melody {
public:
    void play( note_player & p ){
        p.play( note{ note::D5,  note::dQ } );
        p.play( note{ note::D5s, note::dQ } );
        p.play( note{ note::D5,  note::dQ } );
        p.play( note{ note::D5s, note::dQ } );
        p.play( note{ note::D5,  note::dQ } );
        p.play( note{ note::B4,  note::dQ } );
        p.play( note{ note::D5,  note::dQ } );
        p.play( note{ note::C5,  note::dQ } );
        p.play( note{ note::A4,  note::dH } );
    }
};