#pragma once

#include <cstdint>

namespace TurtlebotLibrary
{
    enum class Notes : uint8_t
    {
        C           = 0,
        Csharp      = 1,
        Dflat       = 1,
        D           = 2,
        Dsharp      = 3,
        Eflat       = 3,
        E           = 4,
        Fflat       = 4,
        F           = 5,
        Fsharp      = 6,
        G           = 7,
        Gsharp      = 8,
        Aflat       = 8,
        A           = 9,
        Asharp      = 10,
        Bflat       = 10,
        B           = 11,
        Bsharp      = 0,
        Cflat       = 11,
    };

    struct Note
    {
        Notes note;
        uint8_t octave;
        uint8_t duration;
    };

    inline Note GenerateRestNote(uint8_t duration)
    {
        // As per spec, Turtlebot treats any MIDI note
        // outside the range 31-127 as a rest note 
        return { Notes::C, 0, duration };
    }
}