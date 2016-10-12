#pragma once

#include "TurtlebotMessage.hpp"
#include <cstdint>
#include <vector>

namespace TurtlebotLibrary {

	class Script : public TurtlebotMessage
	{
	public:
		Script();
		~Script();
		void AddCommand(TurtlebotMessage *msg);
		std::vector<TurtlebotMessage*> GetCommandVector();

	protected:
		std::vector<uint8_t> SerializePayload();

	private:
		std::vector<TurtlebotMessage*> commandVector; // should command vector be a pointer?? also relevant in script constructor
	};
}



