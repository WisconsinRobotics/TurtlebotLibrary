#pragma once

#include "TurtlebotMessage.hpp"


namespace TurtlebotLibrarySharp
{
    public ref class Start : public TurtlebotMessage
    {
        public:
            Start() : TurtlebotMessage() 
            {
                this->msg = new TurtlebotLibrary::Start();
            }

            ~Start()
            { 
            }
    };
}