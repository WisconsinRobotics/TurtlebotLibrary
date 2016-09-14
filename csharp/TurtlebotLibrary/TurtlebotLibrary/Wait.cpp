#include "msg/Wait.hpp"

using namespace TurtlebotLibrary;


WaitTime::WaitTime(uint8_t tenths) : TurtlebotMessage(TurtlebotCommandCode::Wait_Time)
{
    this->delay = tenths;
}

WaitTime::~WaitTime()
{
}

uint8_t WaitTime::GetDelay() const
{
    return this->delay;
}

void WaitTime::SetDelay(uint8_t time)
{
    this->delay = time;
}

std::vector<uint8_t> WaitTime::SerializePayload()
{
    std::vector<uint8_t> payload = { this->delay };
    return payload;
}

WaitDistance::WaitDistance(int16_t dist) : TurtlebotMessage(TurtlebotCommandCode::Wait_Distance)
{
    this->distance = dist;
}

WaitDistance::~WaitDistance()
{
}

int16_t WaitDistance::GetDistance() const
{
    return this->distance;
}

void WaitDistance::SetDistance(int16_t dist)
{
    this->distance = dist;
}

std::vector<uint8_t> WaitDistance::SerializePayload()
{
    std::vector<uint8_t> payload;
    payload.push_back(static_cast<uint8_t>(this->distance >> 8));
    payload.push_back(static_cast<uint8_t>(this->distance & 0xFF));
    return payload;
}

WaitAngle::WaitAngle(int16_t ang) : TurtlebotMessage(TurtlebotCommandCode::Wait_Angle)
{
    this->angle = ang;
}

WaitAngle::~WaitAngle()
{
}

int16_t WaitAngle::GetAngle() const
{
    return this->angle;
}

void WaitAngle::SetAngle(int16_t ang)
{
    this->angle = ang;
}

std::vector<uint8_t> WaitAngle::SerializePayload()
{
    std::vector<uint8_t> payload;
    payload.push_back(static_cast<uint8_t>(this->angle >> 8));
    payload.push_back(static_cast<uint8_t>(this->angle & 0xFF));
    return payload;
}

WaitEvent::WaitEvent(Event e, bool inverse) : TurtlebotMessage(TurtlebotCommandCode::Wait_Event)
{
    this->wait_event = e;
    this->inverted = inverse;
}

WaitEvent::~WaitEvent()
{
}

Event WaitEvent::GetEvent() const
{
    return this->wait_event;
}

bool WaitEvent::IsInverted() const
{
    return this->inverted;
}

void WaitEvent::SetEvent(Event e, bool inverse)
{
    this->wait_event = e;
    this->inverted = inverse;
}

std::vector<uint8_t> WaitEvent::SerializePayload()
{
    std::vector<uint8_t> payload;

    if (this->inverted)
        payload.push_back(~static_cast<uint8_t>(this->wait_event) + 1);
    else
        payload.push_back(static_cast<uint8_t>(this->wait_event));

    return payload;
}