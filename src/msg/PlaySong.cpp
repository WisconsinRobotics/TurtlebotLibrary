#include "msg/Actuator.hpp"

using namespace TurtlebotLibrary;

PlaySong::PlaySong(int songNum) : TurtlebotMessage(TurtlebotCommandCode::PlaySong)
{
    this->songNum = songNum;
}

PlaySong::~PlaySong()
{
}

int PlaySong::GetSongNum()
{
    return this->songNum;
}

std::vector<uint8_t> PlaySong::SerializePayload()
{
    std::vector<uint8_t> payload = { static_cast<uint8_t>(this->songNum) };
    return payload;
}