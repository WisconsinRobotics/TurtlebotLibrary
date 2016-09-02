#include "msg/Actuator.hpp"

using namespace TurtlebotLibrary;


Song::Song(int id, int numNotes) : TurtlebotMessage(TurtlebotCommandCode::Song)
{
    this->id = id;
    this->length = numNotes;
}

Song::~Song()
{
}

void Song::AddNote(Note n, int octave)
{
    this->notes.push_back(static_cast<uint8_t>((octave * 6) + static_cast<uint8_t>(n.note)));
    this->durations.push_back(n.duration);
}

int Song::GetSongId()
{
    return this->id;
}

int Song::GetSongLength()
{
    return this->length;
}

/*  Serial sequence: [140] [Song Number] [Song Length]
 *  [Note Number 1] [Note Duration 1] [Note Number 2]
 *  [Note Duration 2], etc. 
 */
std::vector<uint8_t> Song::SerializePayload()
{
    int i;
    std::vector<uint8_t> payload;

    payload.push_back(static_cast<uint8_t>(this->id));
    payload.push_back(static_cast<uint8_t>(this->length));
    
    for(i = 0; i < this->length; i++) 
    {
        payload.push_back(static_cast<uint8_t>(this->notes[i]));
        payload.push_back(static_cast<uint8_t>(this->durations[i]));
    }

    return payload;
}