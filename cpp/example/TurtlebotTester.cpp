#include "TurtlebotLibrary.hpp"
#include <iostream>
#include <memory>
#include "msg/Script.hpp" // why is this necessay but nothing is needed for note???


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

//    for (Note& n : on_wisconsin)
//        n.duration *= EIGHTH_NOTES_PER_DURATION;
	//std::cout << argv[1];
    Script *s = new Script(3);
    Drive *d1 = new Drive((int)100, (int)32768);
    WaitDistance *w = new WaitDistance(5000);
    Drive *d2 = new Drive((int)0, (int)32768);
    s->AddCommand(d1);
	s->AddCommand(w);
	s->AddCommand(d2);
	cmder.SendTurtlebotMessage(d1);

	while (1){}

    return 0;
}