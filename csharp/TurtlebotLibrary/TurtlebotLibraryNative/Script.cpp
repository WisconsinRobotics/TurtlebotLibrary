#include "Script.hpp"

using namespace TurtlebotLibrary;

Script::Script() : TurtlebotMessage(TurtlebotCommandCode::Script)
{
}

Script::~Script()
{
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
	std::vector<uint8_t> payload = { 0 };

	for (int i = 0; i < this->commandVector.size(); i++) {
		std::vector<uint8_t> currCommandPayload = this->commandVector[i]->Serialize();
		for (int j = 0; j < currCommandPayload.size(); j++) {
			payload.push_back(currCommandPayload[j]);
		}
	}

	return payload;
}