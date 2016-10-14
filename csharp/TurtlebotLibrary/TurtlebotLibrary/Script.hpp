#pragma once

#include "TurtlebotMessage.hpp"

using System::Collections::Generic::List;

namespace TurtlebotLibrarySharp
{
	public ref class Script : TurtlebotMessage
	{
	public:
		Script();
		~Script();
		void AddCommand(TurtlebotMessage^ msg); // got rid of star because it gave red squigle, but I think its like java where object variable names are automatically pointers
		//List<TurtlebotMessage^> GetCommandVector(); no longer possible, and no longer really necessary
	};
}
