#pragma once

#include "TurtlebotMessage.hpp"
#include "Note.hpp"
#include <bitset>

namespace TurtlebotLibrary
{
    class Drive : public TurtlebotMessage
    {
        public:
            static const int MAX_ABS_VELOCITY = 500; // mm-s^-1
            static const int MAX_ABS_RADIUS = 2000;  // mm

            // Special cases
            static const int STRAIGHT = 32768;
            static const int CLOCKWISE = 0xFFFF;
            static const int COUNTERCLOCKWISE = 0x0001;

            Drive(int velocity, int radius);
            ~Drive();
            int GetVelocity() const;
            void SetVelocity(int velocity);
            int GetRadius() const;
            void SetRadius(int radius);

        protected:
            std::vector<uint8_t> SerializePayload();

        private:
            int velocity;
            int radius;
    };

    class DigitalOutputs : public TurtlebotMessage
    {
        public:
            DigitalOutputs();
            ~DigitalOutputs();
            std::bitset<8> GetPinEnables() const;
            bool IsPinEnabled(uint8_t pin) const;
            void SetPinEnable(uint8_t pin, bool enable);

        protected:
            std::vector<uint8_t> SerializePayload();

        private:
            std::bitset<8> pinEnable;
    };

    class Song : public TurtlebotMessage
    {
        public:
            Song(int id);
            ~Song();
            bool AddNote(Note n);
            bool AddNote(Notes n, uint8_t octave, uint8_t duration);
            int GetSongId();
            int GetSongLength();
        protected:
            std::vector<uint8_t> SerializePayload();

        private:
            int id;
            std::vector<Note> notes;
    };
}