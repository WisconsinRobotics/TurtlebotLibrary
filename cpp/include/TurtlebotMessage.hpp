#pragma once

#include <cstdint>
#include <vector>

namespace TurtlebotLibrary
{
	enum class TurtlebotCommandCode : uint8_t
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

    class TurtlebotMessage
    {
        public:
            TurtlebotMessage(TurtlebotCommandCode commandCode);
            virtual ~TurtlebotMessage();
            TurtlebotCommandCode GetCommandCode() const;
            std::vector<uint8_t> Serialize();
            bool Deserialize(const uint8_t *buffer, uint8_t length);

        protected:
            virtual std::vector<uint8_t> SerializePayload();
            virtual bool DeserializePayload(const uint8_t *payload, uint8_t payloadLength);

            TurtlebotCommandCode commandCode;
    };
}

