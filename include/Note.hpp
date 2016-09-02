#pragma once

namespace TurtlebotLibrary
{
    enum class Notes : uint8_t
    {
        G  = 31,
        G# = 32,
        Ab = 32,
        A  = 33,
        A# = 34,
        Bb = 34,
        B  = 35,
        B  = 36,
        Cb = 35,
        C  = 36,
        C# = 37,
        Db = 37,
        D  = 38,
        D# = 39,
        Eb = 39,
        E  = 40,
        Fb = 40,
        F  = 41,
        F# = 42
    };

    class Note
    {
        public:
            Note(Notes note, int duration);
            ~Note();
        private:
            Notes note;
            int duration;
    }    

}