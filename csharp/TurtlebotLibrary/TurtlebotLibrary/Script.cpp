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

List<TurtlebotMessage^> Script::GetCommandVector()
{
    std::vector<TurtlebotLibrary::TurtlebotMessage *> x = static_cast<TurtlebotLibrary::Script *>(this->msg)->GetCommandVector();
	List<TurtlebotMessage^>^ toRet = gcnew List<TurtlebotMessage^>();
	for (int i = 0; i < x.size(); i++) {
		toRet.Add(x[i]);
	}
	return toRet;
}  // std::vector<TurtlebotMessage^>.GetRawPtr().ToPointer()