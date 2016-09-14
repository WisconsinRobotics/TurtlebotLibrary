#include "TurtlebotMessage.hpp"

using namespace TurtlebotLibrarySharp;

TurtlebotMessage::TurtlebotMessage()
{
}

TurtlebotMessage::~TurtlebotMessage()
{
    if (msg)
        delete msg;
}

TurtlebotLibrarySharp::TurtlebotCommandCode TurtlebotMessage::GetCommandCode()
{
    return (TurtlebotLibrarySharp::TurtlebotCommandCode)(msg->GetCommandCode());
}

array<System::Byte>^ TurtlebotMessage::Serialize()
{
    auto serialized_buffer = msg->Serialize();
    array<System::Byte>^ managed_buffer = gcnew array<System::Byte>(serialized_buffer.size());
    for (int i = 0; i < serialized_buffer.size(); i++)
        managed_buffer[i] = serialized_buffer[i];

    return managed_buffer;
}

System::Boolean TurtlebotMessage::Deserialize(array<System::Byte>^ buffer, System::Int32 length)
{
    pin_ptr<uint8_t> converted_buffer = &buffer[0];
    return msg->Deserialize(converted_buffer, static_cast<uint8_t>(length));
}

System::IntPtr TurtlebotMessage::GetRawPtr()
{
    return System::IntPtr(this->msg);
}