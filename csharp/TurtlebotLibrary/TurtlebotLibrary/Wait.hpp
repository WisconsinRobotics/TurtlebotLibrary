#pragma once

#include "TurtlebotMessage.hpp"

namespace TurtlebotLibrarySharp
{
    public enum class Event : System::Byte
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

    public ref class WaitTime : public TurtlebotMessage
    {
    public:
        WaitTime(System::Byte tenths);
        ~WaitTime();
        System::Byte GetDelay();
        void SetDelay(System::Byte time);
    };

    public ref class WaitDistance : public TurtlebotMessage
    {
    public:
        WaitDistance(System::Int16 dist);
        ~WaitDistance();
        System::Int16 GetDistance();
        void SetDistance(System::Int16 dist);
    };

    public ref class WaitAngle : public TurtlebotMessage
    {
    public:
        WaitAngle(System::Int16 angle);
        ~WaitAngle();
        System::Int16 GetAngle();
        void SetAngle(System::Int16 angle);
    };

    public ref class WaitEvent : public TurtlebotMessage
    {
    public:
        WaitEvent(Event e, bool inverse);
        ~WaitEvent();
        Event GetEvent();
        bool IsInverted();
        void SetEvent(Event e, bool inverse);
    };
}