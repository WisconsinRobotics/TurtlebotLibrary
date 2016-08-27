#include "msg/Actuator.hpp"

using namespace TurtlebotLibrary;


static inline int clamp(int val, int min, int max)
{
    if (val < min)
        return min;
    else if (val > max)
        return max;
    else
        return val;
}


Drive::Drive(int velocity, int radius) : TurtlebotMessage(TurtlebotCommandCode::Drive)
{
    SetVelocity(velocity);
    SetRadius(radius);
}

Drive::~Drive()
{
}

int Drive::GetVelocity() const
{
    return this->velocity;
}

void Drive::SetVelocity(int vel)
{
    this->velocity = clamp(vel, -MAX_ABS_VELOCITY, MAX_ABS_VELOCITY);
}

int Drive::GetRadius() const
{
    return this->radius;
}

void Drive::SetRadius(int rad)
{
    switch (rad)
    {
        case STRAIGHT:
        case CLOCKWISE:
        case COUNTERCLOCKWISE:
            this->radius = rad;
            return;
        default:
            this->radius = clamp(rad, -MAX_ABS_RADIUS, MAX_ABS_RADIUS);
            return;
    }
}

std::vector<uint8_t> Drive::SerializePayload()
{
    std::vector<uint8_t> payload;

    payload.push_back(static_cast<uint8_t>(this->velocity >> 8));
    payload.push_back(static_cast<uint8_t>(this->velocity & 0xFF));
    payload.push_back(static_cast<uint8_t>(this->radius >> 8));
    payload.push_back(static_cast<uint8_t>(this->radius & 0xFF));

    return payload;
}
