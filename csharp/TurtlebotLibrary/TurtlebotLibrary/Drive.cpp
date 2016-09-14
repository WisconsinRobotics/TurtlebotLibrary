#include "Actuator.hpp"

using namespace TurtlebotLibrarySharp;

Drive::Drive(int velocity, int radius) : TurtlebotMessage(TurtlebotCommandCode::Drive)
{
}

Drive::~Drive()
{
}

int Drive::GetVelocity()
{
}

void Drive::SetVelocity(int vel)
{
}

int Drive::GetRadius()
{
}

void Drive::SetRadius(int rad)
{

}