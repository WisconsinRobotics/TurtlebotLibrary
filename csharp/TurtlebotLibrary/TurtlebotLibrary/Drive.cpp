#include "Actuator.hpp"

using namespace TurtlebotLibrarySharp;

Drive::Drive(System::Int32  velocity, System::Int32  radius) : TurtlebotMessage()
{
    this->msg = new TurtlebotLibrary::Drive(velocity, radius);
}

Drive::~Drive()
{
}

System::Int32 Drive::GetVelocity()
{
    return static_cast<TurtlebotLibrary::Drive *>(this->msg)->GetVelocity();
}

void Drive::SetVelocity(System::Int32 vel)
{
    static_cast<TurtlebotLibrary::Drive *>(this->msg)->SetVelocity(vel);
}

System::Int32 Drive::GetRadius()
{
    return static_cast<TurtlebotLibrary::Drive *>(this->msg)->GetRadius();
}

void Drive::SetRadius(System::Int32 rad)
{
    static_cast<TurtlebotLibrary::Drive *>(this->msg)->SetRadius(rad);
}