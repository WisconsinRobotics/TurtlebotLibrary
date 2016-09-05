#pragma once

#include "TurtlebotMessage.hpp"
#include <cstdint>

namespace TurtlebotLibrary
{
    enum class Event : uint8_t
    {
        WheelDrop           = 1,
        FrontWheelDrop      = 2,
        LeftWheelDrop       = 3,
        RightWheelDrop      = 4,
        Bump                = 5,
        LeftBump            = 6,
        RightBump           = 7,
        VirtualWall         = 8,
        Wall                = 9,
        Cliff               = 10,
        LeftCliff           = 11,
        FrontLeftCliff      = 12,
        FrontRightCliff     = 13,
        RightCliff          = 14,
        HomeBase            = 15,
        AdvanceButton       = 16,
        PlayButton          = 17,
        DigitalInput0       = 18,
        DigitalInput1       = 19,
        DigitalInput2       = 20,
        DigitalInput3       = 21,
        Passive             = 22
    };

    class WaitTime : public TurtlebotMessage
    {
    public:
        WaitTime(uint8_t tenths);
        ~WaitTime();
        uint8_t GetDelay() const;
        void SetDelay(uint8_t time);

    protected:
        std::vector<uint8_t> SerializePayload();

    private:
        uint8_t delay;
    };

    class WaitDistance : public TurtlebotMessage
    {
    public:
        WaitDistance(int16_t dist);
        ~WaitDistance();
        int16_t GetDistance() const;
        void SetDistance(int16_t dist);

    protected:
        std::vector<uint8_t> SerializePayload();

    private:
        int16_t distance;
    };

    class WaitAngle : public TurtlebotMessage
    {
    public:
        WaitAngle(int16_t angle);
        ~WaitAngle();
        int16_t GetAngle() const;
        void SetAngle(int16_t angle);

    protected:
        std::vector<uint8_t> SerializePayload();

    private:
        int16_t angle;
    };

    class WaitEvent : public TurtlebotMessage
    {
    public:
        WaitEvent(Event e, bool inverse = false);
        ~WaitEvent();
        Event GetEvent() const;
        bool IsInverted() const;
        void SetEvent(Event e, bool inverse = false);

    protected:
        std::vector<uint8_t> SerializePayload();

    private:
        Event wait_event;
        bool inverted;
    };
}