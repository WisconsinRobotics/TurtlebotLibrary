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

uint8_t Script::getScriptLength() const
{
	return this->scriptLength;
}

void Script::setScriptLength(uint8_t scriptLength)
{
	this->scriptLength = scriptLength;
}

void Script::addCommand(TurtlebotMessage *msg)
{
	commandVector.push_back(msg);
}

std::vector<TurtlebotMessage*> Script::getCommandVector()
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