#include "Sensor.hpp"

using namespace TurtlebotLibrarySharp;


Sensor::Sensor(SensorPacketID packet_id) : TurtlebotMessage()
{
    this->msg = new TurtlebotLibrary::Sensor((TurtlebotLibrary::SensorPacketID)packet_id);
}

Sensor::~Sensor()
{
}

SensorPacketID Sensor::GetPacketID()
{
    return (SensorPacketID) static_cast<TurtlebotLibrary::Sensor *>(this->msg)->GetPacketID();
}

void Sensor::SetPacketID(SensorPacketID packet_id)
{
    static_cast<TurtlebotLibrary::Sensor *>(this->msg)->SetPacketID((TurtlebotLibrary::SensorPacketID) packet_id);
}