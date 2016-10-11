#include "msg/PlayScript.hpp"

using namespace TurtlebotLibrary;

PlayScript::PlayScript() : TurtlebotMessage(TurtlebotCommandCode::PlayScript)
{
}

PlayScript::~PlayScript()
{
}

std::vector<uint8_t> PlayScript::SerializePayload()
{
	std::vector<uint8_t> payload;
    return payload; // payload is simply the CommandCode to play the next script, they are stored in a queue
}