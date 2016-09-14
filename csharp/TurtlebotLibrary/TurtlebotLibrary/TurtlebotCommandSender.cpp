#include <cstring>
#include "TurtlebotCommandSender.hpp"
#include "Start.hpp"
#include "Mode.hpp"
#include <msclr\marshal_cppstd.h>

using namespace TurtlebotLibrarySharp;

constexpr int DEFAULT_BAUD_RATE = 57600;

TurtlebotCommandSender::TurtlebotCommandSender()
{
    initialized = false;
    stopReading = false;
    serialPort = new TurtlebotLibrary::SerialPort();
    this->readThread = gcnew Thread(gcnew ThreadStart(this, &TurtlebotCommandSender::ReceiveMessage));
}

TurtlebotCommandSender::~TurtlebotCommandSender()
{
    if (serialPort)
    { 
        serialPort->Close();
        delete serialPort;
    }

    initialized = false;
    stopReading = true;

    if (readThread->IsAlive)
        readThread->Join();
}

bool TurtlebotCommandSender::Initialize(System::String^ port, DriveMode driveMode)
{
    if (!port)
        return false;

    msclr::interop::marshal_context context;
    std::string converted_port = context.marshal_as<std::string>(port);

    this->serialPort->SetPortName(converted_port.c_str());
    this->serialPort->SetBaud(DEFAULT_BAUD_RATE);
    if (!this->serialPort->Open())
        return false;

    initialized = true;

    // must send the Start message on startup before Turtlebot can switch to a different mode
    if (driveMode != DriveMode::Passive)
    {
        this->SendTurtlebotMessage(gcnew Start());
    }
    this->SetDriveMode(driveMode);

    readThread->Start();
    return true;
}

void TurtlebotCommandSender::SetDriveMode(DriveMode driveMode)
{
    this->mode = driveMode;

    switch (this->mode)
    {
    case DriveMode::Passive:
        this->SendTurtlebotMessage(gcnew Start());
        break;
    case DriveMode::Safe:
        this->SendTurtlebotMessage(gcnew Safe());
        break;
    case DriveMode::Full:
        this->SendTurtlebotMessage(gcnew Full());
        break;
    }
}

void TurtlebotCommandSender::SendTurtlebotMessage(TurtlebotMessage^ msg)
{
    if (!initialized)
        return;

    auto data = msg->Serialize();
    System::Byte msg_size = data->Length;
    pin_ptr<uint8_t> buffer = &data[0];

    serialPort->WriteData(buffer, msg_size);

    // XXX: there is technically a race condition here
    // this is used to annotate incoming data from the turtlebot
    this->lastSent = msg->GetCommandCode();
}

void TurtlebotCommandSender::ReceiveMessage(void)
{
    uint8_t buffer[256];

    if (!this->initialized)
        return;

    while (!stopReading)
    {
        std::memset(buffer, 0, 256);
        int bytesRead = serialPort->ReadData(buffer, 256);

        if (bytesRead > 0)
        {
            array<System::Byte>^ data = gcnew array<System::Byte>(bytesRead);
            for (int i = 0; i < bytesRead; i++)
                data[i] = buffer[i];

            if (this->OnReadData)
                OnReadData(data, bytesRead, this->lastSent);
        }
    }
}
