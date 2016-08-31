#include "TurtlebotLibrary.hpp"
#include <iostream>


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

    /* test code here */
	TurtlebotLibrary::Drive *driver = new TurtlebotLibrary::Drive(175, TurtlebotLibrary::Drive::STRAIGHT);

	cmder.SendTurtlebotMessage(driver);

	std::cin.ignore();

	driver->SetRadius(TurtlebotLibrary::Drive::CLOCKWISE);
	cmder.SendTurtlebotMessage(driver);

	std::cin.ignore();

	driver->SetRadius(TurtlebotLibrary::Drive::COUNTERCLOCKWISE);
	cmder.SendTurtlebotMessage(driver);

	std::cin.ignore();

	driver->SetVelocity(0);
	cmder.SendTurtlebotMessage(driver);


	delete driver;
    return 0;
}