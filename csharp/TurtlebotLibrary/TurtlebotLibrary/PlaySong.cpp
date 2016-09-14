#include "Actuator.hpp"

using namespace TurtlebotLibrarySharp;

PlaySong::PlaySong(System::Int32 songNum) : TurtlebotMessage()
{
    this->msg = new TurtlebotLibrary::PlaySong(songNum);
}

PlaySong::~PlaySong()
{
}

System::Int32 PlaySong::GetSongNum()
{
    return static_cast<TurtlebotLibrary::PlaySong *>(this->msg)->GetSongNum();
}
