#pragma once

#include <cstdint>

namespace TurtlebotLibrary
{
    enum class Notes : uint8_t
    {
        Rest = 0,
        G  = 31,
        Gsharp = 32,
        Aflat = 32,
        A  = 33,
        Asharp = 34,
        Bflat = 34,
        B  = 35,
        Bsharp  = 36,
        Cflat = 35,
        C  = 36,
        Csharp = 37,
        Dflat = 37,
        D  = 38,
        Dsharp = 39,
        Eflat = 39,
        E  = 40,
        Fflat = 40,
        F  = 41,
        Fsharp = 42
    };

    struct Note
    {
        Notes note;
        uint8_t octave;
        uint8_t duration;
    };
}