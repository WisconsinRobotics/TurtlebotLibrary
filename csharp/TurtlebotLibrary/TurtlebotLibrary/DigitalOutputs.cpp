#include "Actuator.hpp"


using namespace TurtlebotLibrarySharp;

DigitalOutputs::DigitalOutputs() : TurtlebotMessage()
{
    this->msg = new TurtlebotLibrary::DigitalOutputs();
}

DigitalOutputs::~DigitalOutputs()
{
}

array<System::Boolean>^ DigitalOutputs::GetPinEnables()
{
    auto pins = static_cast<TurtlebotLibrary::DigitalOutputs *>(this->msg)->GetPinEnables();
    array<System::Boolean>^ managed_pins = gcnew array<System::Boolean>(pins.size());

    for (int i = 0; i < pins.size(); i++)
        managed_pins[i] = pins[i];

    return managed_pins;
}

System::Boolean DigitalOutputs::IsPinEnabled(System::Byte pin)
{
    return static_cast<TurtlebotLibrary::DigitalOutputs *>(this->msg)->IsPinEnabled(pin);
}

void DigitalOutputs::SetPinEnable(System::Byte pin, bool enable)
{
    static_cast<TurtlebotLibrary::DigitalOutputs *>(this->msg)->SetPinEnable(pin, enable);
}
