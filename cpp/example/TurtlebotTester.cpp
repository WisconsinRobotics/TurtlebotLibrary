#include "TurtlebotLibrary.hpp"
#include <iostream>

using namespace TurtlebotLibrary;

constexpr int EIGHTH_NOTES_PER_DURATION = 8;

std::vector<Note> on_wisconsin = {
    { Notes::D, 5, 2},
    GenerateRestNote(4),
    {Notes::Csharp, 5, 1},
    GenerateRestNote(1),
    {Notes::E, 5, 2},
};

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "usage: " << argv[0] << " <serial port>" << std::endl;
        return 1;
    }

    TurtlebotLibrary::TurtlebotCommandSender cmder;

    if (!cmder.Initialize(argv[1], TurtlebotLibrary::DriveMode::Safe))
    {
        std::cout << "Failed to initialize TurtlebotCommandSender!" << std::endl;
        return 1;
    }

	Drive *drive = new Drive(150, Drive::STRAIGHT);
	cmder.SendTurtlebotMessage(drive);
	return 0;
}