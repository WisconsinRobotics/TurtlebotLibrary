#include "Note.hpp"

using namespace TurtlebotLibrary;


Note::Note(Notes note, int duration)
{
    this->note = note;
    this->duration = duration;
}

Note::~Note()
{
}

