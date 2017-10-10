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

WaitDistance::WaitDistance(TurtlebotCommandSender *cmder, int distance)
{
	this->distance = distance;
	this->distance_travelled = 0;
	this->cmder = cmder;
}

void WaitDistance::Wait()
{
	Sensor *dis = new Sensor(SensorPacketID::Distance);
	while (!finished)
	{
		cmder->SendTurtlebotMessage(dis);
		uint8_t *buffer;
		if (this->serialPort.ReadData(buffer, 2) != 2)
			return;

		this->distance_travelled += buffer[1] << 8 | buffer[0];
		if (this->distance_travelled >= distance)
		{
			finished = true;
		}
	}
}

WaitAngle::WaitAngle(TurtlebotCommandSender cmder, int angle)
{
	this->angle = angle;
}

void WaitAngle::Wait()
{
	Sensor *ang = new Sensor(SensorPacketID::Angle);
	while (!finished)
	{
		cmder.SendTurtlebotMessage(ang);
		angle_travelled += serialPort.ReadData(ang, 2);
		if (angle_travelled >= angle)
		{
			finished = true;
		}
	}
}

