#pragma once

#include "TurtlebotMessage.hpp"

namespace TurtlebotLibrarySharp
{
    public enum class DriveMode : System::Byte
    {
        Passive, Safe, Full
    };

    public ref class TurtlebotCommandSender
    {
        public:
            typedef void (*ReadDataCallback)(array<System::Byte>^ data, System::Byte length, TurtlebotCommandCode lastPacketSentOpcode);
            TurtlebotCommandSender();
            ~TurtlebotCommandSender();
            bool Initialize(System::String^ port, DriveMode driveMode);
            void SetDriveMode(DriveMode driveMode);
            void SendTurtlebotMessage(TurtlebotMessage^ msg);
            void RegisterCallback(ReadDataCallback callback);

        private:
            TurtlebotLibrary::TurtlebotCommandSender *commandSender;
    };
}
