#include "Actuator.hpp"

using namespace TurtlebotLibrarySharp;

Song::Song(System::Int32 id) : TurtlebotMessage()
{
    this->msg = new TurtlebotLibrary::Song(id);
}

Song::~Song()
{
}

System::Boolean Song::AddNote(Note^ n)
{
    TurtlebotLibrary::Note native_note;
    native_note.note = (TurtlebotLibrary::Notes)(n->note);
    native_note.octave = n->octave;
    native_note.duration = n->duration;

    return static_cast<TurtlebotLibrary::Song *>(this->msg)->AddNote(native_note);
}

System::Boolean Song::AddNote(Notes n, System::Byte octave, System::Byte duration)
{
    Note^ note = gcnew Note();
    note->note = n;
    note->octave = octave;
    note->duration = duration;

    return this->AddNote(note);
}

System::Int32 Song::GetSongId()
{
    return static_cast<TurtlebotLibrary::Song *>(this->msg)->GetSongId();
}

System::Int32 Song::GetSongLength()
{
    return static_cast<TurtlebotLibrary::Song *>(this->msg)->GetSongLength();
}
