#include "msg/Actuator.hpp"

using namespace TurtlebotLibrary;

PlaySong::PlaySong(int songNum) : TurtlebotMessage(TurtlebotCommandCode::PlaySong)
{
    this->songNum = songNum;
}

PlaySong::~PlaySong()
{
}

int GetSongNum()
{
    return this->songNum;
}

std::vector<uint8_t> Song::SerializePayload()
{
    return static_cast<uint8_t>(this->songNum);
}