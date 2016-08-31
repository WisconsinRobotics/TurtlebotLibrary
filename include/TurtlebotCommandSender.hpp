#pragma once

#include "Serial.hpp"
#include "TurtlebotMessage.hpp"
#include <thread>

namespace TurtlebotLibrary
{
    enum class DriveMode
    {
        Passive, Safe, Full
    };

    class TurtlebotCommandSender
    {
        public:
            TurtlebotCommandSender();
            ~TurtlebotCommandSender();
            bool Initialize(const char *port, DriveMode driveMode = DriveMode::Safe);
            void SetDriveMode(DriveMode driveMode);
            void SendTurtlebotMessage(TurtlebotMessage *msg);
            void RegisterCallback(const std::function<void(const uint8_t*, int)>& callback);

        private:
            DriveMode mode;
            SerialPort serialPort;
            bool initialized;
            bool stopReading;

            std::thread readThread;
            std::function<void(const uint8_t*, int)> receive_callback;

            void ReceiveMessage(void);
    };
}
