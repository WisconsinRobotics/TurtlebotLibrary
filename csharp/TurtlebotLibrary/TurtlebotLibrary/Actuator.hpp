#pragma once

#include "TurtlebotMessage.hpp"
#include "Note.hpp"

namespace TurtlebotLibrarySharp
{
    public ref class Drive : public TurtlebotMessage
    {
        public:
            static const System::Int32 MAX_ABS_VELOCITY = 500; // mm-s^-1
            static const System::Int32 MAX_ABS_RADIUS = 2000;  // mm

            // Special cases
            static const System::Int32 STRAIGHT = 32768;
            static const System::Int32 CLOCKWISE = 0xFFFF;
            static const System::Int32 COUNTERCLOCKWISE = 0x0001;

            Drive(System::Int32 velocity, System::Int32 radius);
            ~Drive();
            System::Int32 GetVelocity();
            void SetVelocity(System::Int32 velocity);
            System::Int32 GetRadius();
            void SetRadius(System::Int32 radius);

        private:
            TurtlebotLibrary::Drive *drive;
    };

    public ref class DigitalOutputs : public TurtlebotMessage
    {
        public:
            DigitalOutputs();
            ~DigitalOutputs();
            std::bitset<8> GetPinEnables();
            System::Boolean IsPinEnabled(uint8_t pin);
            void SetPinEnable(uint8_t pin, bool enable);

        private:
            TurtlebotLibrary::DigitalOutputs *digitalOutputs;
    };

    public ref class Song : public TurtlebotMessage
    {
        public:
            Song(System::Int32 id);
            ~Song();
            System::Boolean AddNote(Note n);
            System::Boolean AddNote(Notes n, System::Byte octave, System::Byte duration);
            System::Int32 GetSongId();
            System::Int32 GetSongLength();

        private:
            TurtlebotLibrary::Song *song;
    };

    public ref class PlaySong : public TurtlebotMessage
    {
        public:
            PlaySong(System::Int32 songNum);
            ~PlaySong();
            System::Int32 GetSongNum();
        private:
            TurtlebotLibrary::PlaySong *playSong;
    };
}