#pragma once

#include "TurtlebotMessage.hpp"
#include <cstdint>
#include <vector>

namespace TurtlebotLibrary {

	class Script : public TurtlebotMessage
	{
	public:
		Script(uint8_t scriptLength);
		~Script();
		uint8_t GetScriptLength() const; // const is questionable
		void SetScriptLength(uint8_t scriptLength);
		void AddCommand(TurtlebotMessage *msg);
		std::vector<TurtlebotMessage*> GetCommandVector();

	protected:
		std::vector<uint8_t> SerializePayload();

	private:
		uint8_t scriptLength;
		std::vector<TurtlebotMessage*> commandVector; // should command vector be a pointer?? also relevant in script constructor
	};
}



