#include <cstring>
#include "TurtlebotCommandSender.hpp"
#include "msg/Mode.hpp"
#include "msg/Start.hpp"
#include "msg/Actuator.hpp"

constexpr int DEFAULT_BAUD_RATE = 57600;
constexpr int READ_BUFFER_SIZE = 256;

using namespace TurtlebotLibrary;

TurtlebotCommandSender::TurtlebotCommandSender()
{
    initialized = false;
    stopReading = false;
}

TurtlebotCommandSender::~TurtlebotCommandSender()
{
    serialPort.Close();
    initialized = false;
    stopReading = true;
    readThread.join();
}

bool TurtlebotCommandSender::Initialize(const char *port, DriveMode driveMode)
{
    if (!port)
        return false;

    serialPort.SetPortName(port);
    serialPort.SetBaud(DEFAULT_BAUD_RATE);

    if (!serialPort.Open())
        return false;

	initialized = true;
    
    // must send the Start message on startup before Turtlebot can switch to a different mode
    if (driveMode != DriveMode::Passive)
    {
        Start start;
        this->SendTurtlebotMessage(&start);
    }
    this->SetDriveMode(driveMode);

    readThread = std::thread(&TurtlebotCommandSender::ReceiveMessage, this);
	return true;
}

void TurtlebotCommandSender::SetDriveMode(DriveMode driveMode)
{
    Start start;
    Safe safe;
    Full full;

    this->mode = driveMode;

    switch (this->mode)
    {
        case DriveMode::Passive:
            this->SendTurtlebotMessage(&start);
            break;
        case DriveMode::Safe:
            this->SendTurtlebotMessage(&safe);
            break;
        case DriveMode::Full:
            this->SendTurtlebotMessage(&full);
            break;
    }
}

void TurtlebotCommandSender::SendTurtlebotMessage(TurtlebotMessage *msg)
{
    if (!initialized)
        return;

    std::vector<uint8_t> data = msg->Serialize();
    const uint8_t *buffer = data.data();

    serialPort.WriteData(buffer, data.size());

    // XXX: there is technically a race condition here
    // this is used to annotate incoming data from the turtlebot
    this->lastSent = msg->GetCommandCode();
}

void TurtlebotCommandSender::RegisterCallback(const std::function<void(const uint8_t *, int, TurtlebotCommandCode)>& callback)
{
    this->receive_callback = callback;
}

void TurtlebotCommandSender::ReceiveMessage(void)
{
    uint8_t buffer[READ_BUFFER_SIZE];

    if (!this->initialized)
        return;

    while (!stopReading)
    {
        std::memset(buffer, 0, READ_BUFFER_SIZE);
        int bytesRead = serialPort.ReadData(buffer, READ_BUFFER_SIZE);

        if (this->receive_callback && bytesRead > 0)
            this->receive_callback(buffer, bytesRead, this->lastSent);
    }
}
