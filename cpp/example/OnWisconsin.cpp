#include "TurtlebotLibrary.hpp"
#include <iostream>
#include <memory>
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace TurtlebotLibrary;

constexpr int EIGHTH_NOTE_PER_DURATION = 8;

bool song_playing = true;

std::map<std::string, Notes> note_map = {
    { "A", Notes::A },
    { "AS", Notes::Asharp },
    { "B", Notes::B },
    { "C", Notes::C },
    { "CS", Notes::Csharp },
    { "D", Notes::D },
    { "DS", Notes::Dsharp },
    { "E", Notes::E },
    { "F", Notes::F },
    { "FS", Notes::Fsharp },
    { "G", Notes::G },
    { "GS", Notes::Gsharp },
};

std::vector<Note> ReadNotesFromFile(std::string filename)
{
    std::ifstream file(filename);
    if (file.fail())
        return std::vector<Note>();

    std::vector<Note> notes;
    std::string line;
    while (std::getline(file, line))
    {
        std::stringstream linestream(line);
        std::string raw_note;
        int duration;

        std::getline(linestream, raw_note, '\t');
        linestream >> duration;

        if (raw_note == "REST")
        {
            notes.push_back(GenerateRestNote(duration * EIGHTH_NOTE_PER_DURATION));
            continue;
        }

        Notes n = note_map[raw_note.substr(0, raw_note.size() - 1)];
        int octave = std::atoi(raw_note.substr(raw_note.size() - 1, 1).c_str());

        notes.push_back({ n, static_cast<uint8_t>(octave), static_cast<uint8_t>(duration * EIGHTH_NOTE_PER_DURATION) });
    }

    return notes;
}

void PlaySongMonitor(const uint8_t *buffer, int length, TurtlebotCommandCode opcode)
{
    if (opcode != TurtlebotCommandCode::Sensor)
        return;

    song_playing = buffer[0] == 1;
}

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        std::cout << "usage: " << argv[0] << " <serial port> <song file>" << std::endl;
        return 1;
    }

    TurtlebotLibrary::TurtlebotCommandSender cmder;
    if (!cmder.Initialize(argv[1], TurtlebotLibrary::DriveMode::Safe))
    {
        std::cout << "Failed to initialize TurtlebotCommandSender!" << std::endl;
        return 1;
    }

    cmder.RegisterCallback(&PlaySongMonitor);

    // load songs into turtlebot
    std::vector<Note> notes = ReadNotesFromFile(argv[2]);
    std::vector<Song *> songs;

    if (notes.size() > 16 * 16 || notes.size() == 0)
    {
        std::cout << "Too many notes or invalid note file provided!" << std::endl;
        return 1;
    }

    Song *s = new Song(0);
    for (int i = 0; i < notes.size(); i++)
    {
        if (i / 16 != s->GetSongId())
        {
            songs.push_back(s);
            s = new Song(i / 16);
        }
        s->AddNote(notes[i]);
    }

    // add last song if there's anything left over
    if (s->GetSongLength() != 0)
        songs.push_back(s);
    
    for (int i = 0; i < songs.size(); i++)
    {
        cmder.SendTurtlebotMessage(songs[i]);
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    // play the song
    for (int i = 0; i < songs.size(); i++)
    {
        std::unique_ptr<PlaySong> playSong(new PlaySong(i));
        cmder.SendTurtlebotMessage(playSong.get());
        song_playing = true;

        while (song_playing)
        {
            std::unique_ptr<Sensor> sensor(new Sensor(SensorPacketID::SongPlaying));
            cmder.SendTurtlebotMessage(sensor.get());

            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }
    }

    for (int i = 0; i < songs.size(); i++)
        delete songs[i];

    return 0;
}