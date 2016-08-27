#pragma once

#include "TurtlebotMessage.hpp"


namespace TurtlebotLibrary
{
    class Start : public TurtlebotMessage
    {
        public:
            Start() : TurtlebotMessage(TurtlebotCommandCode::Start) { }
            ~Start() { }
    };
}