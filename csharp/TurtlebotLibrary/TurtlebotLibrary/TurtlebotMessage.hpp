#pragma once

#include <cstdint>
#include "../../../cpp/include/Serial.hpp"
#include "../../../cpp/include/TurtlebotMessage.hpp"
#include "../../../cpp/include/Note.hpp"
#include "../../../cpp/include/msg/Actuator.hpp"
#include "../../../cpp/include/msg/Mode.hpp"
#include "../../../cpp/include/msg/Start.hpp"
#include "../../../cpp/include/msg/Sensor.hpp"

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

        // Input packets
        Sensor = 142,

        // Song
        Song = 140,
        PlaySong = 141
    };

    public ref class TurtlebotMessage
    {
    public:
        TurtlebotMessage();
        ~TurtlebotMessage();
        TurtlebotCommandCode GetCommandCode();
        array<System::Byte>^ Serialize();
        System::Boolean Deserialize(array<System::Byte>^ buffer, System::Int32 length);
        System::IntPtr GetRawPtr();

    protected:
        TurtlebotLibrary::TurtlebotMessage *msg = nullptr;
    };
}

