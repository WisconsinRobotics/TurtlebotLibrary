#pragma once

#include "TurtlebotMessage.hpp"

using namespace System::Threading;

namespace TurtlebotLibrarySharp
{
    public enum class DriveMode
    {
        Passive, Safe, Full
    };

    public ref class TurtlebotCommandSender
    {
    public:
        

        TurtlebotCommandSender();
        ~TurtlebotCommandSender();
        bool Initialize(System::String^ port, DriveMode driveMode);
        void SetDriveMode(DriveMode driveMode);
        void SendTurtlebotMessage(TurtlebotMessage^ msg);

        delegate void ReadCallback(array<System::Byte>^ buffer, System::Int32 length, TurtlebotCommandCode lastPacketOpcode);
        ReadCallback^ OnReadData = nullptr;

    private:
        DriveMode mode;
        TurtlebotLibrary::SerialPort *serialPort = nullptr;
        bool initialized;
        bool stopReading;
        TurtlebotCommandCode lastSent;
        Thread^ readThread;

        void ReceiveMessage(void);
    };
}
