#include "msg/Actuator.hpp"

using namespace TurtlebotLibrary;

constexpr int MAX_NOTES_PER_SONG = 16;

Song::Song(int id) : TurtlebotMessage(TurtlebotCommandCode::Song)
{
    this->id = id;
}

Song::~Song()
{
}

bool Song::AddNote(Note n)
{
    if (notes.size() >= MAX_NOTES_PER_SONG)
        return false;

    this->notes.push_back(n);
    return true;
}

bool Song::AddNote(Notes n, uint8_t octave, uint8_t duration)
{
    return this->AddNote({n, octave, duration});
}

int Song::GetSongId()
{
    return this->id;
}

int Song::GetSongLength()
{
    return this->notes.size();
}

/*  Serial sequence: [140] [Song Number] [Song Length]
 *  [Note Number 1] [Note Duration 1] [Note Number 2]
 *  [Note Duration 2], etc. 
 */
std::vector<uint8_t> Song::SerializePayload()
{
    std::vector<uint8_t> payload;
    uint8_t size;

    size = static_cast<uint8_t>(this->notes.size());

    payload.push_back(static_cast<uint8_t>(this->id));
    payload.push_back(size);
    
    for (Note& n : this->notes)
    {
        payload.push_back(static_cast<uint8_t>((n.octave * 6) + static_cast<uint8_t>(n.note)));
        payload.push_back(static_cast<uint8_t>(n.duration));
    }

    return payload;
}