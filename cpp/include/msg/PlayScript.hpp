#pragma once

#include "TurtlebotMessage.hpp"
#include <bitset>

namespace TurtlebotLibrary
{

    class PlayScript : public TurtlebotMessage
    {
        public:
            PlayScript();
            ~PlayScript();
        protected:
            std::vector<uint8_t> SerializePayload();
    };
}