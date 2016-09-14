#include "Wait.hpp"

using namespace TurtlebotLibrarySharp;


WaitTime::WaitTime(System::Byte tenths) : TurtlebotMessage()
{
    this->msg = new TurtlebotLibrary::WaitTime(tenths);
}

WaitTime::~WaitTime()
{
}

System::Byte WaitTime::GetDelay() 
{
    return static_cast<TurtlebotLibrary::WaitTime *>(this->msg)->GetDelay();
}

void WaitTime::SetDelay(System::Byte time)
{
    static_cast<TurtlebotLibrary::WaitTime *>(this->msg)->SetDelay(time);
}

WaitDistance::WaitDistance(System::Int16 dist) : TurtlebotMessage()
{
    this->msg = new TurtlebotLibrary::WaitDistance(dist);
}

WaitDistance::~WaitDistance()
{
}

System::Int16 WaitDistance::GetDistance() 
{
    return static_cast<TurtlebotLibrary::WaitDistance *>(this->msg)->GetDistance();
}

void WaitDistance::SetDistance(System::Int16 dist)
{
    static_cast<TurtlebotLibrary::WaitDistance *>(this->msg)->SetDistance(dist);
}

WaitAngle::WaitAngle(System::Int16 ang) : TurtlebotMessage()
{
    this->msg = new TurtlebotLibrary::WaitTime(ang);
}

WaitAngle::~WaitAngle()
{
}

System::Int16 WaitAngle::GetAngle() 
{
    return static_cast<TurtlebotLibrary::WaitAngle *>(this->msg)->GetAngle();
}

void WaitAngle::SetAngle(System::Int16 ang)
{
    static_cast<TurtlebotLibrary::WaitAngle *>(this->msg)->SetAngle(ang);
}

WaitEvent::WaitEvent(Event e, System::Boolean inverse) : TurtlebotMessage()
{
    this->msg = new TurtlebotLibrary::WaitEvent((TurtlebotLibrary::Event) e, inverse);
}

WaitEvent::~WaitEvent()
{
}

Event WaitEvent::GetEvent() 
{
    return (Event) static_cast<TurtlebotLibrary::WaitEvent *>(this->msg)->GetEvent();
}

bool WaitEvent::IsInverted() 
{
    return static_cast<TurtlebotLibrary::WaitEvent *>(this->msg)->IsInverted();
}

void WaitEvent::SetEvent(Event e, bool inverse)
{
    static_cast<TurtlebotLibrary::WaitEvent *>(this->msg)->SetEvent((TurtlebotLibrary::Event) e, inverse);
}
