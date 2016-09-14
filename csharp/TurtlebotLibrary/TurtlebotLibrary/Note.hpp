#pragma once

namespace TurtlebotLibrarySharp
{
    public enum class Notes : System::Byte
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

    public ref struct Note
    {
        Notes note;
        System::Byte octave;
        System::Byte duration;
    };

    Note^ GenerateRestNote(System::Byte duration)
    {
        // As per spec, Turtlebot treats any MIDI note
        // outside the range 31-127 as a rest note 
        Note^ rest = gcnew Note();
        rest->note = Notes::C;
        rest->octave = 0;
        rest->duration = duration;

        return rest;
    }
}