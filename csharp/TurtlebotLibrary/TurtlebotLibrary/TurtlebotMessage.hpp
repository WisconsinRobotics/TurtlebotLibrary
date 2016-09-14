#pragma once

#pragma once

#include <cstdint>
#include "../../../cpp/include/TurtlebotLibrary.hpp"

using TurtlebotLibrary::TurtlebotCommandCode;

namespace TurtlebotLibrarySharp
{
    public enum class TurtlebotCommandCode : System::Byte
    {
        // Start Commands
        Start = 128,
        Baud = 129, // not supported

        // Mode Commands
        Safe = 131,
        Full = 132,

        // Demo Commands
        Demo = 136,

        // Actuator Commands
        Drive = 137,
        Drive_Direct = 145,
        Digital_Outputs = 147,

        // Wait Commands
        Wait_Time = 155,
        Wait_Distance = 156,
        Wait_Angle = 157,
        Wait_Event = 158,

        // Input packets
        Sensor = 142,

        // Song
        Song = 140,
        PlaySong = 141
    };

    public ref class TurtlebotMessage
    {
    public:
        TurtlebotMessage(TurtlebotCommandCode commandCode);
        virtual ~TurtlebotMessage();
        TurtlebotCommandCode GetCommandCode();
        array<System::Byte>^ Serialize();
        System::Boolean Deserialize(array<System::Byte>^ buffer, System::Int32 length);
        System::IntPtr GetRawPtr();

    private:
        TurtlebotLibrary::TurtlebotMessage *msg;
    };
}

