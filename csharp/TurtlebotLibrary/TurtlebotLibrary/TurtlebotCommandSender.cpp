#include "TurtlebotCommandSender.hpp"
#include <string>
#include <msclr\marshal_cppstd.h>

using namespace TurtlebotLibrarySharp;

TurtlebotCommandSender::TurtlebotCommandSender()
{
    this->commandSender = new TurtlebotLibrary::TurtlebotCommandSender();
}

TurtlebotCommandSender::~TurtlebotCommandSender()
{
    delete this->commandSender;
}

bool TurtlebotCommandSender::Initialize(System::String^ port, DriveMode driveMode)
{
    msclr::interop::marshal_context context;
    std::string converted_port = context.marshal_as<std::string>(port);

    return this->commandSender->Initialize(converted_port.c_str(), (TurtlebotLibrary::DriveMode) driveMode);
}

void TurtlebotCommandSender::SetDriveMode(DriveMode driveMode)
{
    this->commandSender->SetDriveMode((TurtlebotLibrary::DriveMode) driveMode);
}

void TurtlebotCommandSender::SendTurtlebotMessage(TurtlebotMessage^ msg)
{
    this->commandSender->SendTurtlebotMessage((TurtlebotLibrary::TurtlebotMessage *)msg->GetRawPtr().ToPointer());
}

void TurtlebotCommandSender::RegisterCallback(ReadDataCallback callback)
{
    auto delegate_ptr = System::Runtime::InteropServices::Marshal::GetFunctionPointerForDelegate(callback);
    this->commandSender->RegisterCallback((std::function<void(const uint8_t *, int, TurtlebotLibrary::TurtlebotCommandCode)>)(delegate_ptr.ToPointer()));
}
