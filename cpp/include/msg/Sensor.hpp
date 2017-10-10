#pragma once

#include "TurtlebotMessage.hpp"
#include "TurtlebotCommandSender.hpp"
#include "Serial.hpp"
namespace TurtlebotLibrary
{
    enum class SensorPacketID : uint8_t
    {
		Distance		= 19,
		Angle			= 20,
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
		void setDistance(int distance);

    protected:
        std::vector<uint8_t> SerializePayload();

    private:
        SensorPacketID id;
    };

	class WaitDistance
	{
	public:
		WaitDistance(TurtlebotCommandSender *cmder, int distance);
		void Wait();
	private:
		SerialPort serialPort;
		int distance;
		int distance_travelled;
		TurtlebotCommandSender *cmder;
		bool finished;
	};

	class WaitAngle
	{
	public:
		WaitAngle(TurtlebotCommandSender *cmder, int distance);
		void Wait();
	private:
		SerialPort serialPort;
		int angle;
		int angle_travelled;
		TurtlebotCommandSender *cmder;
		bool finished;
	};
}