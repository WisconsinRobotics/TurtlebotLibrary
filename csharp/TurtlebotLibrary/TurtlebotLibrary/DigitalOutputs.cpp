#include "Actuator.hpp"

using namespace TurtlebotLibrarySharp;

DigitalOutputs::DigitalOutputs() : TurtlebotMessage(TurtlebotCommandCode::Digital_Outputs)
{
    this->digitalOutputs = new TurtlebotLibrary::DigitalOutputs();
}

DigitalOutputs::~DigitalOutputs()
{
    delete this->digitalOutputs;
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
