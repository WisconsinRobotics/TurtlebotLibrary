#pragma once

#include "TurtlebotMessage.hpp"

namespace TurtlebotLibrarySharp
{
    enum class SensorPacketID : System::Byte
    {
        SongNumber      = 36,
        SongPlaying     = 37
    };

    public ref class Sensor : public TurtlebotMessage
    {
    public:
        Sensor(SensorPacketID packet_id);
        ~Sensor();
        SensorPacketID GetPacketID();
        void SetPacketID(SensorPacketID packet_id);

    private:
        TurtlebotLibrary::SensorPacketID *id;
    };
}