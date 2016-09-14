#include "msg/Sensor.hpp"

using namespace TurtlebotLibrary;


Sensor::Sensor(SensorPacketID packet_id) : TurtlebotMessage(TurtlebotCommandCode::Sensor)
{
    this->id = packet_id;
}

Sensor::~Sensor()
{
}

SensorPacketID Sensor::GetPacketID() const
{
    return this->id;
}
void Sensor::SetPacketID(SensorPacketID packet_id)
{
    this->id = packet_id;
}

std::vector<uint8_t> Sensor::SerializePayload()
{
    std::vector<uint8_t> payload = { static_cast<uint8_t>(this->id) };
    return payload;
}
