#pragma once

#include "TurtlebotMessage.hpp"


namespace TurtlebotLibrary
{
    class Full : public TurtlebotMessage
    {
        public:
            Full() : TurtlebotMessage(TurtlebotCommandCode::Full) { }
            ~Full() { }
    };

    class Safe : public TurtlebotMessage
    {
        public:
            Safe() : TurtlebotMessage(TurtlebotCommandCode::Safe) { }
            ~Safe() { }
    };

}