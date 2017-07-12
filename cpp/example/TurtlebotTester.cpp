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

    for (Note& n : on_wisconsin)
        n.duration *= EIGHTH_NOTES_PER_DURATION;
	std::cout << argv[1];
    Script *s1 = new Script();
	Script *s2 = new Script();
    Drive *driveStraight = new Drive(150, Drive::STRAIGHT);
    WaitDistance *wait1Meter = new WaitDistance(500);
    Drive *driveRight = new Drive(150, Drive::CLOCKWISE);
	Drive *driveLeft = new Drive(150, Drive::COUNTERCLOCKWISE);
	WaitAngle *waitLeftAngle = new WaitAngle(90);
	WaitAngle *waitRightAngle = new WaitAngle(-90);
	Drive *driveStop = new Drive(0, Drive::STRAIGHT);
    s1->AddCommand(driveStraight);
	s1->AddCommand(wait1Meter);
	s1->AddCommand(driveRight);
	s1->AddCommand(waitRightAngle);
	s1->AddCommand(driveStraight);
	s1->AddCommand(wait1Meter);
	s1->AddCommand(driveLeft);
	s1->AddCommand(waitLeftAngle);
	s1->AddCommand(driveStraight);
	s1->AddCommand(wait1Meter);
	s1->AddCommand(driveStop);
	cmder.SendTurtlebotMessage(s1);
//	cmder.SendTurtlebotMessage(s2);
	PlayScript *playScript = new PlayScript();
	cmder.SendTurtlebotMessage(playScript);

	return 0;
}