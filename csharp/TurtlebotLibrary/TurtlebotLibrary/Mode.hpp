#pragma once

#include "TurtlebotMessage.hpp"

namespace TurtlebotLibrarySharp
{
    public ref class Full : public TurtlebotMessage
    {
        public:
            Full() : TurtlebotMessage() 
            {
                this->msg = new TurtlebotLibrary::Full();
            }

            ~Full()
            { 
            }
    };

    public ref class Safe : public TurtlebotMessage
    {
        public:
            Safe() : TurtlebotMessage() 
            {
                this->msg = new TurtlebotLibrary::Safe();
            }

            ~Safe()
            { 
            }
    };

}