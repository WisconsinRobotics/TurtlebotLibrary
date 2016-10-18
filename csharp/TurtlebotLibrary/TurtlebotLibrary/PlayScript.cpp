#include "PlayScript.hpp"

using namespace TurtlebotLibrarySharp;

PlayScript::PlayScript() : TurtlebotMessage()
{
	this->msg = new TurtlebotLibrary::PlayScript();
}

PlayScript::~PlayScript()
{
    if (this->msg)
        delete this->msg;
}

