#pragma once

#include "TurtlebotMessage.hpp"

namespace TurtlebotLibrary
{
    enum class SensorPacketID : uint8_t
    {
        SongNumber      = 36,
        SongPlaying     = 37
    };

    class Sensor : public TurtlebotMessage
    {
    public:
        Sensor(SensorPacketID packet_id);
        ~Sensor();
        SensorPacketID GetPacketID() const;
        void SetPacketID(SensorPacketID packet_id);

    protected:
        std::vector<uint8_t> SerializePayload();

    private:
        SensorPacketID id;
    };
}