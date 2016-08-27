#include "TurtlebotMessage.hpp"

using namespace TurtlebotLibrary;


TurtlebotMessage::TurtlebotMessage(TurtlebotCommandCode commandCode)
{
    this->commandCode = commandCode;
}

TurtlebotMessage::~TurtlebotMessage()
{
}

TurtlebotCommandCode TurtlebotMessage::GetCommandCode() const
{
    return commandCode;
}

std::vector<uint8_t> TurtlebotMessage::Serialize()
{
    std::vector<uint8_t> data;
    data.push_back(static_cast<uint8_t>(this->commandCode));

    std::vector<uint8_t> payload = this->SerializePayload();
    if (payload.size() != 0)
    {
        data.insert(data.end(), payload.begin(), payload.end());
    }

    return data;
}

bool TurtlebotMessage::Deserialize(const uint8_t *buffer, uint8_t length)
{
    if (!buffer || length == 0)
        return false;

    if (buffer[0] != static_cast<uint8_t>(commandCode))
        return false;

    return this->DeserializePayload(&buffer[1], length - 1);
}

std::vector<uint8_t> TurtlebotMessage::SerializePayload()
{
    return std::vector<uint8_t>();
}

bool TurtlebotMessage::DeserializePayload(const uint8_t *payload, uint8_t payloadLength)
{
    return true;
}