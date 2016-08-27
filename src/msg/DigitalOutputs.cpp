#include "msg/Actuator.hpp"
#include <map>

using namespace TurtlebotLibrary;

static std::map<uint8_t, uint8_t> pinToBitPosMap = {
    { 19, 0 },
    { 7,  1 },
    { 20, 2 }
};

DigitalOutputs::DigitalOutputs() : TurtlebotMessage(TurtlebotCommandCode::Digital_Outputs)
{
    pinEnable = std::bitset<8>(0);
}

DigitalOutputs::~DigitalOutputs()
{
}

std::bitset<8> DigitalOutputs::GetPinEnables() const
{
    return this->pinEnable;
}

bool DigitalOutputs::IsPinEnabled(uint8_t pin) const
{
    if (pinToBitPosMap.find(pin) == pinToBitPosMap.end())
        return false;
        
    return this->pinEnable[pinToBitPosMap[pin]]; 
}

void DigitalOutputs::SetPinEnable(uint8_t pin, bool enable)
{
    if (pinToBitPosMap.find(pin) == pinToBitPosMap.end())
        return;

    this->pinEnable[pinToBitPosMap[pin]] = enable; 
}

std::vector<uint8_t> DigitalOutputs::SerializePayload()
{
    std::vector<uint8_t> payload { static_cast<uint8_t>(pinEnable.to_ulong()) };
    return payload;
}