#include <cstring>
#include "TurtlebotCommandSender.hpp"
#include "msg/Mode.hpp"
#include "msg/Start.hpp"
#include "msg/Actuator.hpp"

constexpr int DEFAULT_BAUD_RATE = 115200;
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

    serialPort = SerialPort(port, DEFAULT_BAUD_RATE);
    if (!serialPort.Open())
        return false;

    this->SetDriveMode(driveMode);

    readThread = std::thread(&TurtlebotCommandSender::ReceiveMessage, this);

    initialized = true;
    return true;
}

void TurtlebotCommandSender::SetDriveMode(DriveMode driveMode)
{
    this->mode = driveMode;
    
    switch (this->mode)
    {
        case DriveMode::Passive:
            this->SendTurtlebotMessage(Start());
            break;
        case DriveMode::Safe:
            this->SendTurtlebotMessage(Safe());
            break;
        case DriveMode::Full:
            this->SendTurtlebotMessage(Full());
            break;
    }
}

void TurtlebotCommandSender::SendTurtlebotMessage(TurtlebotMessage msg)
{
    if (!initialized)
        return;

    std::vector<uint8_t> data = msg.Serialize();
    const uint8_t *buffer = data.data();

    serialPort.WriteData(buffer, data.size());
}

void TurtlebotCommandSender::RegisterCallback(const std::function<void(const uint8_t *, int)>& callback)
{
    this->receive_callback = callback;
}

void TurtlebotCommandSender::ReceiveMessage(void)
{
    uint8_t buffer[READ_BUFFER_SIZE];

    if (!this->initialized)
        return;

    do
    {
        std::memset(buffer, 0, READ_BUFFER_SIZE);
        int bytesRead = serialPort.ReadData(buffer, READ_BUFFER_SIZE);

        if (this->receive_callback && bytesRead > 0)
            this->receive_callback(buffer, bytesRead);

    } while (!stopReading);
}
