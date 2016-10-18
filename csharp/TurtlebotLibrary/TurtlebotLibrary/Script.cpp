#include "Script.hpp"

using namespace TurtlebotLibrarySharp;

Script::Script() : TurtlebotMessage()
{
	this->msg = new TurtlebotLibrary::Script();
}

Script::~Script()
{
	if (this->msg)
		delete this->msg;
}

void Script::AddCommand(TurtlebotMessage^ msg)
{
	static_cast<TurtlebotLibrary::Script *>(this->msg)->AddCommand((TurtlebotLibrary::TurtlebotMessage *)(msg->GetRawPtr().ToPointer()));
}

//List<TurtlebotMessage^> Script::GetCommandVector() no longer being implemented
