#include "Script.hpp"

using namespace TurtlebotLibrary;

Script::Script(uint8_t scriptLength) : TurtlebotMessage(TurtlebotCommandCode::Script)
{
	// should 
	this->scriptLength = scriptLength; 
}

Script::~Script()
{
}

uint8_t Script::GetScriptLength() const
{
	return this->scriptLength;
}

void Script::SetScriptLength(uint8_t scriptLength)
{
	this->scriptLength = scriptLength;
}

void Script::AddCommand(TurtlebotMessage *msg)
{
	commandVector.push_back(msg);
}

std::vector<TurtlebotMessage*> Script::GetCommandVector()
{
	return this->commandVector;
}

std::vector<uint8_t> Script::SerializePayload()
{
	std::vector<uint8_t> payload = { this->scriptLength };

	for (int i = 0; i < this->commandVector.size(); i++) {
		std::vector<uint8_t> currCommandPayload = this->commandVector[i]->Serialize();
		for (int j = 0; j < currCommandPayload.size(); j++) {
			payload.push_back(currCommandPayload[i]);
		}
	}

	return payload;
}