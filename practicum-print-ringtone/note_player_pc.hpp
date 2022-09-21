#ifndef _NOTE_PLAYER_PC_HPP
#define _NOTE_PLAYER_PC_HPP

#include "note_player.hpp"

// ===========================================================================
//
// simple note player for a speaker connected to a GPIO pin
//
// ===========================================================================

class note_player_pc
        : public note_player {
public:
    note_player_pc(){};

    void play(const note& n) override;

private:
    const char* find_note(int f);
};

#endif
