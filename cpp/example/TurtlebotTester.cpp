#include "TurtlebotLibrary.hpp"
#include <iostream>
#include <memory>
#include "msg/Script.hpp" // why is this necessay but nothing is needed for note???
#include "msg/PlayScript.hpp"


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
    WaitDistance *w1 = new WaitDistance(250);
    Drive *d2 = new Drive((int)100, (int)Drive::CLOCKWISE);
	WaitAngle *w2 = new WaitAngle((int)90);
	Drive *d3 = new Drive(0, Drive::STRAIGHT);
    s->AddCommand(d1);
	s->AddCommand(w1);
	s->AddCommand(d3);
//	s->AddCommand(w2);
//	s->AddCommand(d1);
//	s->AddCommand(w1);
//	s->AddCommand(d3);
	cmder.SendTurtlebotMessage(s);

	PlayScript *playScript = new PlayScript();
	cmder.SendTurtlebotMessage(playScript);

	return 0;
}